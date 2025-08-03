#pragma once
#include <string>

namespace maze {

/**
 * @brief API for controlling and interacting with a maze environment
 * 
 * This class provides methods to navigate through a maze, query maze properties,
 * manipulate walls, set colors and text, and handle reset events.
 */
class MazeControlAPI {
private:
  short width_{16};  ///< Width of the maze in cells
  short height_{16}; ///< Height of the maze in cells

public:
  /**
   * @brief Get the width of the maze
   * @return The width of the maze in cells
   */
  int get_maze_width();

  /**
   * @brief Get the height of the maze
   * @return The height of the maze in cells
   */
  int get_maze_height();

  /**
   * @brief Check if there is a wall in front of the current position
   * @return true if there is a wall in front, false otherwise
   */
  bool has_wall_front();

  /**
   * @brief Check if there is a wall to the right of the current position
   * @return true if there is a wall to the right, false otherwise
   */
  bool has_wall_right();

  /**
   * @brief Check if there is a wall to the left of the current position
   * @return true if there is a wall to the left, false otherwise
   */
  bool has_wall_left();

  /**
   * @brief Move forward in the maze
   * @param distance Number of cells to move forward (default: 1)
   */
  void move_forward(int distance = 1);

  /**
   * @brief Turn right (clockwise) in the maze
   */
  void turn_right();

  /**
   * @brief Turn left (counter-clockwise) in the maze
   */
  void turn_left();

  /**
   * @brief Set a wall at the specified position and direction
   * @param x X coordinate of the cell
   * @param y Y coordinate of the cell
   * @param direction Direction of the wall ('n', 's', 'e', 'w' for north, south, east, west)
   */
  void set_wall(int x, int y, char direction);

  /**
   * @brief Clear a wall at the specified position and direction
   * @param x X coordinate of the cell
   * @param y Y coordinate of the cell
   * @param direction Direction of the wall ('n', 's', 'e', 'w' for north, south, east, west)
   */
  void clear_wall(int x, int y, char direction);

  /**
   * @brief Set the color of a cell in the maze
   * @param x X coordinate of the cell
   * @param y Y coordinate of the cell
   * @param color Color character identifier
   */
  void set_color(int x, int y, char color);

  /**
   * @brief Clear the color of a cell in the maze
   * @param x X coordinate of the cell
   * @param y Y coordinate of the cell
   */
  void clear_color(int x, int y);

  /**
   * @brief Clear all colors from the entire maze
   */
  void clear_all_color();

  /**
   * @brief Set text at the specified cell in the maze
   * @param x X coordinate of the cell
   * @param y Y coordinate of the cell
   * @param text Text string to display at the cell
   */
  void set_text(int x, int y, const std::string &text);

  /**
   * @brief Clear text from the specified cell in the maze
   * @param x X coordinate of the cell
   * @param y Y coordinate of the cell
   */
  void clear_text(int x, int y);

  /**
   * @brief Clear all text from the entire maze
   */
  void clear_all_text();

  /**
   * @brief Check if the maze was reset
   * @return true if the maze was reset, false otherwise
   */
  bool was_reset();

  /**
   * @brief Acknowledge that the reset has been handled
   */
  void ack_reset();
}; // class MazeControlAPI

} // namespace maze