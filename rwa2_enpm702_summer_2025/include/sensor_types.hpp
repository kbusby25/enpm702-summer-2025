/**
 * @file sensor_types.hpp
 * @author zeid kootbally (zeidk@umd.edu)
 * @brief Variables and data structures for assignment #2
 * @version 1.2
 * @date 2025-07-11
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#ifndef SENSOR_TYPES_HPP
#define SENSOR_TYPES_HPP

#include <vector>
#include <tuple>
#include <string>

// Data structures for different sensor types
using LidarData = std::vector<double>;        // 8 distance readings in meters
using CameraData = std::tuple<int, int, int>; // RGB values (0-255 each)

// Sensor configuration constants
constexpr int NUM_TIMESTAMPS{5};
constexpr int LIDAR_READINGS_COUNT{8};
constexpr double LIDAR_MIN_RANGE{0.01};
constexpr double LIDAR_MAX_RANGE{10.0};
constexpr double LIDAR_MIN_VALID{0.05};
constexpr double OBSTACLE_THRESHOLD{2.0};
constexpr int RGB_MIN{0};
constexpr int RGB_MAX{255};
constexpr double BRIGHTNESS_THRESHOLD{20.0};
constexpr double DAY_NIGHT_THRESHOLD{100.0};

// Structure to hold sensor readings at each timestamp
struct TimestampData {
    LidarData lidar_readings;
    CameraData camera_readings;
    int timestamp;
};

#endif // SENSOR_TYPES_HPP