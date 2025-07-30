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

#include "warehouse_robotics/battery.hpp"
#include "warehouse_robotics/support.hpp"
#include "warehouse_robotics/task.hpp"

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
  RobotStatus operational_status_{robotics::RobotStatus::IDLE};
  std::unique_ptr<robotics::Battery> battery_;

  void assign_battery(std::string_view battery_id, double capacity);

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
   * @brief Constructor for Robot class with ID, model, and battery attributes
   *
   * Initializes a new robot instance with the specified ID, model, and battery.
   * The robot starts in IDLE status and logs its creation with battery
   * installation.
   *
   * @param robot_id Unique identifier for the robot
   * @param model Model designation of the robot
   * @param battery_id Unique identifier for the battery
   * @param battery_capacity Battery capacity in amp-hours
   *
   * @post Robot is created with IDLE status
   * @post Battery is installed with specified attributes
   * @post Creation is logged to the activity log
   */
  Robot(std::string_view robot_id, std::string_view model,
        std::string_view battery_id, double battery_capacity);

  /**
   * @brief Virtual destructor for proper cleanup
   *
   * Ensures proper cleanup when robot objects are destroyed,
   * especially important for inheritance scenarios.
   */
  // ~Robot();

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

  void assign_task(std::shared_ptr<robotics::Task> task);


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

}; // class Robot

} // namespace robotics