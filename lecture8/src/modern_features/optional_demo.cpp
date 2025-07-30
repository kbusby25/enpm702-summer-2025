/**
 * @file optional_demo.cpp
 * @author Zeid Kootbally (zeidk@umd.edu)
 * @brief Demonstration of std::optional usage
 * @version 0.1
 * @date 2025-07-29
 *
 * @copyright Copyright (c) 2025
 *
 */

#include <iostream>
#include <optional>

// ==========
// </8>
// ==========
[[nodiscard]] std::optional<int> divide(int a, int b) noexcept {
  if (b == 0) {
    return std::nullopt; // No value - clear error indication
  }
  return a / b; // Has value
}

int main() {
  std::optional<int> result{divide(10, 3)};
  if (result) {                          // Clear: check if has value
    std::cout << *result << '\n';        // Safe access
    std::cout << result.value() << '\n'; // Safe access
  }
}

// ==========
// </9>
// ==========
// int main() {
//   std::optional<int> opt_with_value{10};
//   std::optional<int> opt_empty{std::nullopt};

//   std::cout << "opt_with_value: " << opt_with_value.value_or(-1) << "\n"; // 10
//   std::cout << "opt_empty: " << opt_empty.value_or(-1) << "\n";           // -1
// }