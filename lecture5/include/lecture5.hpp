/**
 * @brief Source code for lecture 5 on functions. This file contains only function declarations.
 * 
 */

//======== 2
// void print_hello();
// void print_world();

//======== 3
// void print_hello();
// void print_world();

//======== 4
// void prompt_user();
// void print_number(int number);

//======== 5
// void add_ten(int x);

//======== 6
// void add_ten(int &x);

//======== 7
// Exercise 4

//======== 8
// void push_ten(std::vector<int> &v);

//======== 9
// void print_vector(const std::vector<int> &v);

//======== 10
// void add_ten(int *p);

//======== 11
// void count_calls();

//======== 12
// Exercise #5

//======== 13
// std::vector<int> create_vector();

//======== 14
// std::vector<int> create_vector();

//======== 15
// std::vector<int> conditional_return(bool flag);
// std::vector<int> multiple_paths(int choice);

//======== 16
// std::vector<int> create_vector();

//======== 17
// int &get_element(std::vector<int> &vec, int index);

//======== 18
// const int &get_element(std::vector<int> &vec, int index);

//======== 19
// /**
//  * @brief Function to return a reference to a static variable
//  *
//  * @return int& Returned reference to an integer
//  */
// int &f();

//======== 20
// auto add(int a, int b);

//======== 21
// int truncate_double();
// bool to_bool();
// char to_char();

//======== 22
// int add(int a, int b);
// double add(double a, double b);
// double add(int a, double b);
// double add(double a, int b);
// double add(double a, double b, double c);

//======== 23
// double return_value(double a);
// int return_value(double a);

//======== 24
// int add(int a, int b);
// int add(int a, float b);

// //========
// int add(int a, int b);
// int add(int a, float b);
// int add(int a, double b);

//======== 25
// void add(int a, int b = 0, int c = 0); // Declaration with defaults

//======== 26
// // COMPILATION ERROR: These are considered identical signatures!
// void func(int a, int b);     // Signature: func(int, int)
// void func(int a, int b = 5); // Signature: func(int, int) - defaults ignored!

//======== 27
void f(int &x, int y, int z);
int g(int a, int b);

//======== 28
// long long factorial(int n);