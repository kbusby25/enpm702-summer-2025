/**
 * @file lecture6.cpp
 * @author Zeid Kootbally (zeidk@umd.edu)
 * @brief Code for lecture 6 on smart pointers
 * @version 1.0
 * @date 2025-07-06
 *
 * @copyright Copyright (c) 2025
 *
 */

#include "utils.hpp"
#include <iomanip>
#include <iostream>
#include <memory>
#include <vector>
#include <cassert> // for assert()

int main() {
    //======== 1
    //==============
    // std::unique_ptr<int> u = std::make_unique<int>(10);
    // std::unique_ptr<int> v{u};  // Error

    //======== 2
    //==============
    // {
    //     // Create managed resource on heap
    //     auto u = std::make_unique<int>(10);
    //     std::cout << *u << '\n';  // 10 (dereference to access value)
    //     *u = 20;                  // modify the managed resource
    //     std::cout << *u << '\n';  // 20
    //     std::cout << u << '\n';   // Compilation error: no operator<< for unique_ptr
    // }  // u destructor automatically calls delete on managed resource

    //======== 3
    //==============
    // Create managed resource on heap
    // auto u = std::make_unique<int>(10);
    // if (u) {  // implicit conversion to bool (checks if not null)
    //     std::cout << "Value at " << u.get() << " is " << *u << '\n';
    //     }
    //==============

    // Create managed resource on heap
    // auto u = std::make_unique<int>(10);
    // int* raw_ptr{ u.get() }; // extract raw pointer for observation
    // if (raw_ptr) { // null-check the raw pointer
    //     std::cout << "Value at " << raw_ptr << " is " << *raw_ptr << '\n';
    //     }

    //======== 4
    //==============
    // auto u = std::make_unique<int>(10);
    // auto ptr = u.release(); // transfer ownership to ptr
    // std::cout << *ptr << '\n'; // 10
    // assert(u.get() == nullptr); // u no longer owns the resource
    // assert(u == nullptr); // implicit bool conversion check
    // delete ptr; // Mandatory: prevent memory leak

    //======== 5
    //==============
    // auto u = std::make_unique<int>(10);
    // u.release();

    //======== 6
    //==============
    // auto u = std::make_unique<int>(42);

    // // Transfer ownership to raw pointer for legacy interface
    // int* ptr{ u.release() };

    // // Verify ownership transfer
    // assert(u == nullptr); // u no longer owns resource

    // // Pass to legacy system that expects raw pointer ownership
    // legacy_function(ptr); // ptr now responsible for deletion

    //======== 7
    //==============
    // auto u1 = std::make_unique<int>(10);
    // int* ptr{ u1.release() };
    // std::unique_ptr<int> u2(ptr); // u2 assumes ownership

    //======== 8
    //==============
    // auto u = std::make_unique<int>(10);
    // u.reset(); // destroy managed resource, set to nullptr
    // assert(u.get() == nullptr); // verification: u is now null

    //======== 9
   //==============
    // auto u = std::make_unique<int>(10);
    // u.reset(new int(20)); // destroy old resource, manage new one

        //======== 10
   //==============
    // auto u1 = std::make_unique<int>(10);
    // auto u2 = std::make_unique<int>(20);
    // u1.swap(u2);

    //======== 11
    //==============
    // auto u = std::make_unique<int>(10);
    // display(u);

    //======== 12
    //==============
    // auto u = std::make_unique<int>(10);
    // display(std::move(u)); // Transfer ownership to function
    // // u is now nullptr - ownership transferred

    //======== 13
    //==============
    // // Create managed resource on heap
    // auto u1 = std::make_unique<int>(10);
    // std::cout << "u1: " << u1.get() << '\n';  // @1

    // // Transfer ownership using move constructor
    // auto u2{ std::move(u1) }; // u1 transfers ownership to u2
    // std::cout << "u2: " << u2.get() << '\n'; // @1 (same address)
    // assert(u1 == nullptr);  // u1 is now empty

    // // u1 can be reused for new resource management
    // u1.reset(new int{ 20 });
    // std::cout << u1.get() << '\n';  // @2 (different address)

    //======== 14
    //==============
    // auto u = std::make_unique<int>(10); // Create managed resource
    // std::cout << "*u: " << *u << '\n';        // 10
    // std::cout << "u: " << u.get() << '\n';    // @1
    // reseat(u); // u will be modified to point to new resource
    // std::cout << "*u: " << *u << '\n';       // 20
    // std::cout << "u: " << u.get() << '\n';   // @2

    //======== 15
    //==============
    // auto u{ create_resource() };
    // std::cout << *u << '\n';       // 10
    // std::cout << &u << '\n';       // @1 (same address due to optimization)

    //======== 16
    //==============
    // auto s1 = std::make_shared<int>(10);
    // auto s2{ s1 };
    // auto s3 = s2;

    //======== 17
    //==============
    // auto s1 = std::make_shared<int>(10);
    // std::cout << s1.use_count() << '\n';

    // auto s2{ s1 };
    // std::cout << s1.use_count() << ' ';
    // std::cout << s2.use_count() << '\n';

    // auto s3 = s2;
    // std::cout << s1.use_count() << ' ';
    // std::cout << s2.use_count() << ' ';
    // std::cout << s3.use_count() << '\n';

    // s1.reset();
    // std::cout << s1.use_count() << ' ';
    // std::cout << s2.use_count() << ' ';
    // std::cout << s3.use_count() << '\n';

    // s1.swap(s2);
    // std::cout << s1.use_count() << ' ';
    // std::cout << s2.use_count() << ' ';
    // std::cout << s3.use_count() << '\n';

    // s2.reset(new int(20));
    // std::cout << s1.use_count() << ' ';
    // std::cout << s2.use_count() << ' ';
    // std::cout << s3.use_count() << '\n';

    //======== 18
    //==============
    // auto original = std::make_shared<int>(10);
    // std::cout << original.use_count() << '\n';   // 1
    // sink_shared_ptr(original); // Pass by value creates copy
    // std::cout << original.use_count() << '\n';   // 1 (copy destroyed after function)

    //======== 19
    //==============
    // auto original = std::make_shared<int>(10);
    // std::cout << original.use_count() << '\n';   // 1
    // reseat_shared_ptr(original); // Pass by reference
    // std::cout << original.use_count() << '\n';   // 1 (no copy made)

    //======== 20
    //==============
    // auto result{ create_shared_resource() };
    // std::cout << &result << '\n'; // @1 (same address due to RVO)

    //======== 21
    //==============
    // auto s = std::make_shared<int>(10);
    // // Create weak_ptr from s
    // std::weak_ptr<int> w1{ s };
    // // Create weak_ptr from another weak_ptr
    // std::weak_ptr<int> w2{ w1 };

    //======== 22
    //==============
    // auto s = std::make_shared<int>(10);
    // // Create weak_ptr from shared_ptr
    // std::weak_ptr<int> w{ s };

    // std::cout << *w << '\n';        // Error: No operator*
    // std::cout << w.get() << '\n';   // Error: No get() method

    //======== 23
    //==============
// // Declare empty weak pointer
//     std::weak_ptr<int> weak_observer;
//     {
//     auto shared_resource = std::make_shared<int>(10);
//     weak_observer = shared_resource;  // weak_observer now observes the resource
//     if (auto locked_ptr = weak_observer.lock(); locked_ptr)
//         std::cout << "Resource value: " << *locked_ptr << "\n";
//     else
//         std::cout << "Unable to access resource\n";
//     }  // shared_resource destroyed, resource deallocated

//     if (auto locked_ptr = weak_observer.lock(); locked_ptr)
//         std::cout << "Resource value: " << *locked_ptr << "\n";
//     else
//         std::cout << "Unable to access resource\n";

//======== 24
    //==============
// // Declare empty weak pointer
//     std::weak_ptr<int> weak_observer;
//     {
//     auto shared_resource = std::make_shared<int>(10);
//     weak_observer = shared_resource;  // weak_observer now observes the resource
//     if (!weak_observer.expired())
//         std::cout << "Resource is still valid\n";
//     else
//         std::cout << "Resource has been destroyed\n";
//     }  // shared_resource destroyed, resource deallocated

//     if (!weak_observer.expired())
//         std::cout << "Resource is still valid\n";
//     else
//         std::cout << "Resource has been destroyed\n";

//======== 25
    //==============
    // auto s = std::make_shared<int>(10);
    // std::weak_ptr<int> w = s;
    // s.reset();
    // w.reset();

    }// end main()