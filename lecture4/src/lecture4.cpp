/**
 * @file lecture4.cpp
 * @author Zeid Kootbally (zeidk@umd.edu)
 * @brief Code snippets for lecture 4 on STL containers
 * @version 0.1
 * @date 2025-06-17
 *
 * @copyright Copyright (c) 2025
 *
 */

#include <iostream>
#include <iomanip>
#include <typeinfo> // needed for typeid
#include <string>
#include <array>
#include <vector>
using namespace std::literals::string_literals;

union MyUnion
{
    int int_value;
    double char_value;
};

int main()
{
    // //==============
    // //======== 1
    // //==============
    // char my_string[] = "hello"; // Compiler automatically adds '\0' at the end.
    // // You can stream the character array directly to std::cout
    // std::cout << my_string << '\n';

    // //---

    // const char *my_literal = "world"; // Points to the first character 'w'
    // // std::cout knows to print characters starting from the pointer
    // // until it finds the null-terminator ('\0').
    // std::cout << my_literal << '\n';

    // //==============
    // //======== 2
    // //==============
    // std::string s0("Initial string"); // initialized from a C string

    // std::string s1;                                   // empty string
    // std::string s2(s0);                               // initialized from another string
    // std::string s3(s0, 8, 3);                         // "str"
    // std::string s4("Another character sequence", 12); // "Another char"
    // std::string s5a(10, 'x');                         // "xxxxxxxxxx"
    // std::string s5b(10, 42);                          // "**********"
    // std::string s6(s0.begin(), s0.begin() + 7);       // "Initial"

    // //==============
    // //======== 3
    // //==============
    // auto greeting1{"hello"};                       // C string
    // // std::cout << typeid(greeting1).name() << '\n'; // C string literal

    // // auto greeting2{"hello"s};                      // C++ string
    // // std::cout << typeid(greeting2).name() << '\n'; // C++ string literal

    // std::cout << "hello" << '\n';  // C string literal
    // std::cout << "hello"s << '\n'; // C++ string literal

    // //==============
    // //======== 4
    // //==============
    // std::string greeting{"hello"};
    // std::cout << greeting.length() << '\n'; // 5
    // // or
    // std::cout << greeting.size() << '\n'; // 5

    // //==============
    // //======== 5
    // //==============
    // std::string my_string{"short string"};
    // std::cout << sizeof(my_string) << '\n'; // 32
    // my_string = "This is now a longer string";
    // std::cout << sizeof(my_string) << '\n'; // 32
    // my_string = "This is now an even longer string";
    // std::cout << sizeof(my_string) << '\n'; // 32

    // //==============
    // //======== 6
    // //==============
    // std::string my_string{"Life is cool"};
    // std::cout << sizeof(my_string) << '\n';    // 32
    // std::cout << my_string.length() << '\n';   // 12
    // std::cout << my_string.capacity() << '\n'; // 15

    // //==============
    // //======== 7
    // //==============
    // std::string my_string{"Life is so good!"};
    // std::cout << sizeof(my_string) << '\n';    // 32
    // std::cout << my_string.size() << '\n';     // 16
    // std::cout << my_string.capacity() << '\n'; // 16
    // my_string.append("!");
    // std::cout << my_string.size() << '\n';     // 17
    // std::cout << my_string.capacity() << '\n'; // 32

    // //==============
    // //======== 8
    // //==============
    // // Declare a union variable
    // MyUnion data;

    // // Store an integer in the union
    // data.int_value = 42;
    // // Store a char in the union (overwrites the double)
    // data.char_value = 'H';

    // // Demonstrate that only the last assigned value is valid
    // std::cout << "char: " << data.char_value << '\n';
    // std::cout << "integer: " << data.int_value << '\n';

    // //==============
    // //======== 9
    // //==============
    // Declare a union variable
    // MyUnion data;
    // std::cout << "Size of: " << sizeof(data) << '\n';

    // //==============
    // //======== 10
    // //==============
    // std::string my_string(10, 'x');
    // std::cout << my_string.capacity() << '\n'; // 15
    // my_string.assign(16, 'x');
    // std::cout << my_string.capacity() << '\n'; // 30
    // my_string.assign(32, 'x');
    // std::cout << my_string.capacity() << '\n'; // 60

    // //==============
    // //======== 11
    // //==============
    // initialization
    std::string quote{"Just a flesh wound"};

    // access characters
    std::cout << quote.front() << '\n'; // return a ref to 1st character
    quote.front() = 'j';                // modify the 1st character
    std::cout << quote[0] << '\n';      // return the 1st character
    std::cout << quote[5] << '\n';      // return the 6th character
    std::cout << quote.at(5) << '\n';   // return the 6th character
    std::cout << quote.back() << '\n';  // return a ref to the last character
    quote.back() = 'D';                 // modify the last character
    std::cout << quote.back() << '\n';
    quote[6] = 'A';    // modify the 7th character
    quote.at(6) = 'a'; // modify the 7th character

    // //==============
    // //======== 12
    // //==============
    // std::string greeting{"Hi"};
    // std::cout << greeting[10] << '\n'; // UB

    // //==============
    // //======== 13
    // //==============
    // std::string greeting{"Hi"};
    // std::cout << greeting.at(10) << '\n'; // Error

    // //==============
    // //======== 14
    // //==============
    /*
    write a for loop to print each character of the string
    */

    // //==============
    // //======== 15
    // //==============
    // std::string quote{"Just a flesh wound!"};

    // for (char c : quote)
    // {
    //     std::cout << c << ' ';
    // }
    // std::cout << '\n';

    // //==============
    // //======== 16
    // //==============
    // std::string greeting{"Hi"};
    // for (auto it{greeting.begin()};
    //      it != greeting.end();
    //      ++it)
    // {
    //     std::cout << *it << '\n';
    // }

    // //==============
    // //======== 17
    // //==============
    // std::cout << "Enter your full name: "; // e.g., John Doe
    // std::string name{};
    // std::cin >> name; // John

    // std::cout << "Enter your student id: "; // e.g., 123223LUJ
    // std::string student_id{};
    // std::cin >> student_id; // Doe

    // std::cout << "Name: " << name << ", ID: " << student_id << '\n';

    // //==============
    // //======== 18
    // //==============
    // std::cout << "Enter your full name: ";
    // std::string name{};
    // std::getline(std::cin >> std::ws, name);

    // std::cout << "Enter your student id: ";
    // std::string student_id{};
    // std::getline(std::cin >> std::ws, student_id);

    // std::cout << "Name: " << name << ", ID: " << student_id << '\n';

    // //==============
    // //======== 19
    // //==============
    // std::string s1{"Hello"};
    // s1 += " World"; // append a string
    // s1 += '!';      // append a character
    // //--
    // std::string s2{"Hello"};
    // std::string s3{"World"};
    // std::string s4{s2 + " " + s3};
    // //--
    // std::string s5{"Hello"};
    // s5.append(" World!");
    // //--
    // std::string s6{"Hello"};
    // s6.push_back('!');

    // //==============
    // //======== 20
    // //==============
    // std::string s1{"Hello World"};
    // std::string s2{"Big "};
    // s1.insert(6, s2); // Inserts at position 6
    // //--
    // std::string s3 = "Hello World";
    // std::string s4 = "Wonderful Big Day";
    // s3.insert(6, s4, 10, 4); // Inserts "Big" at the 6th position in s3
    // //--
    // std::string s1 = "Hello World";
    // std::string s2 = "Beautiful ";
    // s1.insert(s1.begin() + 6, s2.begin(), s2.end());

    // //==============
    // //======== 21
    // //==============
    // std::string s1{"Hello World"};
    // s1.erase(s1.size() - 6, 6); // remove 6 characters starting from index 5
    // //--
    // std::string s2{"Hello World"};
    // s2.erase(s2.begin() + 6, s2.end());
    // //--
    // std::string s3 = "Hello";
    // s3.erase(4);
    // //--
    // std::string s4{"Hello World"};
    // s4.clear();
    // //--
    // std::string s5{"Hello"};
    // s5.pop_back();

    // //==============
    // //======== 22
    // //==============
    // std::string s;
    // std::cout << "Size of std::string is " << sizeof s << " bytes\n" //?
    //           << "Default-constructed capacity is " << s.capacity() // ?
    //           << " and size is " << s.size() << '\n';               // ?

    // for (int i = 0; i < 42; i++)
    //     s.append(" 42 ");
    // std::cout << "Capacity after 42 appends is " << s.capacity() // ?
    //           << " and size is " << s.size() << '\n';            // ?

    // s.clear();
    // std::cout << "Capacity after clear() is " << s.capacity() // ?
    //           << " and size is " << s.size() << '\n';         // ?

    // s.shrink_to_fit();
    // std::cout << "Capacity after shrink_to_fit() is " << s.capacity() // ?
    //           << " and size is " << s.size() << '\n';                 // ?

    //==============
    //======== 23
    //==============
    // std::string str = "Hello";
    // std::cout << str.size() << " " << str << '\n'; // 5, "Hello"

    // str.resize(8);                                 // new_size > size: growing
    // std::cout << str.size() << " " << str << '\n'; // 8, "Hello\0\0\0"

    // str.resize(12, '!');                           // new_size > size: growing with specified char
    // std::cout << str.size() << " " << str << '\n'; // 12, "Hello\0\0\0!!!!"

    //==============
    //======== 24
    //==============
    // std::string str = "Hello World!";
    // std::cout << "Size: " << str.size() << ", Content: '" << str << "'\n"; // 12, "Hello World!"

    // str.resize(5);                                                         // new_size < size: shrinking
    // std::cout << "Size: " << str.size() << ", Content: '" << str << "'\n"; // 5, "Hello"

    // std::cout << "Capacity: " << str.capacity() << '\n'; // Unchanged (≥12)

    //==============
    //======== 25
    //==============

    // std::string str = "Hello";
    // std::cout << "Before: Size: " << str.size()
    //           << ", Capacity: " << str.capacity() << '\n'; // 5, ≥5

    // str.resize(5); // new_size == size: no change
    // std::cout << "After:  Size: " << str.size()
    //           << ", Capacity: " << str.capacity() << '\n'; // 5, unchanged

    // std::cout << "Content unchanged: '" << str << "'\n"; // "Hello"

    //==============
    //======== 26
    //==============


    // std::string my_string(10, 'x');
    // std::cout << "Capacity is " << my_string.capacity()       // ?
    //           << " and size is " << my_string.size() << '\n'; // ?
    // my_string.reserve(100);                                   // new_cap > capacity
    // std::cout << "Capacity is " << my_string.capacity()       // ?
    //           << " and size is " << my_string.size() << '\n'; // ?

    //==============
    //======== 27
    //==============

    // std::string my_string(50, 'x');
    // std::cout << "Capacity is " << my_string.capacity()       // ?
    //           << " and size is " << my_string.size() << '\n'; // ?
    // my_string.reserve(100);                                   // new_cap > capacity: guaranteed
    // std::cout << "Capacity is " << my_string.capacity()       // ?
    //           << " and size is " << my_string.size() << '\n'; // ?
    // my_string.reserve(70);                                    // size < new_cap < capacity: non-binding
    // std::cout << "Capacity is " << my_string.capacity()       // ?
    //           << " and size is " << my_string.size() << '\n'; // ?

    //==============
    //======== 28
    //==============

    // std::string my_string(50, 'x');
    // std::cout << "Capacity is " << my_string.capacity()       // Implementation-dependent (≥50)
    //           << " and size is " << my_string.size() << '\n'; // 50
    // my_string.reserve(70);                                   // new_cap > capacity: guaranteed allocation
    // std::cout << "Capacity is " << my_string.capacity()       // ≥70
    //           << " and size is " << my_string.size() << '\n'; // 50 (unchanged)
    // my_string.reserve(40);                                    // new_cap < size < capacity: non-binding
    // std::cout << "Capacity is " << my_string.capacity()       // May shrink to ≥50, may stay ≥70
    //           << " and size is " << my_string.size() << '\n'; // 50 (always unchanged)

    //==============
    //======== 29
    //==============

    // std::string full_name;
    // full_name.reserve(100); // allocate memory for 100 characters

    // std::cout << "Enter your first name: "; // Albus
    // std::string first_name;
    // std::cin >> first_name;
    // full_name.append(first_name);

    // std::cout << "Enter your middle name: "; // Percival
    // std::string middle_name;
    // std::cin >> middle_name;
    // middle_name.resize(1);                     // keep only the first letter
    // full_name.append(" " + middle_name + "."); // add a dot

    // std::cout << "Enter your last name: "; // Dumbledore
    // std::string last_name;
    // std::cin >> last_name;
    // full_name.append(" " + last_name);

    // full_name.shrink_to_fit(); // capacity is now equal to size

    // std::cout << full_name << '\n'; // Albus P. Dumbledore

    //==============
    //======== 30
    //==============

    // std::array<int, 5> a1{1, 2, 3, 4, 5};              // [1, 2, 3, 4, 5]
    // std::array<int, 10> a2{1, 2, 3, 4, 5, 6, 7, 8, 9}; // [1, 2, 3, 4, 5, 6, 7, 8, 9]

    // std::cout << sizeof(a1) << '\n';
    // std::cout << sizeof(a2) << '\n';

    //==============
    //======== 31
    //==============

    // // C Array
    // // zero initialization
    // int a1[2]{}; // [0, 0]
    // // explicit initialization
    // int a2[2]{1, 2};
    // // partial initialization
    // int a3[2]{1}; // [1, 0]
    // // size inference
    // int a4[]{1, 2};

    // // fill with explicit initialization
    // // up to but not including
    // int a5[3]{};              // [0, 0, 0]
    // std::fill(a5, a5 + 2, 3); //[3, 3, 0]

    // // fill with partial initialization
    // // up to but not including
    // int a6[3]{};              // [0, 0, 0]
    // std::fill(a6, a6 + 2, 1); //[1, 1, 0]
    //==============

    // // C++ Array

    // // zero initialization
    // std::array<int, 2> a1{}; // [0, 0]
    // // explicit initialization
    // std::array<int, 2> a2 = {1, 2};
    // // partial initialization
    // std::array<int, 2> a3 = {1}; // [1, 0]
    // //@\emphIII{no size inference}@

    // // fill with explicit initialization
    // // up to but not including
    // std::array<int, 2> a4;
    // std::fill(a4.begin(), a4.end(), 3); //[3, 3]

    // // fill with partial initialization
    // // up to but not including
    // std::array<int, 3> a5{};
    // std::fill(a5.begin(), a5.begin() + 2, 1); //[1, 1, 0]

    //==============
    //======== 32
    //==============

    // int my_array[5]{1, 2, 3, 4, 5};
    // std::cout << my_array << '\n'; // @

    // int *ptr = my_array;
    // std::cout << ptr << '\n'; // @
    // // first element using pointer
    // int first_number = *ptr;
    // std::cout << first_number << '\n'; // 1
    // // second element using pointer arithmetic
    // int second_number = *(ptr + 1);
    // std::cout << second_number << '\n'; // 2

    // for (size_t i{0}; i < std::size(my_array); ++i)
    // {
    //     std::cout << my_array[i] << ' ';
    // }
    // std::cout << '\n';

    //==============
    //======== 33
    //==============

    // int my_array[5]{1, 2, 3, 4, 5};
    // int *ptr = my_array;

    // for (size_t i{0}; i < std::size(my_array); ++i)
    // {
    //     // write code here
    // }

    //==============
    //======== 34
    //==============
    // constexpr size_t length1{3};
    // size_t length2{3};

    // // C++ array
    // std::array<int, 3> cpp_array1{};       // ok: 3 is a compile-time constant
    // std::array<int, length1> cpp_array2{}; // ok: length1 is a compile-time constant
    // std::array<int, length2> cpp_array3{}; // Error: length2 is not a compile-time constant

    // // C array
    // int c_array1[3]{};       // ok: 3 is a compile-time constant
    // int c_array2[length1]{}; // ok: length1 is a compile-time constant
    // int c_array3[length2]{}; // Error: length2 is not a compile-time constant

    //==============
    //======== 35
    //==============
    // constexpr size_t length{3};

    // // C array
    // int a1[length]{1, 2, 3};
    // std::cout << a1[0] << '\n'; // 1
    // a1[0] = 10;                 // [10, 2, 3]

    // // regular for loop
    // for (size_t i{0}; i < length; ++i)
    //     std::cout << a1[i] << ' ';
    // std::cout << '\n';

    // // range-based for loop
    // for (const auto &item : a1)
    //     std::cout << item << ' ';
    // std::cout << '\n';

    // // C++ array
    // std::array<int, length> a2{10, 20, 30};
    // std::cout << a2.at(0) << '\n';   // 10
    // std::cout << a2.empty() << '\n'; // 0 (false)
    // std::cout << a2.size() << '\n';  // 3
    // std::cout << a2.front() << '\n'; // 10
    // std::cout << a2.back() << '\n';  // 30
    // a2.at(0) = 100;                  // [100, 20, 30]

    // // regular for loop
    // for (size_t i{0}; i < length; ++i)
    //     std::cout << a2.at(i) << ' ';
    // std::cout << '\n';

    // // range-based for loop
    // for (const auto &item : a2)
    //     std::cout << item << ' ';
    // std::cout << '\n';

    // a2.fill(0); // [0, 0, 0]

    //==============
    //======== 36
    //==============
    // int numbers[2][3]{
    // {1, 2, 3},  // row 0
    // {4, 5, 6}   // row 1
    //==============
    // std::array<std::array<int, 3>, 2> numbers{{
    //     // note the double braces
    //     {1, 2, 3}, // row 0
    //     {4, 5, 6}  // row 1
    // }};

    //==============
    //======== 37
    //==============
    // int numbers[3][2][3]{
    //     {{1, 2, 3}, {4, 5, 6}},
    //     {{7, 8, 9}, {10, 11, 12}},
    //     {{13, 14, 15}, {16, 17, 18}}
    // };
    //==============
    // std::array<std::array<std::array<int, 3>, 2>, 3> numbers{{{{{1, 2, 3}, {4, 5, 6}}},
    //                                                           {{{7, 8, 9}, {10, 11, 12}}},
    //                                                           {{{13, 14, 15}, {16, 17, 18}}}}};

    //==============
    //======== 38
    //==============
    // int numbers[2][3]{
    //     {1, 2, 3},
    //     {4, 5, 6}};
    // numbers[1][1] = 100;
    // std::cout << numbers[1][1] << '\n';

    // //==============

    // std::array<std::array<int, 3>, 2> numbers{{{1, 2, 3},
    //                                            {4, 5, 6}}};

    // numbers.at(1).at(1) = 100;
    // std::cout << numbers.at(1).at(1) << '\n';

    //==============
    //======== 39
    //==============
    // std::vector<int> vec1 = {1, 2, 3};
    // std::vector<int> vec2 = {1, 2, 3, 4, 5};

    // std::cout << sizeof(vec1) << '\n';
    // std::cout << sizeof(vec2) << '\n';

    //==============
    //======== 40
    //==============
    // std::vector<int> my_vector{1, 2, 3, 4};
    // std::cout << my_vector.capacity() << '\n';
    // my_vector.push_back(5);
    // std::cout << my_vector.capacity() << '\n';

    //==============
    //======== 41
    //==============
    // std::vector<int> vec = {1, 2, 3, 4, 5};

    // std::cout << "Initial size: " << vec.size() << '\n';
    // std::cout << "Initial capacity: " << vec.capacity() << '\n';

    // // Reserve space
    // vec.reserve(20);
    // std::cout << "Size: " << vec.size() << '\n';
    // std::cout << "Capacity: " << vec.capacity() << '\n';

    // // Add more elements to the vector
    // for (auto i{0}; i < 60; ++i)
    //     vec.push_back(i);

    // // Display updated size and capacity
    // std::cout << "Size: " << vec.size() << '\n';
    // std::cout << "Capacity: " << vec.capacity() << '\n';

    // // Shrink the vector to fit its size
    // vec.shrink_to_fit();
    // std::cout << "Size: " << vec.size() << '\n';
    // std::cout << "Capacity: " << vec.capacity() << '\n';

    //==============
    //======== 42
    //==============
    // std::vector<int> v1{-1, 3, 5};  // initialization with explicit values
    // std::vector<int> v2{};          // zero initialization
    // std::cout << v2.size() << '\n'; // ???
    // std::cout << v2.at(0) << '\n';  // ???
    // v2 = v1;                        // copy items of v1 into v2
    // auto v3{v1};                    // initialization from an existing vector

    //==============
    //======== 43
    //==============
    // std::vector<int> numbers{-1, 3, 5, -9}; // initialization with 4 items

    // std::cout << numbers.front() << '\n'; // -1
    // std::cout << numbers.back() << '\n';  // -9

    // // indexing operator (no bounds check)
    // numbers[0] = -2;                 // [-2, 3, 5, -9]
    // std::cout << numbers[0] << '\n'; // -2
    // // at() method
    // numbers.at(0) = 1;                  // [1, 3, 5, -9]
    // std::cout << numbers.at(3) << '\n'; // 4th item - bounds check

    // // regular for loop
    // for (size_t i{0}; i < numbers.size(); ++i)
    //     numbers[i] = 0;
    // std::cout << '\n';

    // // ranged-base for loop
    // for (auto &item : numbers)
    //     item = 1;
    // std::cout << '\n';

    // numbers.assign({1, 2, 3, 4}); // replace entire content with new values

    //==============
    //======== 44
    //==============
    // std::vector<int> my_vector;

    // // Add elements to the vector using push_back()
    // my_vector.push_back(10);
    // my_vector.push_back(20);
    // my_vector.push_back(30);

    // // Output the elements of the vector
    // std::cout << "Elements in my_vector: ";
    // for (size_t i{0}; i < my_vector.size(); ++i)
    // {
    //     std::cout << my_vector.at(i) << " ";
    // }
    // std::cout << '\n';

    //==============
    //======== 45
    //==============
    // // Declare a vector of pairs of integers
    // std::vector<std::pair<int, int>> pair_vector;

    // // Add elements to the vector using emplace_back()
    // pair_vector.emplace_back(1, 2);
    // pair_vector.emplace_back(3, 4);
    // pair_vector.emplace_back(5, 6);

    // // Output the elements of the vector
    // for (const auto &p : pair_vector)
    // {
    //     std::cout << "First: " << p.first << ", Second: " << p.second << '\n';
    // }

    //==============
    //======== 46
    //==============
    // // Declare and initialize a vector of integers
    // std::vector<int> my_vector = {1, 2, 3, 5, 6};

    // // Insert a single element at the 4th position (index 3)
    // my_vector.insert(my_vector.begin() + 3, 4); // 1 2 3 4 5 6

    // // Insert multiple elements at the end
    // my_vector.insert(my_vector.end(), {7, 8, 9}); // 1 2 3 4 5 6 7 8 9

    // // Insert multiple copies of the same value
    // my_vector.insert(my_vector.begin(), 3, 0); // 0 0 0 1 2 3 4 5 6 7 8 9

    //==============
    //======== 47
    //==============
    // std::vector<std::pair<int, std::string>> vec;

    // // Use emplace() to insert elements
    // vec.emplace(vec.begin(), 1, "one");
    // vec.emplace(vec.end(), 3, "three");
    // vec.emplace(vec.end(), 4, "four");
    // vec.emplace(vec.begin() + 1, 2, "two");

    //==============
    //======== 48
    //==============
    // // Declare and initialize a vector of integers
    // std::vector<int> vec = {1, 2, 3, 4, 5};

    // // Use pop_back() to remove the last element
    // vec.pop_back();

    // // Output the elements of the vector after pop_back()
    // std::cout << "Elements in vec after pop_back: ";
    // for (const int &value : vec)
    // {
    //     std::cout << value << " ";
    // }
    // std::cout << '\n';

    //==============
    //======== 49
    //==============
    // // Declare and initialize a vector of integers
    // std::vector<int> vec = {1, 2, 3, 4, 5};

    // // Remove the element at the 2nd position (index 1)
    // vec.erase(vec.begin() + 1);

    // // Remove a range of elements (2nd and 3rd)
    // vec.erase(vec.begin() + 1, vec.begin() + 3);

    //==============
    //======== 50
    //==============
    // // Declare and initialize a vector of integers
    // std::vector<int> my_vector = {1, 2, 3, 4, 5};

    // // Clear all elements from the vector
    // my_vector.clear();

    // // Output the size of the vector after clear
    // std::cout << "Size of my_vector after clear: " << my_vector.size() << '\n';

    // // Check if the vector is empty
    // if (my_vector.empty())
    // {
    //     std::cout << "my_vector is now empty.\n";
    // }
    // else
    // {
    //     std::cout << "my_vector is not empty.\n";
    // }
}
