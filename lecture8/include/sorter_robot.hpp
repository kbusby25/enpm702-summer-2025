/**
 * @file sorter_robot.hpp
 * @brief Header file for the SorterRobot class in the Warehouse Robot Management System
 * @author zeidk (zeidk@umd.edu)
 * @version 2.0
 * @date 2025-07-27
 */

#pragma once

#include "robot.hpp"
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
    double sort_accuracy_;          ///< Sorting accuracy percentage
    std::queue<std::string> processing_queue_;  ///< Queue of items to process
    std::string current_zone_;      ///< Current zone the robot is in

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
    virtual ~SorterRobot() = default;

    // ==========================================
    // SORTING OPERATIONS
    // ==========================================

    /**
     * @brief Categorizes an item based on its properties
     * @param item_id ID of the item to categorize
     * @return Category string for the item
     */
    std::string categorize_item(std::string_view item_id);

    /**
     * @brief Applies sorting rules to determine item placement
     * @param item_id ID of the item to apply rules to
     */
    void apply_sorting_rules(std::string_view item_id);

    /**
     * @brief Moves robot to specified zone
     * @param zone Target zone to move to
     */
    void move_to_zone(std::string_view zone);

    /**
     * @brief Updates sorting statistics and performance metrics
     */
    void update_sort_statistics();

    /**
     * @brief Adds item to processing queue
     * @param item_id ID of item to add to queue
     */
    void add_to_queue(std::string_view item_id);

    /**
     * @brief Processes next item in the queue
     * @return Item ID that was processed, empty string if queue empty
     */
    std::string process_next_item();

    /**
     * @brief Gets sort accuracy
     * @return Sort accuracy percentage
     */
    [[nodiscard]] double get_sort_accuracy() const noexcept { return sort_accuracy_; }

    /**
     * @brief Gets current zone
     * @return Current zone name
     */
    [[nodiscard]] std::string_view get_current_zone() const noexcept { return current_zone_; }

    /**
     * @brief Gets number of items in processing queue
     * @return Queue size
     */
    [[nodiscard]] size_t get_queue_size() const noexcept { return processing_queue_.size(); }

    /**
     * @brief Clears the processing queue
     */
    void clear_queue();

    // ==========================================
    // POLYMORPHIC METHODS (OVERRIDE)
    // ==========================================

    /**
     * @brief Executes sorting and organization task
     * @override Implements specialized task execution for sorting operations
     */
    void execute_task();

    /**
     * @brief Gets description of current sorting task
     * @return String description of the sorting task
     * @override Provides specialized task description for sorting operations
     */
    [[nodiscard]] std::string get_task_description() const;

private:
    /**
     * @brief Analyzes item properties for categorization
     * @param item_id ID of item to analyze
     * @return Analysis results as string
     */
    std::string analyze_item_properties(std::string_view item_id);
};

} // namespace robotics