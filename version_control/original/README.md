
# Autonomous Delivery Robot: ENPM702-Tech-Bot

This repository contains the configuration files and documentation for the ENPM702-Tech-Bot, an autonomous delivery robot platform. The primary goal of this project is to manage and version control the robot's operational parameters.
Overview

The robot's behavior is primarily controlled by the robot_config.yaml file. This file defines all critical parameters, from hardware specifications to mission-level settings. Centralizing the configuration in this repository allows for reliable tracking of changes, easier collaboration among team members, and stable deployment rollbacks.
`robot_config.yaml`

This is the master configuration file for the robot. It is structured into several key sections:

- `hardware`: Defines the core computing and sensor components, such as the CPU, memory, LiDAR, and camera models.
- `navigation`: Controls all movement-related parameters, including the navigation update rate, maximum speed, acceleration, and path-planning algorithms.
- `power_management`: Manages the robot's battery settings, including the low-power threshold and auto-recharge behavior.
<!-- - `gps`: Contains settings for the GPS module. This section can be enabled or disabled depending on the operational requirements. -->