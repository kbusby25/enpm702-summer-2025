/**
 * @file static_demo.cpp
 * @author Zeid Kootbally (zeidk@umd.edu)
 * @brief Demonstration of static attributes and methods
 * @version 0.1
 * @date 2025-07-29
 *
 * @copyright Copyright (c) 2025
 *
 */

#include "modern_features/static_demo.hpp"
#include <iostream>

// Counter example
int main() {
  Counter counter;
  std::cout << Counter::s_count << '\n';        // Access public static
  std::cout << Counter::get_secret() << '\n';  // Access private static
  std::cout << counter.s_count << '\n';         // Access public static
  std::cout << counter.get_secret() << "\n\n"; // Access private static
  //   std::cout << Counter::s_secret << '\n';   // Error: 's_secret' is private

  CounterInline counter_inline;
  std::cout << CounterInline::s_count << '\n';       // Access public static
  std::cout << CounterInline::get_secret() << '\n'; // Access private static
  std::cout << counter_inline.s_count << '\n';       // Access public static
  std::cout << counter_inline.get_secret() << '\n'; // Access private static
  //   std::cout << CounterInline::s_secret << '\n';   // Error: 's_secret' is
  //   private
}

// // Math example
// int main() {
//   // Static methods - no object needed
//   std::cout << "Pi: " << Math::get_pi() << '\n';
//   std::cout << "Square of 4: " << Math::square(4) << '\n';
//   std::cout << "Calculations so far: " << Math::get_calculation_count() << '\n';

//   // Create objects to use non-static methods
//   Math calc1(1.0); // High precision
//   Math calc2(0.1); // Lower precision

//   std::cout << "Circle area (calc1): " << calc1.compute_area(5.0) << '\n';
//   std::cout << "Circle area (calc2): " << calc2.compute_area(5.0) << '\n';

//   std::cout << "Total calculations: " << Math::get_calculation_count() << '\n';
// }
