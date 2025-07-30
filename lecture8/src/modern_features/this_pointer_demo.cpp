
/**
 * @file this_demo.cpp
 * @author Zeid Kootbally (zeidk@umd.edu)
 * @brief Demonstration for the this pointer
 * @version 0.1
 * @date 2025-07-29
 *
 * @copyright Copyright (c) 2025
 *
 */

#include "modern_features/this_pointer_demo.hpp"
#include <iostream>

int main() {
  Box b{10};
  b.double_size().print(); // Chaining using 'this'
}