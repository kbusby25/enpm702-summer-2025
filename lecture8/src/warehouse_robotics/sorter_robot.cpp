/**
 * @file sorter_robot.cpp
 * @brief Implementation file for the SorterRobot class
 * @author zeidk (zeidk@umd.edu)
 * @version 2.0
 * @date 2025-07-27
 */

#include "warehouse_robotics/sorter_robot.hpp"
#include <algorithm>
#include <iomanip>
#include <iostream>
#include <random>
#include <sstream>
#include <unordered_map>

// ==========================================
// CONSTRUCTOR
// ==========================================

robotics::SorterRobot::SorterRobot(std::string_view robot_id, double accuracy)
    : robotics::Robot(robot_id, "SorterBot-T3"), sort_accuracy_(accuracy),
      current_zone_("Zone_A") {

  if (accuracy < 0 || accuracy > 100) {
    throw std::invalid_argument("Sort accuracy must be between 0 and 100");
  }

  std::cout << "SorterRobot initialized with accuracy: " << std::fixed
            << std::setprecision(1) << accuracy << "%, starting in "
            << current_zone_ << '\n';
}

// ==========================================
// POLYMORPHIC METHODS (OVERRIDE)
// ==========================================
void robotics::SorterRobot::execute_task() {
  log_activity("*** SorterRobot executing sorting and organization task");
}
