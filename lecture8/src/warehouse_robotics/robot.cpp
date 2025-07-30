/**
 * @file Robot.cpp
 * @brief Implementation file for the Robot class in the Warehouse Robot
 * Management System
 * @author zeidk (zeidk@umd.edu)
 * @version 2.0
 * @date 2025-07-27
 */

#include "warehouse_robotics/robot.hpp"

#include <iostream>
#include <stdexcept>

// ==========================================
// CONSTRUCTORS AND DESTRUCTOR
// ==========================================

robotics::Robot::Robot(std::string_view robot_id, std::string_view model)
    : robot_id_{robot_id}, model_{model} {
  // Log robot creation
  log_activity("Robot created with ID: " + robot_id_ + ", Model: " + model_);

  // Install default battery (composition - battery is owned by robot)
  assign_battery(std::string(robot_id) + "_battery", 100.0);
}

void robotics::Robot::assign_battery(std::string_view battery_id,
                                     double capacity) {
  battery_ = std::make_unique<robotics::Battery>(battery_id, capacity);
  log_activity("Battery installed: " + std::string(battery_id) +
               " with capacity " + std::to_string(capacity) + " Ah");
}

robotics::Robot::Robot(std::string_view robot_id, std::string_view model,
                       std::string_view battery_id, double battery_capacity)
    : robot_id_{robot_id}, model_{model},
      battery_{std::make_unique<Battery>(battery_id, battery_capacity)} {
  // Log robot creation
  log_activity("Robot created with ID: " + robot_id_ + ", Model: " + model_);
  log_activity("Battery initialized with ID: " + std::string(battery_id) +
               ", Capacity: " + std::to_string(battery_capacity) + " Ah");
}

// robotics::Robot::~Robot() {
//     // Log robot destruction
//     // log_activity("Robot " + robot_id_ + " (" + model_ + ") is being
//     destroyed");
// }

// ==========================================
// TASK MANAGEMENT
// ==========================================

void robotics::Robot::execute_task() {
  // Base implementation - derived classes should override for specific behavior
  log_activity("*** Executing generic robot task for " + robot_id_);
}

void robotics::Robot::assign_task(std::shared_ptr<robotics::Task> task) {
    if (!task) {
        throw std::invalid_argument("Cannot assign null task to robot");
    }
    // Set the task status to robotics::TaskStatus::ASSIGNED
    std::cout << "[Robot LOG] Task assigned to robot\n";
}
// ==========================================
// UTILITY METHODS
// ==========================================

void robotics::Robot::log_activity(std::string_view message) const {
  // Output with standardized format for consistent logging
  std::cout << "[ROBOT LOG] " << message << '\n';
}
