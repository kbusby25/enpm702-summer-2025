/**
 * @file scanner_robot.hpp
 * @brief Header file for the ScannerRobot class in the Warehouse Robot Management System
 * @author zeidk (zeidk@umd.edu)
 * @version 2.0
 * @date 2025-07-27
 */

#pragma once

#include "robot.hpp"
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
    virtual ~ScannerRobot() = default;

    // ==========================================
    // SCANNING OPERATIONS
    // ==========================================

    /**
     * @brief Scans a barcode and identifies the item
     * @param barcode Barcode string to scan
     * @return Item ID if scan successful, empty string if failed
     */
    std::string scan_barcode(std::string_view barcode);

    /**
     * @brief Updates inventory records for a scanned item
     * @param item_id ID of the item to update in inventory
     */
    void update_inventory(std::string_view item_id);

    /**
     * @brief Validates a scanned item against database
     * @param item_id ID of the item to validate
     * @return true if item is valid, false otherwise
     */
    bool validate_scan(std::string_view item_id) const;

    /**
     * @brief Synchronizes local inventory buffer with central database
     */
    void sync_database();

    /**
     * @brief Gets scanner range
     * @return Scanner range in meters
     */
    [[nodiscard]] double get_scanner_range() const noexcept { return scanner_range_; }

    /**
     * @brief Gets scan accuracy
     * @return Scan accuracy percentage
     */
    [[nodiscard]] double get_scan_accuracy() const noexcept { return scan_accuracy_; }

    /**
     * @brief Gets number of items in buffer
     * @return Number of scanned items in buffer
     */
    [[nodiscard]] size_t get_buffer_size() const noexcept { return inventory_buffer_.size(); }

    /**
     * @brief Clears the inventory buffer
     */
    void clear_buffer();

    // ==========================================
    // POLYMORPHIC METHODS (OVERRIDE)
    // ==========================================

    /**
     * @brief Executes scanning and inventory task
     * @override Implements specialized task execution for scanning operations
     */
    void execute_task();

    /**
     * @brief Gets description of current scanning task
     * @return String description of the scanning task
     * @override Provides specialized task description for scanning operations
     */
    [[nodiscard]] std::string get_task_description() const;

private:
    /**
     * @brief Calibrates the scanner for optimal performance
     */
    void calibrate_scanner();
};

} // namespace robotics