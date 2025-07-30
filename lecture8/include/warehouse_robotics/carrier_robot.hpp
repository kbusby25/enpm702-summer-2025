/**
 * @file carrier_robot.hpp
 * @brief Header file for the CarrierRobot class in the Warehouse Robot
 * Management System
 * @author zeidk (zeidk@umd.edu)
 * @version 2.0
 * @date 2025-07-27
 */

#pragma once

#include "warehouse_robotics/robot.hpp"
#include <string>
#include <string_view>
#include <vector>

namespace robotics {

// Forward declarations
class Item;
class Position;

/**
 * @class CarrierRobot
 * @brief Specialized robot for transporting items in the warehouse
 *
 * CarrierRobot extends the base Robot class to provide cargo transportation
 * capabilities including load management, route calculation, and weight
 * monitoring.
 */
class CarrierRobot : public Robot {
private:
  double load_capacity_;                    ///< Maximum weight capacity in kg
  double current_load_{0.0};                ///< Current load weight in kg
  std::vector<std::string> cargo_manifest_; ///< List of items currently loaded
public:
  /**
   * @brief Constructor for CarrierRobot
   * @param robot_id Unique identifier for the robot
   * @param capacity Maximum load capacity in kg
   */
  CarrierRobot(std::string_view robot_id, double capacity);

  /**
   * @brief Virtual destructor
   */
  // virtual ~CarrierRobot() = default;

  // ==========================================
  // POLYMORPHIC METHODS (OVERRIDE)
  // ==========================================

  /**
   * @brief Executes cargo transport task
   * @override Implements specialized task execution for cargo transport
   */
  void execute_task();
};

} // namespace robotics