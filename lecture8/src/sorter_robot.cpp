/**
 * @file sorter_robot.cpp
 * @brief Implementation file for the SorterRobot class
 * @author zeidk (zeidk@umd.edu)
 * @version 2.0
 * @date 2025-07-27
 */

#include "sorter_robot.hpp"
#include <algorithm>
#include <iomanip>
#include <iostream>
#include <random>
#include <sstream>
#include <unordered_map>

namespace robotics {

// ==========================================
// CONSTRUCTOR
// ==========================================

SorterRobot::SorterRobot(std::string_view robot_id, double accuracy)
    : Robot(robot_id, "SorterBot-T3"), sort_accuracy_(accuracy),
      current_zone_("Zone_A") {

  if (accuracy < 0 || accuracy > 100) {
    throw std::invalid_argument("Sort accuracy must be between 0 and 100");
  }

  std::cout << "SorterRobot initialized with accuracy: " << std::fixed
            << std::setprecision(1) << accuracy << "%, starting in "
            << current_zone_ << '\n';
}

// ==========================================
// SORTING OPERATIONS
// ==========================================

std::string SorterRobot::categorize_item(std::string_view item_id) {
  if (!validate_operation()) {
    log_activity("Cannot categorize item - robot not operational");
    return "";
  }

  if (item_id.empty()) {
    log_activity("Cannot categorize empty item ID");
    return "";
  }

  // Analyze item properties first
  std::string analysis = analyze_item_properties(item_id);

  // Simple categorization based on item ID patterns
  std::string category;
  std::string item_str(item_id);

  if (item_str.find("ELEC") != std::string::npos ||
      item_str.find("12345") != std::string::npos) {
    category = "Electronics";
  } else if (item_str.find("BOOK") != std::string::npos ||
             item_str.find("67890") != std::string::npos) {
    category = "Books";
  } else if (item_str.find("CLOTH") != std::string::npos ||
             item_str.find("ABC") != std::string::npos) {
    category = "Clothing";
  } else if (item_str.find("FOOD") != std::string::npos ||
             item_str.find("XYZ") != std::string::npos) {
    category = "Food";
  } else {
    category = "General";
  }

  // Simulate sorting accuracy
  static std::random_device rd;
  static std::mt19937 gen(rd());
  std::uniform_real_distribution<> dis(0.0, 100.0);

  if (dis(gen) > sort_accuracy_) {
    category = "Miscategorized"; // Simulate sorting error
    log_activity(
        "WARNING: Item may have been miscategorized due to sorting error");
  }

  std::cout << "Categorized item " << item_id << " as: " << category << '\n';

  return category;
}

void SorterRobot::apply_sorting_rules(std::string_view item_id) {
  if (!validate_operation()) {
    log_activity("Cannot apply sorting rules - robot not operational");
    return;
  }

  std::string category = categorize_item(item_id);

  // Define zone mapping for categories
  static const std::unordered_map<std::string, std::string> zone_map = {
      {"Electronics", "Zone_E"}, {"Books", "Zone_B"},
      {"Clothing", "Zone_C"},    {"Food", "Zone_F"},
      {"General", "Zone_G"},     {"Miscategorized", "Zone_M"}};

  auto it = zone_map.find(category);
  std::string target_zone = (it != zone_map.end()) ? it->second : "Zone_G";

  std::ostringstream oss;
  oss << "Applied sorting rule: " << item_id << " (" << category << ") -> "
      << target_zone;
  log_activity(oss.str());

  // Move to appropriate zone if not already there
  if (current_zone_ != target_zone) {
    move_to_zone(target_zone);
  }
}

void SorterRobot::move_to_zone(std::string_view zone) {
  if (!validate_operation()) {
    log_activity("Cannot move to zone - robot not operational");
    return;
  }

  if (zone == current_zone_) {
    log_activity("Already in target zone " + std::string(zone));
    return;
  }

  std::string previous_zone = current_zone_;
  current_zone_ = zone;

  std::cout << "Moved from " << previous_zone << " to " << current_zone_
            << '\n';

  // Call base class move method
  move();
}

void SorterRobot::update_sort_statistics() {
  static size_t total_items_sorted = 0;
  static size_t successful_sorts = 0;

  total_items_sorted++;

  // Simulate successful sort based on accuracy
  static std::random_device rd;
  static std::mt19937 gen(rd());
  std::uniform_real_distribution<> dis(0.0, 100.0);

  if (dis(gen) <= sort_accuracy_) {
    successful_sorts++;
  }

  double current_success_rate =
      (total_items_sorted > 0)
          ? (static_cast<double>(successful_sorts) / total_items_sorted * 100.0)
          : 0.0;

  std::cout << "Sort statistics updated: " << successful_sorts << "/"
      << total_items_sorted << " successful (" << std::fixed
      << std::setprecision(1) << current_success_rate << "%)\n";
}

void SorterRobot::add_to_queue(std::string_view item_id) {
  if (item_id.empty()) {
    log_activity("Cannot add empty item ID to queue");
    return;
  }

  processing_queue_.push(std::string(item_id));

  std::cout << "Added item " << item_id
      << " to processing queue (Queue size: " << processing_queue_.size()
      << ")\n";
}

std::string SorterRobot::process_next_item() {
  if (processing_queue_.empty()) {
    log_activity("Processing queue is empty");
    return "";
  }

  std::string item_id = processing_queue_.front();
  processing_queue_.pop();

  // std::cout << "Processing item " << item_id
  //     << " (Remaining in queue: " << processing_queue_.size() << ")\n";
 

  // Apply sorting rules to the item
  apply_sorting_rules(item_id);

  // Update statistics
  update_sort_statistics();

  return item_id;
}

void SorterRobot::clear_queue() {
  size_t cleared_count = processing_queue_.size();

  // Clear the queue
  std::queue<std::string> empty_queue;
  processing_queue_.swap(empty_queue);

  if (cleared_count > 0) {
    log_activity("Cleared processing queue (" + std::to_string(cleared_count) +
                 " items)");
  }
}

// ==========================================
// POLYMORPHIC METHODS (OVERRIDE)
// ==========================================

void SorterRobot::execute_task() {
  if (!validate_operation()) {
    log_activity("Cannot execute task - robot not operational");
    return;
  }

  log_activity("*** SorterRobot executing sorting and organization task");

  // Add sample items to queue if empty
  if (processing_queue_.empty()) {
    std::vector<std::string> sample_items = {"ITEM_ELEC001", "ITEM_BOOK002",
                                             "ITEM_CLOTH003", "ITEM_FOOD004",
                                             "ITEM_GEN005"};

    for (const auto &item : sample_items) {
      add_to_queue(item);
    }
  }

  // Process all items in queue
  size_t processed_count = 0;
  while (!processing_queue_.empty() &&
         processed_count < 10) { // Limit to prevent infinite loop
    std::string processed_item = process_next_item();
    if (!processed_item.empty()) {
      processed_count++;
    }
  }

  log_activity("Sorting task completed successfully. Processed " +
               std::to_string(processed_count) + " items");
}

std::string SorterRobot::get_task_description() const {
  std::ostringstream oss;
  oss << "Sort and organize items (Accuracy: " << std::fixed
      << std::setprecision(1) << sort_accuracy_
      << "%, Current Zone: " << current_zone_
      << ", Queue: " << processing_queue_.size() << " items)";

  return oss.str();
}

// ==========================================
// PRIVATE HELPER METHODS
// ==========================================

std::string SorterRobot::analyze_item_properties(std::string_view item_id) {
  // Simulate item property analysis
  std::ostringstream analysis;

  analysis << "Analysis of " << item_id << ": ";

  // Simple analysis based on item ID
  std::string item_str(item_id);
  if (item_str.length() > 10) {
    analysis << "Complex item with detailed identifier. ";
  } else {
    analysis << "Standard item with basic identifier. ";
  }

  // Simulate weight/size analysis
  static std::random_device rd;
  static std::mt19937 gen(rd());
  std::uniform_real_distribution<> weight_dis(0.1, 10.0);

  double estimated_weight = weight_dis(gen);
  analysis << "Estimated weight: " << std::fixed << std::setprecision(1)
           << estimated_weight << "kg. ";

  if (estimated_weight > 5.0) {
    analysis << "Heavy item - requires careful handling.";
  } else {
    analysis << "Standard weight item.";
  }

  std::string result = analysis.str();
  log_activity("Item analysis: " + result);

  return result;
}

} // namespace robotics