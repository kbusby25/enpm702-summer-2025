/**
 * @file string_view_demo.cpp
 * @author Zeid Kootbally (zeidk@umd.edu)
 * @brief Demonstration of std::string_view
 * @version 1.0
 * @date 2025-07-27
 * 
 * @copyright Copyright (c) 2025
 * 
 */


#include <chrono>
#include <iostream>
#include <string>
#include <string_view>


//===========
//== Demo #1
//===========

// // Using const std::string& - less flexible
// void process_name(const std::string& name) { /* ... */
// }

// int main() {
//     std::string full_name = "John Smith";
//     const char* c_string = "Jane Doe";

//     process_name(full_name);      // OK
//     process_name(c_string);       // Creates temporary std::string -> expensive!
//     process_name("Bob Johnson");  // Creates temporary std::string -> expensive!

//     // Want substring? Need to create new string:
//     process_name(full_name.substr(0, 4));  // Allocates memory for "John"
// }

//===========
//== Demo #2
//===========

// // Using std::string_view
// void process_name(std::string_view name) { /* ... */
// }

// int main() {
//     std::string john = "John Smith";
//     const char* jane = "Jane Doe";

//     process_name(john);           // OK - no conversion
//     process_name(jane);           // OK - no conversion
//     process_name("Bob Johnson");  // OK - no conversion

//     // Substrings are free:
//     process_name(john.substr(0, 4));  // No allocation - just view!
// }


//===========
//== Demo #3
//===========

// Function that takes const std::string&
void process_string(const std::string& str) {
    // Simple work to prevent optimization
    if (!str.empty()) {
        std::cout << "";  // Minimal work
    }
}

// Function that takes std::string_view
void process_string_view(std::string_view str) {
    // Same simple work
    if (!str.empty()) {
        std::cout << "";  // Minimal work
    }
}

int main() {
    constexpr int iterations{1000000};
    auto test_string{"This is a test string for performance comparison"};

    std::cout << "Testing " << iterations << " iterations\n";

    // Test const std::string&
    auto start{std::chrono::high_resolution_clock::now()};
    for (int i{0}; i < iterations; ++i) {
        process_string(test_string);  // Creates temporary std::string
    }
    auto end{std::chrono::high_resolution_clock::now()};
    auto time1{std::chrono::duration_cast<std::chrono::microseconds>(end - start).count()};

    // Test std::string_view
    start = std::chrono::high_resolution_clock::now();
    for (int i{0}; i < iterations; ++i) {
        process_string_view(test_string);  // No temporary
    }
    end = std::chrono::high_resolution_clock::now();
    auto time2{std::chrono::duration_cast<std::chrono::microseconds>(end - start).count()};

    // Results
    std::cout << "const std::string&: " << time1 << " μs\n";
    std::cout << "std::string_view:   " << time2 << " μs\n";
    std::cout << "Speedup: " << (double)time1 / time2 << "x\n";
}