/**
 * @file battery.hpp
 * @brief Header file for the Battery class in the Warehouse Robot Management
 * System
 * @author zeidk (zeidk@umd.edu)
 * @version 2.0
 * @date 2025-07-27
 */

#pragma once

#include "warehouse_robotics/support.hpp"
#include <string>
#include <string_view>

namespace robotics {

/**
 * @class Battery
 * @brief Battery class for robot power management
 *
 * This class represents a battery that is owned by a robot (composition
 * relationship). The battery cannot exist independently of the robot that owns
 * it.
 */
class Battery {
private:
  double capacity_;     ///< Battery capacity in amp-hours
  double charge_level_; ///< Current charge level in amp-hours
  ChargingStatus charging_status_{
      robotics::ChargingStatus::FULL}; ///< Current charging status
  std::string battery_id_;             ///< Unique battery identifier
public:
  /**
   * @brief Constructor for Battery
   * @param battery_id Unique identifier for the battery
   * @param capacity Battery capacity in amp-hours
   */
  Battery(std::string_view battery_id, double capacity);

  /**
   * @brief Virtual destructor
   */
  virtual ~Battery() = default;
}; // class Battery
} // namespace robotics