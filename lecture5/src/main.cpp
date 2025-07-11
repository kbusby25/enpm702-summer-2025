/**
 * @file main.cpp
 * @author Zeid Kootbally (zeidk@umd.edu)
 * @brief Source code for lecture 5 on functions
 *
 * This file contains only the main function. Other function declarations are located in lecture5.cpp. Other function definitions are located in lecture5.hpp.
 * @version 2.0
 * @date 2025-07-11
 *
 * @copyright Copyright (c) 2025
 *
 */

#include <iomanip>
#include <iostream>
#include <vector>

#include "lecture5.hpp"

int main()
{
    //======== 1
    //==============

    //======== 2
    //==============
    // print_hello();
    // std::cout << "exit main\n";

    //======== 3
    //==============
    // print_hello();
    // std::cout << "exit main\n";

    //======== 4
    //==============
    // prompt_user();

    //======== 5
    //==============
    // int a{5};
    // add_ten(a);
    // std::cout << a << '\n'; // 5

    //======== 6
    //==============
    // int a{5};
    // add_ten(a);
    // std::cout << a << '\n'; // 15

    //======== 7
    //==============
    // int x{5};
    // int y{10};

    // std::cout << x << ", " << y << '\n'; // 5, 10
    // swap_values(x, y);
    // std::cout << x << ", " << y << '\n'; // 10, 5

    //======== 8
    //==============
    // std::vector<int> num_vect{1, 2, 3, 4, 5};
    // push_ten(num_vect);
    // for (const auto &item : num_vect)
    // {
    //     std::cout << item << " "; // 1 2 3 4 5 6
    // }
    // std::cout << '\n';

    //======== 9
    //==============
    // std::vector<int> num_vect{1, 2, 3, 4, 5};
    // print_vector(num_vect);

    //======== 10
    //==============
    // int a{5};
    // add_ten(&a);
    // std::cout << a << '\n'; // 15

    //======== 11
    //==============

    // count_calls();  // 1 time(s);
    // count_calls();  // 2 time(s);
    // count_calls();  // 3 time(s);

    //======== 12
    //==============

    // add_to_sum(1); // 1
    // add_to_sum(2); // 3
    // add_to_sum(3); // 6
    // add_to_sum(4); // 10

    //======== 13
    //==============
    // std::vector<int> vect{create_vector()};
    // // Construction directly in vect's location

    //======== 14
    //==============
    // std::vector<int> result{create_vector()};

    //======== 15
    //==============

    //======== 16
    //==============
    // std::vector<int> v1{};
    // v1 = create_vector();                // No copy elision
    // std::cout << "&v1: " << &v1 << '\n'; //@2

    //======== 17
    //==============
    // std::vector<int> my_vector{1, 2, 3, 4, 5};

    // // Get a reference to the element at index 2
    // int &ref = get_element(my_vector, 2);

    // // Modify the element via the reference
    // ref = 10;

    // // Check the new value
    // std::cout << my_vector[2] << '\n';

    //======== 18
    //==============
    // std::vector<int> my_vector = {1, 2, 3, 4, 5};

    // // Get a reference to the element at index 2
    // const int &ref = get_element(my_vector, 2);

    // // No intention of modifying the returned reference
    // std::cout << ref << '\n';

    //======== 19
    //==============
    // f() = 5;         // 1
    // auto &ref = f(); // 5
    // ref = 10;
    // f(); // 10

    //======== 20
    //==============
    // std::cout << add(2, 3) << '\n';

    //======== 21
    //==============

    //======== 22
    //==============
    // std::cout << add(2, 3) << '\n';           // add(int, int)
    // std::cout << add(2, 3.5) << '\n';         // add(int, double)
    // std::cout << add(2.5, 3) << '\n';         // add(double, int)
    // std::cout << add(2.5, 3.2) << '\n';       // add(double, double)
    // std::cout << add(2.5, 3.2, 4.75) << '\n'; // add(double, double, double)

    //======== 23
    //==============

    //======== 24
    //==============

    // std::cout << add(2, 3) << '\n';    // add(int, int) -- exact match
    // std::cout << add(2, 3.5f) << '\n'; // add(int, float) -- exact match
    // //==============
    // std::cout << add(2.5, 3) << '\n';     // add(double, int) -- ???
    // std::cout << add('h', false) << '\n'; // add(char, bool) -- ???

    //======== 25
    //==============

    //======== 26
    //==============

    //======== 27
    //==============
    int x{10};
    int y{20};
    int z{};
    z = g(x, y);
    std::cout << z << '\n';

    //======== 28
    //==============
    // int n{};
    // std::cout << "Enter a number: ";
    // std::cin >> n;
    // std::cout << "Factorial of " << n << " is " << factorial(n) << '\n';
}

//======== 29
//==============
// int main(int argc, char *argv[]) {
//     std::cout << "Number of arguments: " << argc << '\n';
//     for (int i{0}; i < argc; i++) {
//         std::cout << "Argument " << i << ": " << argv[i] << '\n';
//     }
// }