#pragma once

/**
 * @file support.hpp
 * @brief Support definitions for the Warehouse Robot Management System
 * @author zeidk (zeidk@umd.edu)
 * @version 1.0
 * @date 2025-07-23
 */

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
 *       conversions and provide better type safety
 *
 * @see Robot::get_status()
 * @see Robot::operational_status_
 */
enum class RobotStatus {
    /**
     * @brief Robot is idle and available for task assignment
     *
     * The robot is powered on, fully functional, and waiting for commands.
     * This is the default state for robots that are not currently performing
     * any operations.
     */
    IDLE,

    /**
     * @brief Robot is actively performing a task
     *
     * The robot is currently executing an assigned task such as moving,
     * scanning, sorting, or carrying items. In this state, the robot
     * should not be assigned new tasks until the current one is completed.
     */
    ACTIVE,

    /**
     * @brief Robot is connected to a charging station
     *
     * The robot is currently charging its battery and is not available
     * for task assignment. The robot will automatically transition to
     * IDLE state when charging is complete and battery level is sufficient.
     */
    CHARGING,

    /**
     * @brief Robot is undergoing maintenance or calibration
     *
     * The robot is temporarily out of service for scheduled maintenance,
     * repairs, or calibration procedures. Tasks cannot be assigned to
     * robots in this state until maintenance is completed.
     */
    MAINTENANCE,

    /**
     * @brief Robot has encountered an error and requires attention
     *
     * The robot has experienced a malfunction, collision, or other error
     * condition that prevents normal operation. Human intervention or
     * system diagnosis is required before the robot can resume normal
     * operations.
     */
    ERROR
};  // class RobotStatus
}  // namespace robotics