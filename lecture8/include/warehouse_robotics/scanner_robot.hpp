/**
 * @file scanner_robot.hpp
 * @brief Header file for the ScannerRobot class in the Warehouse Robot Management System
 * @author zeidk (zeidk@umd.edu)
 * @version 2.0
 * @date 2025-07-27
 */

#pragma once

#include "warehouse_robotics/robot.hpp"
#include <vector>
#include <string>
#include <string_view>

namespace robotics {

// Forward declarations
class Item;
class InventoryDatabase;

/**
 * @class ScannerRobot
 * @brief Specialized robot for scanning and inventory management
 * 
 * ScannerRobot extends the base Robot class to provide barcode scanning,
 * inventory tracking, and database synchronization capabilities.
 */
class ScannerRobot : public Robot {
private:
    double scanner_range_;          ///< Scanning range in meters
    double scan_accuracy_;          ///< Scanning accuracy percentage
    std::vector<std::string> inventory_buffer_;  ///< Buffer for scanned items

public:
    /**
     * @brief Constructor for ScannerRobot
     * @param robot_id Unique identifier for the robot
     * @param range Scanning range in meters
     * @param accuracy Scanning accuracy percentage (0.0 to 100.0)
     */
    ScannerRobot(std::string_view robot_id, double range, double accuracy);

    /**
     * @brief Virtual destructor
     */
    // virtual ~ScannerRobot() = default;

    // ==========================================
    // POLYMORPHIC METHODS (OVERRIDE)
    // ==========================================

    /**
     * @brief Executes scanning and inventory task
     * @override Implements specialized task execution for scanning operations
     */
    void execute_task();

};

} // namespace robotics