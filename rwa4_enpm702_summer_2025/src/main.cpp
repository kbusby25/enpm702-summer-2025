/**
 * @file main.cpp
 * @author Zeid Kootbally (zeidk@umd.edu)
 * @brief Simple main function showing an example of the micromouse API use
 * @version 0.1
 * @date 2025-08-03
 *
 * @copyright Copyright (c) 2025
 *
 */
#include "maze_solver/maze_api.hpp"
#include <iostream>
#include <string>
#include <string_view>

void log(std::string_view text) { std::cerr << text << '\n'; }

int main() {
  maze::MazeControlAPI maze_control_api;

  log("Running...");
  log("Setting start color and text");
  maze_control_api.set_color(0, 0, 'B');
  maze_control_api.set_text(0, 0, "start");

  log("Setting goal colors and text");
  maze_control_api.set_color(8, 7, 'R');
  maze_control_api.set_text(8, 7, "goal");
  maze_control_api.set_color(7, 7, 'C');
  maze_control_api.set_text(7, 7, "goal");
  maze_control_api.set_color(8, 8, 'G');
  maze_control_api.set_text(8, 8, "goal");
  maze_control_api.set_color(7, 8, 'O');
  maze_control_api.set_text(7, 8, "goal");

  // Example of how to set a left wall in the simulator
  maze_control_api.set_wall(0, 0, 'w');
  // Example of how to set a south wall in the simulator
  maze_control_api.set_wall(0, 0, 's');

  while (true) {
    if (!maze_control_api.has_wall_left()) {
      maze_control_api.turn_left();
    }

    while (maze_control_api.has_wall_front()) {
      maze_control_api.turn_right();
    }
    maze_control_api.move_forward();
  }
}