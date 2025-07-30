/**
 * @file scanner_robot.cpp
 * @brief Implementation file for the ScannerRobot class
 * @author zeidk (zeidk@umd.edu)
 * @version 2.0
 * @date 2025-07-27
 */

#include "scanner_robot.hpp"
#include <algorithm>
#include <iomanip>
#include <iostream>
#include <random>
#include <sstream>

namespace robotics {

// ==========================================
// CONSTRUCTOR
// ==========================================

ScannerRobot::ScannerRobot(std::string_view robot_id, double range,
                           double accuracy)
    : Robot(robot_id, "ScannerBot-S2"), scanner_range_(range),
      scan_accuracy_(accuracy) {

  if (range <= 0) {
    throw std::invalid_argument("Scanner range must be positive");
  }

  if (accuracy < 0 || accuracy > 100) {
    throw std::invalid_argument("Scan accuracy must be between 0 and 100");
  }

  std::cout << "ScannerRobot initialized with range: " << std::fixed
            << std::setprecision(1) << range
            << "m, accuracy: " << std::setprecision(1) << accuracy << "%\n";

  // Perform initial calibration
  calibrate_scanner();
}

// ==========================================
// SCANNING OPERATIONS
// ==========================================

std::string ScannerRobot::scan_barcode(std::string_view barcode) {
  if (!validate_operation()) {
    // log_activity("Cannot scan barcode - robot not operational");
    return "";
  }

  if (barcode.empty()) {
    // log_activity("Cannot scan empty barcode");
    return "";
  }

  // Simulate scanning accuracy
  static std::random_device rd;
  static std::mt19937 gen(rd());
  std::uniform_real_distribution<> dis(0.0, 100.0);

  bool scan_successful = dis(gen) <= scan_accuracy_;

  if (!scan_successful) {
    // log_activity("Barcode scan failed - poor reading conditions");
    return "";
  }

  // Generate item ID from barcode (simplified)
  std::string item_id = "ITEM_" + std::string(barcode);

  // Add to inventory buffer
  inventory_buffer_.push_back(item_id);

  // std::cout << "Successfully scanned barcode " << barcode
  //           << " -> Item ID: " << item_id << '\n';

  return item_id;
}

void ScannerRobot::update_inventory(std::string_view item_id) {
  if (!validate_operation()) {
    log_activity("Cannot update inventory - robot not operational");
    return;
  }

  // Check if item is in buffer
  auto it =
      std::find(inventory_buffer_.begin(), inventory_buffer_.end(), item_id);
  if (it == inventory_buffer_.end()) {
    // log_activity("Item " + std::string(item_id) + " not found in scan buffer");
    return;
  }

  // log_activity("Updated inventory record for item " + std::string(item_id));

  // In a real system, this would update a database
  // For now, just log the update
}

bool ScannerRobot::validate_scan(std::string_view item_id) const {
  if (item_id.empty()) {
    return false;
  }

  // Simplified validation - check if item follows expected format
  if (item_id.length() < 5 || item_id.substr(0, 5) != "ITEM_") {
    return false;
  }

  // Simulate database validation
  static std::random_device rd;
  static std::mt19937 gen(rd());
  std::uniform_real_distribution<> dis(0.0, 100.0);

  // 95% chance of validation success for properly formatted items
  return dis(gen) <= 95.0;
}

void ScannerRobot::sync_database() {
  if (!validate_operation()) {
    // log_activity("Cannot sync database - robot not operational");
    return;
  }

  if (inventory_buffer_.empty()) {
    // log_activity("No items in buffer to sync");
    return;
  }

  // std::cout << "Syncing " << inventory_buffer_.size()
  //           << " items with central database\n";

  // Simulate database synchronization
  size_t successful_syncs = 0;
  for (const auto &item_id : inventory_buffer_) {
    if (validate_scan(item_id)) {
      successful_syncs++;
    }
  }

  // std::cout << "Database sync completed: " << successful_syncs << "/"
  //           << inventory_buffer_.size() << " items synchronized successfully\n";

  // Clear buffer after sync
  clear_buffer();
}

void ScannerRobot::clear_buffer() {
  size_t cleared_count = inventory_buffer_.size();
  inventory_buffer_.clear();

  // if (cleared_count > 0) {
  //   log_activity("Cleared inventory buffer (" + std::to_string(cleared_count) +
  //                " items)");
  // }
}

// ==========================================
// POLYMORPHIC METHODS (OVERRIDE)
// ==========================================

void ScannerRobot::execute_task() {
  if (!validate_operation()) {
    log_activity("Cannot execute task - robot not operational");
    return;
  }

  log_activity("*** ScannerRobot executing scanning and inventory task");

  // Perform scanner calibration check
  calibrate_scanner();

  // Simulate scanning multiple items
  std::vector<std::string> sample_barcodes = {"12345", "67890", "ABC123",
                                              "XYZ789"};

  for (const auto &barcode : sample_barcodes) {
    std::string item_id = scan_barcode(barcode);
    if (!item_id.empty()) {
      update_inventory(item_id);
    }
  }

  // Call base class move method
  move();

  // Sync with database if buffer has items
  if (!inventory_buffer_.empty()) {
    sync_database();
  }

  log_activity("Scanning task completed successfully");
}

std::string ScannerRobot::get_task_description() const {
  std::ostringstream oss;
  oss << "Scan inventory items (Range: " << std::fixed << std::setprecision(1)
      << scanner_range_ << "m, Accuracy: " << scan_accuracy_
      << "%, Buffer: " << inventory_buffer_.size() << " items)";

  return oss.str();
}

// ==========================================
// PRIVATE HELPER METHODS
// ==========================================

void ScannerRobot::calibrate_scanner() {
  // log_activity("Calibrating scanner systems...");

  // Simulate calibration process
  // In reality, this would involve hardware calibration procedures

  // Slight accuracy improvement after calibration
  if (scan_accuracy_ < 99.0) {
    scan_accuracy_ += 0.5;
    if (scan_accuracy_ > 99.0) {
      scan_accuracy_ = 99.0;
    }
  }

  // std::ostringstream oss;
  // oss << "Scanner calibration complete. Current accuracy: " << std::fixed
  //     << std::setprecision(1) << scan_accuracy_ << "%";
  // log_activity(oss.str());
}

} // namespace robotics