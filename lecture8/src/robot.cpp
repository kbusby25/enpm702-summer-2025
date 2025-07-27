/**
 * @file Robot.cpp
 * @brief Implementation file for the Robot class in the Warehouse Robot Management System
 * @author zeidk (zeidk@umd.edu)
 * @version 2.0
 * @date 2025-07-27
 */

#include "robot.hpp"

#include <iostream>
#include <stdexcept>

// ==========================================
// CONSTRUCTORS AND DESTRUCTOR
// ==========================================

robotics::Robot::Robot(std::string_view robot_id, std::string_view model)
    : robot_id_{robot_id},
      model_{model},
      operational_status_{robotics::RobotStatus::IDLE} {
    // Log robot creation
    log_activity("Robot created with ID: " + robot_id_ + ", Model: " + model_);
}

robotics::Robot::~Robot() {
    // Log robot destruction
    log_activity("Robot " + robot_id_ + " (" + model_ + ") is being destroyed");
}

// ==========================================
// MUTATORS (SETTERS)
// ==========================================

void robotics::Robot::set_model(std::string_view model) {
    std::string old_model = model_;
    model_ = model;
    log_activity("Robot model changed from '" + old_model + "' to '" + model_ + "'");
}

// ==========================================
// CORE ROBOT OPERATIONS
// ==========================================

void robotics::Robot::move() {
    if (!validate_operation()) {
        std::string error_msg = "Robot " + robot_id_ + " cannot move - invalid operational status: " + status_to_string(operational_status_);
        log_activity("FAILED: " + error_msg);
        throw std::runtime_error(error_msg);
    }

    // Set status to ACTIVE during movement
    robotics::RobotStatus previous_status = operational_status_;
    operational_status_ = robotics::RobotStatus::ACTIVE;

    log_activity("Robot " + robot_id_ + " started movement (status changed from " + status_to_string(previous_status) + " to " + status_to_string(operational_status_) + ")");
}

void robotics::Robot::update_position(/* const Position& pos */) {
    // Placeholder implementation until Position class is available
    log_activity("Position updated for robot " + robot_id_);

    // Note: When Position class is implemented, this method should:
    // 1. Validate the new position
    // 2. Update internal position storage
    // 3. Log the position change with coordinates
    // 4. Potentially trigger location-based events
}

// ==========================================
// TASK MANAGEMENT
// ==========================================

void robotics::Robot::execute_task() {
    if (!validate_operation()) {
        std::string error_msg = "Robot " + robot_id_ + " cannot execute task - invalid operational status: " + status_to_string(operational_status_);
        log_activity("FAILED: " + error_msg);
        throw std::runtime_error(error_msg);
    }

    // Set status to ACTIVE during task execution
    robotics::RobotStatus previous_status = operational_status_;
    operational_status_ = robotics::RobotStatus::ACTIVE;

    log_activity("Robot " + robot_id_ + " started task execution (status changed from " + status_to_string(previous_status) + " to " + status_to_string(operational_status_) + ")");

    // Base implementation - derived classes should override for specific behavior
    log_activity("Executing generic robot task for " + robot_id_);
}

std::string robotics::Robot::get_task_description() const {
    // Base implementation returns generic description
    // Derived classes should override to provide specific task descriptions
    return "Generic robot task for " + model_ + " robot (ID: " + robot_id_ + ")";
}

// ==========================================
// UTILITY METHODS
// ==========================================

bool robotics::Robot::validate_operation() const noexcept {
    // Robot can perform operations if it's not in ERROR or MAINTENANCE status
    return operational_status_ != robotics::RobotStatus::ERROR &&
           operational_status_ != robotics::RobotStatus::MAINTENANCE;
}

void robotics::Robot::log_activity(std::string_view message) const {
    // Output with standardized format for consistent logging
    std::cout << "[ROBOT LOG] " << message << '\n';
}

// ==========================================
// HELPER FUNCTIONS (PRIVATE UTILITIES)
// ==========================================

std::string robotics::Robot::status_to_string(robotics::RobotStatus status) const noexcept {
    // Convert RobotStatus enum to human-readable string
    // Note: This assumes RobotStatus enum values - adjust based on your support.hpp
    switch (status) {
        case robotics::RobotStatus::IDLE:
            return "IDLE";
        case robotics::RobotStatus::ACTIVE:
            return "ACTIVE";
        case robotics::RobotStatus::ERROR:
            return "ERROR";
        case robotics::RobotStatus::MAINTENANCE:
            return "MAINTENANCE";
        case robotics::RobotStatus::CHARGING:
            return "CHARGING";
        default:
            return "UNKNOWN";
    }
}