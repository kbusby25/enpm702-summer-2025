/**
 * @file carrier_robot.hpp
 * @brief Header file for the CarrierRobot class in the Warehouse Robot Management System
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
class Position;

/**
 * @class CarrierRobot
 * @brief Specialized robot for transporting items in the warehouse
 * 
 * CarrierRobot extends the base Robot class to provide cargo transportation
 * capabilities including load management, route calculation, and weight monitoring.
 */
class CarrierRobot : public Robot {
private:
    double load_capacity_;           ///< Maximum weight capacity in kg
    double current_load_{0.0};           ///< Current load weight in kg
    std::vector<std::string> cargo_manifest_;  ///< List of items currently loaded
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
    virtual ~CarrierRobot() = default;

    // ==========================================
    // CARGO MANAGEMENT
    // ==========================================

    /**
     * @brief Loads an item onto the robot
     * @param item_id ID of the item to load
     * @param weight Weight of the item in kg
     * @return true if item was successfully loaded, false if capacity exceeded
     */
    bool load_item(std::string_view item_id, double weight);

    /**
     * @brief Unloads an item from the robot
     * @param item_id ID of the item to unload
     * @return true if item was successfully unloaded, false if item not found
     */
    bool unload_item(std::string_view item_id);

    /**
     * @brief Calculates route to destination (placeholder for future Position integration)
     * @param dest_zone Destination zone name
     * @return Vector of waypoint descriptions
     */
    std::vector<std::string> calculate_route(std::string_view dest_zone);

    /**
     * @brief Checks if current load is within safe limits
     * @return true if load is within limits, false otherwise
     */
    bool check_weight_limits() const noexcept;

    /**
     * @brief Gets current load percentage
     * @return Load percentage (0.0 to 100.0)
     */
    [[nodiscard]] double get_load_percentage() const noexcept;

    /**
     * @brief Gets current load weight
     * @return Current load in kg
     */
    [[nodiscard]] double get_current_load() const noexcept { return current_load_; }

    /**
     * @brief Gets load capacity
     * @return Maximum capacity in kg
     */
    [[nodiscard]] double get_load_capacity() const noexcept { return load_capacity_; }

    /**
     * @brief Gets number of items currently loaded
     * @return Number of items in cargo manifest
     */
    [[nodiscard]] size_t get_item_count() const noexcept { return cargo_manifest_.size(); }

    // ==========================================
    // POLYMORPHIC METHODS (OVERRIDE)
    // ==========================================

    /**
     * @brief Executes cargo transport task
     * @override Implements specialized task execution for cargo transport
     */
    void execute_task();

    /**
     * @brief Gets description of current transport task
     * @return String description of the transport task
     * @override Provides specialized task description for cargo operations
     */
    [[nodiscard]] std::string get_task_description() const;

private:
    /**
     * @brief Optimizes load distribution for better balance
     */
    void optimize_load_distribution();
};

} // namespace robotics