/**
 * @file lecture5.cpp
 * @author Zeid Kootbally (zeidk@umd.edu)
 * @brief Function definitions for lecture 5 on functions.
 * @version 2.0
 * @date 2025-07-03
 *
 * @copyright Copyright (c) 2025
 *
 */

#include "lecture5.hpp"

//======== 2
// void print_hello()
// {
//     std::cout << "hello, ";
//     print_world();
// }

// void print_world()
// {
//     std::cout << "world\n";
// }

//======== 3
// void print_hello()
// {
//     std::cout << "hello, ";
//     print_world();
// }

// void print_world()
// {
//     std::cout << "world\n";
// }

//======== 4
// void prompt_user() {
//     std::cout << "Enter a number: ";
//     int num{};
//     std::cin >> num;
//     print_number(num);
// }

// void print_number(int number) {
//     if (number == -1)
//         return;

//     if (number > 0)
//         std::cout << "The number is: " << number << "\n";
//     else
//         prompt_user();
// }

//======== 5
// void add_ten(int x)
// {
//     // Implicit int x{a};
//     x += 10; // 15
// }

//======== 6
// void add_ten(int &x) {
//     // Implicit: int &x{a};
//     x = x + 10;  // 15
// }

//======== 7
// Exercise 4

//======== 8
// void push_ten(std::vector<int> &v) {  // Passed by reference
//     // Implicit: std::vector<int> &v{num_vect};
//     v.push_back(6);
// }

//======== 9
// void print_vector(const std::vector<int> &v) {  // Passed by const reference
//     // Implicit: const std::vector<int> &v{num_vect};
//     for (const int &item : v) {
//         std::cout << item << " ";  // 1 2 3 4 5
//     }
//     // v.push_back(100);  // This would be an error since v is const
// }

//======== 10
// void add_ten(int *p)
// {
//     // Implicit: int* p{&a};
//     *p += 10;
// }

//======== 11
// void count_calls()
// {
//     // static variable
//     static int count{0};
//     count++;
//     std::cout << count << " time(s)\n";
// }

//======== 12
// Exercise #5

//======== 13
// std::vector<int> create_vector()
// {
//     return std::vector<int>{1, 2, 3};
//     //     ^^^^^^^^^^^^^^^^^^^^^^^^^
//     //     Prvalue - guaranteed RVO
// }

//======== 14
// std::vector<int> create_vector()
// {
//     std::vector<int> local_vec{1, 2, 3};
//     // ... potential operations on local_vec ...
//     return local_vec; // Named object return
// }

//======== 15
// std::vector<int> conditional_return(bool flag)
// {
//     std::vector<int> vec1{1, 2, 3};
//     std::vector<int> vec2{4, 5, 6};
//     return flag ? vec1 : vec2; // NRVO fails!
// }

// std::vector<int> multiple_paths(int choice)
// {
//     std::vector<int> result{};
//     if (choice == 1)
//     {
//         result = {1, 2, 3};
//         return result; // NRVO fails!
//     }
//     else if (choice == 2)
//     {
//         result = {4, 5, 6};
//         return result; // NRVO fails!
//     }
//     return result; // NRVO fails!
// }

//======== 16
// std::vector<int> create_vector()
// {
//     std::vector<int> local_vect{1, 2, 3};
//     std::cout << "&local_vect: " << &local_vect << '\n'; //@1
//     return local_vect;
// }

//======== 17
// // Function to return a reference to the element at a given index
// int &get_element(std::vector<int> &vec, int index)
// {
//     return vec[index]; // Returning a reference to the element
// }

//======== 18
// // Function to return a const reference to the element at a given index
// const int &get_element(std::vector<int> &vec, int index)
// {
//     return vec[index]; // Returning a reference to the element
// }

//======== 19
// // Function to return a reference to a static variable
// int &f()
// {
//     static int var{1};
//     std::cout << var << '\n';
//     return var;
// }

//======== 20
// // Declaration
// auto add(int a, int b);

// // Definition
// auto add(int a, int b) { return a + b; }

//======== 21
// int truncate_double()
// {
//     double value = 10.75;
//     return value; // 10.75 → 10 (truncated)
// }

// bool to_bool()
// {
//     int value = 0;
//     return value; // 0 → false, non-zero → true
// }

// char to_char()
// {
//     int ascii = 65;
//     return ascii; // 65 → 'A'
// }

//======== 22
// int add(int a, int b) { return a + b; }
// double add(double a, double b) { return a + b; }
// double add(int a, double b) { return a + b; }
// double add(double a, int b) { return a + b; }
// double add(double a, double b, double c) { return a + b + c; }

//======== 23
// double return_value(double a)
// {
//     return a;
// }

// int return_value(double a)
// { // Error: redefinition of 'return_value'
//     return a;
// }

//======== 24
// int add(int a, int b) { return a + b; }
// int add(int a, float b) { return a + b; }
// //========
// int add(int a, int b) { return a + b; }
// int add(int a, float b) { return a + b; }
// int add(int a, double b) { return a + b; }

//======== 25
// void add(int a, int b = 0, int c = 0); // Declaration with defaults
// void add(int a, int b = 0, int c = 0)
// { // ERROR: Defaults repeated!
//     std::cout << a + b + c << '\n';
// }

//======== 26
// // COMPILATION ERROR: These are considered identical signatures!
// void func(int a, int b);     // Signature: func(int, int)
// void func(int a, int b = 5); // Signature: func(int, int) - defaults ignored!

//======== 27
void f(int &x, int y, int z)
{
    x += y + z;
}

int g(int a, int b)
{
    int result{};
    result = a + b;
    f(result, a, b);
    return result;
}

//======== 28
// long long factorial(int n)
// {
//     if (n <= 1)
//         return 1;                // Base case: 0! or 1! is 1
//     return n * factorial(n - 1); // Recursive call
// }