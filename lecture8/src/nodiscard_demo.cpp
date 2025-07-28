#include <iostream>
#include <string>

// Function with [[nodiscard]] - compiler will warn if return value is ignored
[[nodiscard]] int divide(int a, int b) noexcept {
    if (b == 0) {
        return -1; // Error indicator
    }
    return a / b;
}

int main() {
    // GOOD: Using the return value with uniform initialization
    const auto result{divide(10, 2)};
    std::cout << "Result: " << result << '\n';
    
    // BAD: Ignoring return value - compiler will issue warning
    // divide(20, 4);  // Warning: ignoring return value of function declared with 'nodiscard'
}