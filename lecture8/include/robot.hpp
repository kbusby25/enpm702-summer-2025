/**
 * @file Robot.hpp
 * @brief Header file for the Robot class in the Warehouse Robot Management
 * System
 * @author zeidk (zeidk@umd.edu)
 * @version 2.0
 * @date 2025-07-27
 */

#pragma once

#include <memory>
#include <string>
#include <string_view>

#include "support.hpp"

namespace robotics {
// Forward declarations for classes that will be implemented later
// class Operator;
// class Battery;
// class Position;

/**
 * @class Robot
 * @brief Concrete Robot class representing warehouse robots in the management
 * system
 *
 * This class serves as the base implementation for all warehouse robots. It
 * provides core functionality for robot operations including movement, task
 * execution, and status management. The class is designed to be extensible for
 * specialized robot types such as CarrierRobot, ScannerRobot, and SorterRobot.
 *
 * @note Members are now properly encapsulated with controlled access
 * @see RobotStatus
 */
class Robot {
private:
  // ==========================================
  // PRIVATE MEMBER VARIABLES
  // ==========================================

  /**
   * @brief Unique identifier for the robot
   *
   * A string that uniquely identifies this robot instance within the
   * warehouse management system. Used for logging, tracking, and
   * task assignment purposes.
   */
  std::string robot_id_;

  /**
   * @brief Model designation of the robot
   *
   * Specifies the robot model type, which may determine capabilities,
   * specifications, and compatible operations.
   */
  std::string model_;

  /**
   * @brief Current operational status of the robot
   *
   * Indicates the robot's current state in the system. This affects
   * the robot's availability for task assignment and operational capabilities.
   *
   * @see RobotStatus
   */
  RobotStatus operational_status_ = robotics::RobotStatus::IDLE;

public:
  // ==========================================
  // CONSTRUCTORS AND DESTRUCTOR
  // ==========================================

  /**
   * @brief Constructor for Robot class with ID and model
   *
   * Initializes a new robot instance with the specified ID and model.
   * The robot starts in IDLE status and logs its creation.
   *
   * @param robot_id Unique identifier for the robot
   * @param model Model designation of the robot
   *
   * @post Robot is created with IDLE status
   * @post Creation is logged to the activity log
   */
  Robot(std::string_view robot_id, std::string_view model);

  /**
   * @brief Virtual destructor for proper cleanup
   *
   * Ensures proper cleanup when robot objects are destroyed,
   * especially important for inheritance scenarios.
   */
  ~Robot();

  // ==========================================
  // ACCESSORS (GETTERS)
  // ==========================================

  /**
   * @brief Gets the robot's unique identifier
   *
   * @return String view of the robot's ID for efficient access
   */
  [[nodiscard]] std::string_view get_robot_id() const noexcept {
    return robot_id_;
  }

  /**
   * @brief Gets the model designation of the robot
   *
   * Retrieves the model string that identifies the type and specifications
   * of this robot instance.
   *
   * @return String view of the robot's model designation
   */
  [[nodiscard]] std::string_view get_model() const noexcept { return model_; }

  /**
   * @brief Gets the current operational status of the robot
   *
   * @return Current RobotStatus of this robot instance
   *
   * @see RobotStatus
   */
  [[nodiscard]] robotics::RobotStatus get_status() const noexcept {
    return operational_status_;
  }

  // ==========================================
  // MUTATORS (SETTERS)
  // ==========================================

  /**
   * @brief Sets the model designation of the robot
   *
   * Updates the robot's model designation string that identifies the type
   * and specifications of this robot instance.
   *
   * @param model New model designation to assign to the robot
   *
   * @post Robot's model designation is updated to the specified value
   * @post Model change is logged to the activity log
   */
  void set_model(std::string_view model);

  // ==========================================
  // CORE ROBOT OPERATIONS
  // ==========================================

  /**
   * @brief Moves the robot to a new location
   *
   * Initiates robot movement after validating that the operation is allowed.
   * Changes robot status to ACTIVE during movement and logs the activity.
   *
   * @pre Robot must pass operation validation (not in ERROR or MAINTENANCE)
   * @post Robot status set to ACTIVE if movement is successful
   * @post Movement activity is logged
   *
   * @throws std::runtime_error if robot cannot perform operation
   */
  void move();

