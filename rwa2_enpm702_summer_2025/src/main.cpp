#include "sensor_types.hpp"
#include <iostream>
#include <iomanip>
#include <vector>
#include <unordered_map>
#include <string>
#include <random>
#include <algorithm>
#include <numeric>

int main() {
    std::cout << "=== ROBOT DUAL-SENSOR SYSTEM ===\n\n";
    
    // ========================================================================
    // STEP 1: Initialize Data Structures
    // ========================================================================
    
    // Storage for all sensor data across timestamps
    std::vector<TimestampData> sensor_readings;
    
    // Quality tracking variables
    const std::unordered_map<std::string, int> initial_counts{{"LIDAR", 0}, {"Camera", 0}};
    std::unordered_map<std::string, int> valid_readings{initial_counts};
    std::unordered_map<std::string, int> total_readings{initial_counts};
    
    // Variables for calculating summary statistics
    double total_lidar_avg_distance{0.0};
    double total_camera_brightness{0.0};
    int total_obstacles_detected{0};
    int day_mode_count{0};
    int night_mode_count{0};
    
    // ========================================================================
    // STEP 2: Setup Random Number Generation
    // ========================================================================
    std::random_device rd;
    std::mt19937 gen{rd()};
    
    // TODO: Create the required distributions
    
    
    // ========================================================================
    // STEP 3: Data Generation Loop (Timestamps 0-4)
    // ========================================================================
    std::cout << "Generating sensor data for 5 timestamps...\n\n";
    
    for (int timestamp{0}; timestamp < NUM_TIMESTAMPS; ++timestamp) {
        TimestampData current_data;
        current_data.timestamp = timestamp;
        
        // TODO: Generate LIDAR data (8 distance readings)
     
        // TODO: Generate Camera data (RGB tuple)
    }
    
    // ========================================================================
    // STEP 4: Data Processing Loop
    // ========================================================================
    for (const auto& data : sensor_readings) {
        std::cout << "Processing Timestamp: " << data.timestamp << '\n';
        
        // ----------------------------------------------------------------
        // LIDAR Processing
        // ----------------------------------------------------------------
        total_readings["LIDAR"]++;
        
        // TODO: Process LIDAR data
        // Extract lidar readings
        
        // TODO: Calculate average distance using std::accumulate
        
        // TODO: Count obstacles (readings < 2.0 meters)
    
        
        // TODO: Validate LIDAR data (all readings > 0.05m)
        
        // TODO: Display LIDAR output
       
        // ----------------------------------------------------------------
        // Camera Processing
        // ----------------------------------------------------------------
        total_readings["Camera"]++;
        
        // TODO: Process Camera data using structured bindings
        
        // TODO: Calculate brightness and classify lighting
          
        // TODO: Validate Camera data (RGB values 0-255, brightness > 20)
         
        // TODO: Display Camera output
    
        std::cout << '\n';
    }
    
    // ========================================================================
    // STEP 5: Summary Statistics
    // ========================================================================
    std::cout << "=== SUMMARY STATISTICS ===\n";
    
    // TODO: Calculate and display total statistics
 
    // TODO: Calculate individual sensor reliability percentages
 
    // TODO: Display sensor reliability report

    // TODO: Display average sensor values and operational statistics
}