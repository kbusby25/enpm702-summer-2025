/**
 * @file scanner_robot.cpp
 * @brief Implementation file for the ScannerRobot class
 * @author zeidk (zeidk@umd.edu)
 * @version 2.0
 * @date 2025-07-27
 */

#include "warehouse_robotics/scanner_robot.hpp"
#include <algorithm>
#include <iomanip>
#include <iostream>
#include <random>
#include <sstream>

// ==========================================
// CONSTRUCTOR
// ==========================================

robotics::ScannerRobot::ScannerRobot(std::string_view robot_id, double range,
                                     double accuracy)
    : robotics::Robot(robot_id, "ScannerBot-S2"), scanner_range_(range),
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
}

// ==========================================
// POLYMORPHIC METHODS (OVERRIDE)
// ==========================================

void robotics::ScannerRobot::execute_task() {
  log_activity("*** ScannerRobot executing scanning and inventory task");
}
