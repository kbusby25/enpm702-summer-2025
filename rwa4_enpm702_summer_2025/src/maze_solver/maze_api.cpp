#include "maze_solver/maze_api.hpp"
#include <cstdlib>
#include <iostream>

int maze::MazeControlAPI::get_maze_width() {
    std::cout << "mazeWidth\n";
    std::string response;
    std::cin >> response;
    return atoi(response.c_str());
}

int maze::MazeControlAPI::get_maze_height() {
    std::cout << "mazeHeight\n";
    std::string response;
    std::cin >> response;
    return atoi(response.c_str());
}

bool maze::MazeControlAPI::has_wall_front() {
    std::cout << "wallFront\n";
    std::string response;
    std::cin >> response;
    return response == "true";
}

bool maze::MazeControlAPI::has_wall_right() {
    std::cout << "wallRight\n";
    std::string response;
    std::cin >> response;
    return response == "true";
}

bool maze::MazeControlAPI::has_wall_left() {
    std::cout << "wallLeft\n";
    std::string response;
    std::cin >> response;
    return response == "true";
}

void maze::MazeControlAPI::move_forward(int distance) {
    std::cout << "moveForward ";
    // Don't print distance argument unless explicitly specified, for
    // backwards compatibility with older versions of the simulator
    if (distance != 1) {
        std::cout << distance;
    }
    std::cout << std::endl;
    std::string response;
    std::cin >> response;
    if (response != "ack") {
        std::cerr << response << std::endl;
        throw;
    }
}

void maze::MazeControlAPI::turn_right() {
    std::cout << "turnRight\n";
    std::string ack;
    std::cin >> ack;
}

void maze::MazeControlAPI::turn_left() {
    std::cout << "turnLeft\n";
    std::string ack;
    std::cin >> ack;
}

void maze::MazeControlAPI::set_wall(int x, int y, char direction) {
    std::cout << "setWall " << x << " " << y << " " << direction << std::endl;
}

void maze::MazeControlAPI::clear_wall(int x, int y, char direction) {
    std::cout << "clearWall " << x << " " << y << " " << direction << std::endl;
}

void maze::MazeControlAPI::set_color(int x, int y, char color) {
    std::cout << "setColor " << x << " " << y << " " << color << std::endl;
}

void maze::MazeControlAPI::clear_color(int x, int y) {
    std::cout << "clearColor " << x << " " << y << std::endl;
}

void maze::MazeControlAPI::clear_all_color() {
    std::cout << "clearAllColor\n";
}

void maze::MazeControlAPI::set_text(int x, int y, const std::string& text) {
    std::cout << "setText " << x << " " << y << " " << text << std::endl;
}

void maze::MazeControlAPI::clear_text(int x, int y) {
    std::cout << "clearText " << x << " " << y << std::endl;
}

void maze::MazeControlAPI::clear_all_text() {
    std::cout << "clearAllText\n";
}

bool maze::MazeControlAPI::was_reset() {
    std::cout << "wasReset\n";
    std::string response;
    std::cin >> response;
    return response == "true";
}

void maze::MazeControlAPI::ack_reset() {
    std::cout << "ackReset\n";
    std::string ack;
    std::cin >> ack;
}

void maze::MazeControlAPI::log(std::string_view text) { std::cerr << text << '\n'; }
