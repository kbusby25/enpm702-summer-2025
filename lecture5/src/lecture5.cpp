/**
 * @file lecture5.cpp
 * @author Zeid Kootbally (zeidk@umd.edu)
 * @brief Code snippets for lecture 5 on functions
 * @version 0.1
 * @date 2025-07-03
 *
 * @copyright Copyright (c) 2025
 *
 */

#include <array>
#include <iomanip>
#include <iostream>
#include <string>
#include <typeinfo>  // needed for typeid
#include <vector>

// function declaration/prototype
int add_numbers(int a, int b);

// function definition/implementation
int add_numbers(int a, int b) {
    return a + b;
}

int main() {
    // //==============
    // //======== 1
    // //==============

    // //==============
    // //======== 2
    // //==============
    std::cout << add_numbers(3, 5) << '\n';
}