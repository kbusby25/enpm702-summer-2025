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
    double distance_coords = calculate_distance(0.0, 0.0, 3.0, 4.0);
    std::pair<double, double> point1 = {0.0, 0.0};
    std::pair<double, double> point2 = {5.0, 12.0};
    double distance_points = calculate_distance(point1, point2);
    
    // Cleaning System Testing
    std::cout << "=== CLEANING SYSTEM TESTING ===\n";
    double cleaning_efficiency = calculate_efficiency(150.0, 75.0);
    double estimated_battery_life = estimate_battery_life(60.0, "eco");
    double current_battery = 100.0;
    double total_cleaned_area = 0.0;
    update_status(current_battery, total_cleaned_area, 25.0, 80.0);
    
    // Utils Testing
    std::cout << "=== UTILS TESTING ===\n";
    std::vector<double> efficiency_data = {85.5, 92.0, 78.3, 88.7, 91.2};
    double average_efficiency = calculate_average(efficiency_data);
    double minimum_value;
    double maximum_value;
    bool extremes_found = find_extremes(efficiency_data, minimum_value, maximum_value);
    display_status(12.5, 8.3, 85.7, 92.4);
}