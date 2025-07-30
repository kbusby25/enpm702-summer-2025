/**
 * @file carrier_robot.cpp
 * @brief Implementation file for the CarrierRobot class
 * @author zeidk (zeidk@umd.edu)
 * @version 2.0
 * @date 2025-07-27
 */

#include "warehouse_robotics/carrier_robot.hpp"
#include <algorithm>
#include <iomanip>
#include <iostream>

// ==========================================
// CONSTRUCTOR
// ==========================================

robotics::CarrierRobot::CarrierRobot(std::string_view robot_id, double capacity)
    : robotics::Robot(robot_id, "CarrierBot-X1"), load_capacity_(capacity) {

  if (capacity <= 0) {
    throw std::invalid_argument("Load capacity must be positive");
  }
  std::cout << "CarrierRobot initialized with capacity: " << std::fixed
            << std::setprecision(1) << capacity << " kg\n";
}

// ==========================================
// POLYMORPHIC METHODS (OVERRIDE)
// ==========================================

void robotics::CarrierRobot::execute_task() {
  log_activity("*** CarrierRobot executing transport task");
}