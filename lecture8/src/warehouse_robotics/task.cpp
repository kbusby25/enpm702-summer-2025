/**
 * @file task.cpp
 * @brief Implementation file for the Task class
 * @author zeidk (zeidk@umd.edu)
 * @version 2.0
 * @date 2025-07-27
 */

#include "warehouse_robotics/task.hpp"
#include "warehouse_robotics/support.hpp"
#include <iostream>
#include <stdexcept>
#include <iomanip>
#include <sstream>
#include <string_view>
#include <unordered_map>


// ==========================================
// CONSTRUCTOR
// ==========================================

robotics::Task::Task(std::string_view task_id, robotics::TaskType task_type, robotics::Priority priority)
    : task_id_(task_id), task_type_(task_type), priority_(priority)  {
    
    if (task_id.empty()) {
        throw std::invalid_argument("Task ID cannot be empty");
    }
}

