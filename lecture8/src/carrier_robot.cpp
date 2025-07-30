/**
 * @file carrier_robot.cpp
 * @brief Implementation file for the CarrierRobot class
 * @author zeidk (zeidk@umd.edu)
 * @version 2.0
 * @date 2025-07-27
 */

#include "carrier_robot.hpp"
#include <algorithm>
#include <iomanip>
#include <iostream>

namespace robotics {

// ==========================================
// CONSTRUCTOR
// ==========================================

CarrierRobot::CarrierRobot(std::string_view robot_id, double capacity)
    : Robot(robot_id, "CarrierBot-X1"), load_capacity_(capacity) {

  if (capacity <= 0) {
    throw std::invalid_argument("Load capacity must be positive");
  }
  std::cout << "CarrierRobot initialized with capacity: " << std::fixed
            << std::setprecision(1) << capacity << " kg\n";
}

// ==========================================
// CARGO MANAGEMENT
// ==========================================

bool CarrierRobot::load_item(std::string_view item_id, double weight) {
  if (!validate_operation()) {
    log_activity("Cannot load item - robot not operational");
    return false;
  }

  if (weight <= 0) {
    log_activity("Cannot load item with non-positive weight");
    return false;
  }

  if (current_load_ + weight > load_capacity_) {
    std::cout << "Cannot load " << item_id << ": would exceed capacity ("
        << std::fixed << std::setprecision(1) << current_load_ + weight << " > "
        << load_capacity_ << " kg)\n";

    return false;
  }

  cargo_manifest_.emplace_back(item_id);
  current_load_ += weight;

  std::cout << "Loaded item " << item_id << " (+" << std::fixed
      << std::setprecision(1) << weight << "kg). Total load: " << current_load_
      << "/" << load_capacity_ << " kg (" << std::setprecision(0)
      << get_load_percentage() << "%)\n";

  // Optimize load distribution if near capacity
  if (get_load_percentage() > 80.0) {
    optimize_load_distribution();
  }

  return true;
}

bool CarrierRobot::unload_item(std::string_view item_id) {
  if (!validate_operation()) {
    log_activity("Cannot unload item - robot not operational");
    return false;
  }

  auto it = std::find(cargo_manifest_.begin(), cargo_manifest_.end(), item_id);
  if (it == cargo_manifest_.end()) {
    log_activity("Cannot unload " + std::string(item_id) +
                 " - item not found in manifest");
    return false;
  }

  cargo_manifest_.erase(it);

  // Simplified weight calculation - assume average item weight
  double avg_weight = cargo_manifest_.empty()
                          ? current_load_
                          : current_load_ / (cargo_manifest_.size() + 1);
  current_load_ -= avg_weight;
  if (current_load_ < 0)
    current_load_ = 0;

  std::cout << "Unloaded item " << item_id << ". Remaining load: " << std::fixed
      << std::setprecision(1) << current_load_ << " kg ("
      << std::setprecision(0) << get_load_percentage() << "%)\n";

  return true;
}

std::vector<std::string>
CarrierRobot::calculate_route(std::string_view dest_zone) {
  std::vector<std::string> route;

  // Simplified route calculation - placeholder implementation
  route.push_back("Starting from current position");
  route.push_back("Navigate to main corridor");
  route.push_back("Proceed to zone " + std::string(dest_zone));
  route.push_back("Arrive at destination");

  log_activity("Route calculated to zone " + std::string(dest_zone) + " (" +
               std::to_string(route.size()) + " waypoints)");

  return route;
}

bool CarrierRobot::check_weight_limits() const noexcept {
  const double warning_threshold = 90.0;   // 90% of capacity
  const double critical_threshold = 100.0; // 100% of capacity

  double load_percent = get_load_percentage();

  if (load_percent >= critical_threshold) {
    return false; // Over capacity
  } else if (load_percent >= warning_threshold) {
    // Within limits but approaching capacity
    return true;
  }

  return true; // Well within limits
}

double CarrierRobot::get_load_percentage() const noexcept {
  if (load_capacity_ <= 0)
    return 0.0;
  return (current_load_ / load_capacity_) * 100.0;
}

// ==========================================
// POLYMORPHIC METHODS (OVERRIDE)
// ==========================================

void CarrierRobot::execute_task() {
  if (!validate_operation()) {
    log_activity("Cannot execute task - robot not operational");
    return;
  }

  log_activity("*** CarrierRobot executing transport task");

  // Perform pre-transport checks
  if (!check_weight_limits()) {
    log_activity("WARNING: Load exceeds safe limits!");
  }

  // Simulate task execution
  // std::cout << "Transporting " << cargo_manifest_.size()
  //     << " items, total weight: " << std::fixed << std::setprecision(1)
  //     << current_load_ << " kg\n";

  // Call base class move method
  move();

  log_activity("Transport task completed successfully");
}

std::string CarrierRobot::get_task_description() const {
  std::ostringstream oss;
  oss << "Transport " << cargo_manifest_.size() << " items (";
  oss << std::fixed << std::setprecision(1) << current_load_ << "/"
      << load_capacity_;
  oss << " kg, " << std::setprecision(0) << get_load_percentage()
      << "% capacity)";

  return oss.str();
}

// ==========================================
// PRIVATE HELPER METHODS
// ==========================================

void CarrierRobot::optimize_load_distribution() {
  if (cargo_manifest_.empty()) {
    return;
  }

  log_activity("Optimizing load distribution for better balance");

  // Simplified optimization - in reality this would involve
  // complex algorithms for weight distribution and center of gravity
  std::sort(cargo_manifest_.begin(), cargo_manifest_.end());

  log_activity("Load distribution optimized");
}

} // namespace robotics