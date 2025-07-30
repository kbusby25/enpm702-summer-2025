/**
 * @file sorter_robot.hpp
 * @brief Header file for the SorterRobot class in the Warehouse Robot
 * Management System
 * @author zeidk (zeidk@umd.edu)
 * @version 2.0
 * @date 2025-07-27
 */

#pragma once

#include "warehouse_robotics/robot.hpp"
#include <queue>
#include <string>
#include <string_view>

namespace robotics {

// Forward declarations
class Item;
class Position;

/**
 * @class SorterRobot
 * @brief Specialized robot for sorting and organizing items
 *
 * SorterRobot extends the base Robot class to provide item categorization,
 * sorting rule application, and zone-based organization capabilities.
 */
class SorterRobot : public Robot {
private:
  double sort_accuracy_;                     ///< Sorting accuracy percentage
  std::queue<std::string> processing_queue_; ///< Queue of items to process
  std::string current_zone_;                 ///< Current zone the robot is in

public:
  /**
   * @brief Constructor for SorterRobot
   * @param robot_id Unique identifier for the robot
   * @param accuracy Sorting accuracy percentage (0.0 to 100.0)
   */
  SorterRobot(std::string_view robot_id, double accuracy);

  /**
   * @brief Virtual destructor
   */
  // virtual ~SorterRobot() = default;

  // ==========================================
  // POLYMORPHIC METHODS (OVERRIDE)
  // ==========================================

  /**
   * @brief Executes sorting and organization task
   * @override Implements specialized task execution for sorting operations
   */
  void execute_task();
};

} // namespace robotics