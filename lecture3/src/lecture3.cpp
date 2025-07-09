/**
 * @file lecture3.cpp
 * @author Zeid Kootbally (zeidk@umd.edu)
 * @brief Code snippets for lecture 3 on normal pointers
 * @version 0.1
 * @date 2025-06-17
 *
 * @copyright Copyright (c) 2025
 *
 */

#include <iostream>
#include <iomanip>
#include <typeinfo> // needed for typeid

int main()
{
    //     // //==============
    //     // //======== 1
    //     // //==============
    //     // int a{10};
    //     // int *p{&a};
    //     // std::cout << &a << '\n';
    //     // std::cout << p << '\n';

    //     // //==============
    //     // //======== 2
    //     // //==============
    //     // int a{10};
    //     // std::cout << typeid(&a).name() << '\n';
    //     // // //==============
    //     // int *p;
    //     // std::cout << typeid(p).name() << '\n';

    //     // //==============
    //     // //======== 3
    //     // //==============
    //     // int *p1{nullptr}; // nullptr literal (from C++)
    //     // int *p2{NULL};    // NULL macro (from C)
    //     // int *p3{0};       // value initialization
    //     // int *p4{};        // zero initialization
    //     // //==============
    //     // int a{3};
    //     // int *p1{&a};
    //     // int *p2{nullptr};
    //     // if (p1 != p2)
    //     //     std::cout << "p1 is not null\n";
    //     // else
    //     //     std::cout << "p1 is null\n";

    //     // //==============
    //     // //======== 4
    //     // //==============
    //     // int a{10};
    //     // std::cout << &a << '\n';    // 0x7fffffffdb3c
    //     // std::cout << *(&a) << '\n'; // What is the output?

    //     // int *p{&a};
    //     // std::cout << p << '\n';  // 0x7fffffffdb3c
    //     // std::cout << *p << '\n'; // What is the output?

    //     // //==============
    //     // //======== 5
    //     // //==============
    //     // int a{10};
    //     // int *p{&a};

    //     // // Modify the value of a through p
    //     // *p = 20;

    //     // std::cout << a << '\n';  // 20
    //     // std::cout << *p << '\n'; // 20

    //     // //==============
    //     // //======== 6
    //     // //==============

    //     // int a{10};
    //     // int *p{&a};

    //     // *p *= 2;

    //     // std::cout << a << '\n';
    //     // std::cout << *p << '\n';
    //     // //==============
    //     // int a{2};
    //     // int *p{&a};
    //     // int **q{&p};
    //     // int ***r{&q};

    //     // std::cout << *p << '\n';
    //     // std::cout << **q << '\n';
    //     // std::cout << ***r << '\n';

    //     // //==============
    //     // //======== 7
    //     // //==============
    //     // int i{10};
    //     // double d{10.0};
    //     // float f{10.0f};
    //     // char c{'a'};

    //     // int *p{&i};
    //     // double *q{&d};
    //     // float *r{&f};
    //     // char *s{&c};

    //     // std::cout << sizeof(p) << '\n';
    //     // std::cout << sizeof(q) << '\n';
    //     // std::cout << sizeof(r) << '\n';
    //     // std::cout << sizeof(s) << '\n';

    //     // //==============
    //     // //======== 8
    //     // //==============
    //     // int a{5};
    //     // double b{2.5};
    //     // int *p{nullptr}; // OK
    //     // p = &a;          // OK
    //     // p = &b;          // Error
    //     // //==============
    //     // int a{10};
    //     // int *p{&a};
    //     // std::cout << *p << '\n';

    //     // //==============
    //     // //======== 9
    //     // //==============
    //     // int a{5};
    //     // int b{5};

    //     // int *p1{&a}; // p1 points to a
    //     // int *p2{&b}; // p2 points to b
    //     // int *p3{&a}; // p3 points to a

    //     // std::cout << std::boolalpha; // print bools as true/false
    //     // std::cout << (p1 == p2) << '\n';
    //     // std::cout << (p1 == p3) << '\n';

    //     // //==============
    //     // //======== 10
    //     // //==============
    //     // int a{10};
    //     // int b{20};

    //     // int *p1{&a};
    //     // int *p2{&b};
    //     // int *p3{&a};

    //     // std::cout << std::boolalpha; // print bools as true/false
    //     // std::cout << (*p1 == *p2) << '\n';
    //     // std::cout << (*p1 == *p3) << '\n';
    //     // std::cout << (*p1 > *p2) << '\n';
    //     // std::cout << (*p1 >= *p2) << '\n';
    //     // std::cout << (*p1 < *p2) << '\n';
    //     // std::cout << (*p1 <= *p2) << '\n';
    //     // std::cout << (*p1 != *p2) << '\n';

    //     // //==============
    //     // //======== 11
    //     // //==============
    //     // int a{10};
    //     // int b{20};

    //     // int *p1{&a};
    //     // int *p2{&b};
    //     // int *p3{&a};

    //     // // write your code here

    //     //==============
    //     //======== 12
    //     //==============
    //     // int a{2};
    //     // int b{3};

    //     // /* pointer to const */
    //     // const int *p1;
    //     // p1 = &a; // OK
    //     // p1 = &b; // OK
    //     // *p1 = 3; // Error

    //     // /* const pointer */
    //     // int *const p2{&a};
    //     // *p2 = 3; // OK
    //     // p2 = &b; // Error

    //     // /* const pointer to const */
    //     // const int *const p3{&a};
    //     // *p3 = 3; // Error
    //     // p3 = &b; // Error

    //     // //==============
    //     // //======== 13
    //     // //==============
    //     // int *p; // p is a wild pointer. It holds a garbage memory address.

    //     // // The following line is UNDEFINED BEHAVIOR.
    //     // // We are attempting to write the value 100 to an unknown memory address.
    //     // *p = 100;
    //     // // The program might crash here, or it might seem to continue,
    //     // // having corrupted some unknown part of memory.
    //     // std::cout << "This line may or may not be reached.\n";

    //     // //==============
    //     // //======== 14
    //     // //==============
    //     // int *p{new int{15}};
    //     // std::cout << p << '\n'; // 0x55555556b2b0
    //     // delete p;
    //     // std::cout << p << '\n';  // 0x55555556b2b0
    //     // std::cout << *p << '\n'; // UB

    //     // //==============
    //     // //======== 15
    //     // //==============
    //     // int *p{new int{5}}; // allocate and point to data on the heap
    //     // delete p;           // free the heap memory
    //     // int a{2};           // create a is on the stack
    //     // p = &a;             // point to data on the stack
    //     // p = new int{3};     // allocate and point to data on the heap
    //     // delete p;           // free the heap memory
    //     // p = nullptr;        // null pointer

    //     // //==============
    //     // //======== 16
    //     // //==============
    //     // int a{3};
    //     // int *p{&a};
    //     // delete p; // UB

    //     // //==============
    //     // //======== 17
    //     // //==============
    //     // int *p{nullptr};
    //     // delete p; // safe to delete a null pointer

    //     // //==============
    //     // //======== 18
    //     // //==============
    //     // int *p{new int{2}};
    //     // delete p;                // p is dangling
    //     // *p = 5;                  // UB
    //     // std::cout << *p << '\n'; // UB

    // //==============
    // //======== 19
    // //==============
    // int *p = nullptr;

    // { // Inner scope starts
    //     int inner_variable{5};
    //     p = &inner_variable;
    //     std::cout << "Inside scope: " << *p << '\n';
    // } // Inner scope ends, `inner_variable` is destroyed.
    // // UB: Accessing memory that is out of scope.
    // std::cout << "Outside scope: " << *p << '\n';

    // ==============
    // ======== 20
    // ==============
    // for (int i{0}; i < 100000; ++i)
    // {
    //     // In each iteration, we allocate a new integer.
    //     // But we never deallocate the memory from the previous iteration.
    //     int *p{new int(i)};
    // }

    // //==============
    // //======== 21
    // //==============
    // int *p1{new int{2}};
    // int *p2{p1};

    // delete p1;
    // p1 = nullptr;

    // delete p2; // UB

    //==============
    //======== 22
    //==============

    // int *p{nullptr};
    // std::cout << *p << '\n'; // UB

    //============

    // int *p{nullptr};
    // if (p)
    // {                            // if p is not null
    //     std::cout << *p << '\n'; // it's ok to derefence it
    // }
    // else
    // { // if p is null
    //     // print error, assign pointer, do nothing at all, etc
    //     // but do not derefence it
    //     std::cout << "pointer is null\n";
    // }

    //==============
    //======== 23
    //==============
    // int &ref{};
    // //--
    // int a{10};
    // int &ref{a};              // ref is a reference to a
    // ref = 20;                 // a is now 20
    // std::cout << a << '\n';   // 20
    // a = 30;                   // ref is now 30
    // std::cout << ref << '\n'; // 30
    // //--
    // std::cout << &a << '\n';   // 0x7fffffffdadc
    // std::cout << &ref << '\n'; // 0x7fffffffdadc
    // //--
    // int b{3};
    // ref = b; // This assigns the value of b to a

    // //==============
    // //======== 24
    // //==============
    // int *p1{new int(10)};
    // int *p2{new int(20)};
    // int &ref{*p1};

    // ref = *p2;
    // *p2 = 30;
    // p1 = new int(40);
    // delete p2;
    // *p1 = *p2;
    // int *p3{p2};
    // ref = 50;
    // delete p3;
}
