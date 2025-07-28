/**
 * @file explicit_demo.cpp
 * @author Zeid Kootbally (zeidk@umd.edu)
 * @brief Demonstration of explicit usage
 * @version 1.0
 * @date 2025-07-27
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#include <iostream>

// ========================================
// PROBLEM: Without explicit
// ========================================

class Box {
public:
  Box(int size) : size_{size} {} // Non-explicit
  int get_size() const { return size_; }

private:
  int size_;
};

void ship_box(const Box &box) {
  std::cout << "Shipping box of size " << box.get_size() << '\n';
}

int main() {
  // These work, but intent is unclear:
  Box box = 10; // Looks like assignment, but creates Box
  ship_box(20);  // Looks like passing int, but creates Box
}

// ========================================
// SOLUTION: With explicit
// ========================================

// class Box {
// public:
//   explicit Box(int size) : size_{size} {} // Non-explicit
//   int get_size() const { return size_; }

// private:
//   int size_;
// };

// void ship_box(const Box &box) {
//   std::cout << "Shipping box of size " << box.get_size() << '\n';
// }

// int main() {
//   // These cause compilation errors:
//   //   Box box = 10;     // ERROR: no implicit conversion
//   // ship_box(20);     // ERROR: no implicit conversion

//   // Must be explicit:
//     Box box{10};      // Clear: creating SafeBox object
//     ship_box(Box{20}); // Clear: creating SafeBox object
// }