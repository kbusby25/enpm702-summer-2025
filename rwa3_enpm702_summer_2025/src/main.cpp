/**
 * @file main.cpp
 * @author Zeid Kootbally (zeidk@umd.edu)
 * @brief Main file for assignment #3
 * @version 1.0
 * @date 2025-07-13
 * 
 * @copyright Copyright (c) 2025
 * 
 */

 #include<iostream>
 #include<vector>
 // include other header files.

int main() {
    // Navigation Testing
    std::cout << "=== NAVIGATION TESTING ===\n";

    // Distance calculation tests
    const double distance_coords{calculate_distance(0.0, 0.0, 3.0, 4.0)};
    const auto point1 = std::make_pair(0.0, 0.0);
    const auto point2 = std::make_pair(5.0, 12.0);
    const double distance_points{calculate_distance(point1, point2)};

    // Coordinate validation tests
    is_valid_coordinate(50.0);
    is_valid_coordinate(-5.0);
    is_valid_coordinate(75.0, 10.0, 80.0);
    is_valid_coordinate({25.0, 75.0});
    is_valid_coordinate({50.0, 120.0});
    is_valid_coordinate({30.0, 40.0}, 20.0, 60.0);

    // Total distance calculation
    const std::vector<std::pair<double, double>> waypoints{
        {0.0, 0.0}, {5.0, 0.0}, {5.0, 12.0}, {10.0, 15.0}, {12.5, 15.0}};
    const double total_distance{calculate_total_distance(waypoints)};

    // Cleaning System Testing
    std::cout << "\n=== CLEANING SYSTEM TESTING ===\n";

    // Efficiency calculation
    const double cleaning_efficiency{calculate_efficiency(75.0, 150.0)};

    // Battery life estimation - both versions
    const double battery_life_default{estimate_battery_life(60.0)};
    const double battery_life_eco{estimate_battery_life(60.0, "eco")};
    const double battery_life_turbo{estimate_battery_life(60.0, "turbo")};

    // Status update
    double current_battery{100.0};   // NOT const - modified by update_status
    double total_cleaned_area{0.0};  // NOT const - modified by update_status
    update_status(current_battery, total_cleaned_area, 25.0, 80.0);

    // Utils Testing
    std::cout << "\n=== UTILS TESTING ===\n";

    // Average calculation
    const std::vector<double> efficiency_data{85.5, 92.0, 78.3, 88.7, 91.2};
    const double average_efficiency{calculate_average(efficiency_data)};

    // Find extremes
    double min_value{};  // NOT const - may be modified by find_extremes
    double max_value{};  // NOT const - may be modified by find_extremes
    const bool extremes_found{find_extremes(efficiency_data, min_value, max_value)};

    // Test with empty vector
    const std::vector<double> empty_data{};
    double min_empty{};  // NOT const - may be modified by find_extremes
    double max_empty{};  // NOT const - may be modified by find_extremes
    const bool extremes_empty{find_extremes(empty_data, min_empty, max_empty)};

    // Test with non-empty vector (different initial values)
    const std::vector<double> sensor_data{-3.2, 7.8, -1.5, 9.4, 2.1};
    double min_sensor{};  // NOT const - may be modified by find_extremes
    double max_sensor{};  // NOT const - may be modified by find_extremes
    const bool extremes_sensor{find_extremes(sensor_data, min_sensor, max_sensor)};

    // Display status
    display_status(12.5, 8.3, 85.7, 92.4);
}