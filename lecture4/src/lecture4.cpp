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

    //==============
    //======== 11
    //==============
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
}
