#include "robot.hpp"

#include <iostream>

// Robot class implementation
Robot::Robot(const std::string& robot_id, const std::string& model)
    : robot_id_(robot_id), model_(model), operational_status_(RobotStatus::IDLE) {
    log_activity("Robot created with ID: " + robot_id_ + ", Model: " + model_);
}

void Robot::move() {
    if (validate_operation()) {
        operational_status_ = RobotStatus::ACTIVE;
        log_activity("Robot " + robot_id_ + " is moving");
    } else {
        log_activity("Robot " + robot_id_ + " cannot move - operation validation failed");
    }
}

RobotStatus Robot::get_status() const {
    return operational_status_;
}

void Robot::update_position(/* const Position& pos */) {
    // Position parameter commented out since Position class is not available
    log_activity("Robot " + robot_id_ + " position updated");
}

// Commented out methods that depend on other classes
/*
void Robot::assign_operator(const Operator& op) {
    log_activity("Operator assigned to robot " + robot_id_);
}

void Robot::assign_battery(const Battery& bat) {
    log_activity("Battery assigned to robot " + robot_id_);
}
*/

void Robot::execute_task() {
    if (validate_operation()) {
        log_activity("Robot " + robot_id_ + " executing generic task");
        operational_status_ = RobotStatus::ACTIVE;
    } else {
        log_activity("Robot " + robot_id_ + " cannot execute task - operation validation failed");
    }
}

std::string Robot::get_task_description() const {
    return "Generic task for robot " + robot_id_;
}

bool Robot::validate_operation() {
    // Simple validation - check if robot is not in error or maintenance state
    return (operational_status_ != RobotStatus::ERROR &&
            operational_status_ != RobotStatus::MAINTENANCE);
}

void Robot::log_activity(const std::string& message) {
    std::cout << "[ROBOT LOG] " << message << std::endl;
}