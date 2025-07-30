/**
 * @file task.hpp
 * @brief Header file for the Task class in the Warehouse Robot Management
 * System
 * @author zeidk (zeidk@umd.edu)
 * @version 2.0
 * @date 2025-07-27
 */

#pragma once

#include "warehouse_robotics/support.hpp"
#include <memory>
#include <string>
#include <string_view>

namespace robotics {

// Forward declarations
class Robot;

/**
 * @class Task
 * @brief Task class for robot task management
 *
 * This class represents a task that can be assigned to robots (aggregation
 * relationship). Tasks can exist independently and can be reassigned between
 * robots.
 */
class Task {
private:
  std::string task_id_;          ///< Unique task identifier
  robotics::TaskType task_type_; ///< Type of task
  robotics::Priority priority_;  ///< Task priority level
  robotics::TaskStatus status_{
      robotics::TaskStatus::CREATED}; ///< Current task status

public:
  /**
   * @brief Constructor for Task
   * @param task_id Unique identifier for the task
   * @param task_type Type of the task
   * @param priority Priority level of the task
   */
  Task(std::string_view task_id, TaskType task_type, Priority priority);

  /**
   * @brief Virtual destructor
   */
  // virtual ~Task() = default;


}; // class Task

} // namespace robotics