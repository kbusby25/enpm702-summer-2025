/**
 * @file support.hpp
 * @brief Support definitions for the Warehouse Robot Management System
 * @author zeidk (zeidk@umd.edu)
 * @version 1.0
 * @date 2025-07-23
 */

#pragma once

namespace robotics {

/**
 * @enum RobotStatus
 * @brief Enumeration representing the operational status of warehouse robots
 *
 * This enumeration defines the various states that a robot can be in during
 * its operation within the warehouse management system. The status affects
 * the robot's ability to perform tasks and move within the warehouse.
 *
 * @note This is a scoped enumeration (enum class) to prevent implicit
 * conversions and provide better type safety
 *
 * @see Robot::get_status()
 * @see Robot::operational_status_
 */
enum class RobotStatus {
    IDLE,        ///< Robot is idle and available for task assignment
    ACTIVE,      ///< Robot is actively performing a task
    CHARGING,    ///< Robot is connected to a charging station
    MAINTENANCE, ///< Robot is undergoing maintenance or calibration
    ERROR        ///< Robot has encountered an error and requires attention
}; // enum class RobotStatus

/**
 * @enum ChargingStatus
 * @brief Enumeration for battery charging states
 *
 * Defines the possible charging states of a robot's battery system.
 * Used to monitor and manage power levels in warehouse robots.
 */
enum class ChargingStatus {
    CHARGING,    ///< Battery is currently being charged
    FULL,        ///< Battery is fully charged and ready for use
    DISCHARGING, ///< Battery is being consumed during normal operation
    CRITICAL     ///< Battery level is critically low and requires immediate charging
};

/**
 * @enum TaskType
 * @brief Enumeration for different types of tasks
 *
 * Categorizes the various types of operations that can be assigned
 * to robots in the warehouse management system.
 */
enum class TaskType {
    TRANSPORT,   ///< Move items from one location to another
    SCAN,        ///< Scan barcodes and update inventory records
    SORT,        ///< Categorize and organize items by type or destination
    MAINTENANCE  ///< Perform system maintenance or calibration tasks
};

/**
 * @enum Priority
 * @brief Enumeration for task priority levels
 *
 * Defines the urgency levels for task execution, allowing the system
 * to prioritize critical operations over routine tasks.
 */
enum class Priority {
    LOW,     ///< Non-urgent tasks that can be scheduled flexibly
    NORMAL,  ///< Standard priority tasks for regular operations
    HIGH,    ///< Important tasks that should be completed promptly
    URGENT   ///< Critical tasks requiring immediate attention
};

/**
 * @enum TaskStatus
 * @brief Enumeration for task status states
 *
 * Tracks the lifecycle of tasks from creation through completion,
 * enabling proper workflow management and progress monitoring.
 */
enum class TaskStatus {
    CREATED,     ///< Task has been created but not yet assigned
    ASSIGNED,    ///< Task has been assigned to a robot
    IN_PROGRESS, ///< Task is currently being executed
    COMPLETED,   ///< Task has been successfully completed
    FAILED       ///< Task execution failed and requires attention
};

} // namespace robotics