  /**
   * @brief Updates the robot's position coordinates
   *
   * Updates the robot's current position in the warehouse coordinate system.
   *
   * @note Position parameter commented out until Position class is implemented
   * @post Position update is logged
   */
  void update_position(/* const Position& pos */);

  // ==========================================
  // ASSIGNMENT METHODS (COMMENTED OUT)
  // ==========================================

  /**
   * @brief Assigns an operator to this robot
   *
   * Associates a human operator with this robot for monitoring and control.
   *
   * @note Method commented out until Operator class is implemented
   * @param op The operator to assign to this robot
   */
  // void assign_operator(const Operator& op);

  /**
   * @brief Assigns a battery to this robot
   *
   * Associates a battery unit with this robot for power management.
   *
   * @note Method commented out until Battery class is implemented
   * @param bat The battery to assign to this robot
   */
  // void assign_battery(const Battery& bat);

  // ==========================================
  // TASK MANAGEMENT
  // ==========================================

  /**
   * @brief Executes a generic task assigned to the robot
   *
   * Performs the robot's current task after validating that the operation
   * is allowed. This method can be overridden by derived classes to
   * implement specialized task execution.
   *
   * @pre Robot must pass operation validation
   * @post Robot status set to ACTIVE if task execution begins
   * @post Task execution is logged
   *
   * @throws std::runtime_error if robot cannot perform operation
   * @see validate_operation()
   */
  void execute_task();

  /**
   * @brief Gets a description of the robot's current task
   *
   * Returns a human-readable description of what task the robot is
   * currently assigned to perform. Can be overridden by derived classes
   * to provide specific task descriptions.
   *
   * @return String description of the current task
   */
  [[nodiscard]] std::string get_task_description() const;

  // ==========================================
  // UTILITY METHODS
  // ==========================================

  /**
   * @brief Validates whether the robot can perform operations
   *
   * Checks if the robot is in a state that allows it to perform
   * operations such as movement or task execution.
   *
   * @return true if robot can perform operations, false otherwise
   * @retval true Robot is not in ERROR or MAINTENANCE status
   * @retval false Robot is in ERROR or MAINTENANCE status
   */
  [[nodiscard]] bool validate_operation() const noexcept;

  /**
   * @brief Logs robot activities with formatted output
   *
   * Records robot activities and events to the console with a
   * standardized format for debugging and monitoring purposes.
   *
   * @param message The activity message to log
   *
   * @post Message is output to console with [ROBOT LOG] prefix
   */
  void log_activity(std::string_view message) const;

  // ==========================================
  // COMPARISON OPERATORS
  // ==========================================

  /**
   * @brief Equality comparison operator
   *
   * Two robots are considered equal if they have the same robot_id
   *
   * @param other Robot to compare with
   * @return true if robots have the same ID, false otherwise
   */
  [[nodiscard]] bool operator==(const Robot &other) const noexcept {
    return robot_id_ == other.robot_id_;
  }

  /**
   * @brief Inequality comparison operator
   *
   * @param other Robot to compare with
   * @return true if robots have different IDs, false otherwise
   */
  [[nodiscard]] bool operator!=(const Robot &other) const noexcept {
    return !(*this == other);
  }

  /**
   * @brief Less-than comparison operator for sorting
   *
   * Compares robots by their robot_id for use in sorted containers
   *
   * @param other Robot to compare with
   * @return true if this robot's ID is lexicographically less than other's
   */
  [[nodiscard]] bool operator<(const Robot &other) const noexcept {
    return robot_id_ < other.robot_id_;
  }

private:
  // ==========================================
  // PRIVATE HELPER METHODS
  // ==========================================

  /**
   * @brief Converts RobotStatus enum to string representation
   *
   * @param status The RobotStatus enum value to convert
   * @return String representation of the status
   */
  std::string status_to_string(robotics::RobotStatus status) const noexcept;
}; // class Robot

} // namespace robotics