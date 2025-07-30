/**
 * @file battery.cpp
 * @brief Implementation file for the Battery class
 * @author zeidk (zeidk@umd.edu)
 * @version 2.0
 * @date 2025-07-27
 */

#include "warehouse_robotics/battery.hpp"
#include <iostream>
#include <stdexcept>
#include <iomanip>
#include <sstream>



// ==========================================
// CONSTRUCTOR
// ==========================================

robotics::Battery::Battery(std::string_view battery_id, double capacity)
    : capacity_(capacity), charge_level_(capacity), battery_id_(battery_id) {
    
    if (capacity <= 0) {
        throw std::invalid_argument("Battery capacity must be positive");
    }
    
    if (battery_id.empty()) {
        throw std::invalid_argument("Battery ID cannot be empty");
    }
}
