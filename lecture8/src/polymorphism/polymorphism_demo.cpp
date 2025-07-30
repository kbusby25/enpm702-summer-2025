#include <iostream>

// // ==========================================
// // </21>
// // ==========================================
// // BASE CLASS
// class Base {
// public:
//   Base(int base_value) : base_member_{base_value} {}
//   void test() { std::cout << "Base::test() called" << '\n'; }

// protected:
//   int base_member_;
// }; // class Base

// // DERIVED CLASS
// class Derived : public Base {
// public:
//   Derived(double derived_value, int base_value)
//       : Base(base_value), derived_member_{derived_value} {}

// private:
//   double derived_member_;
// }; // class Derived

// // MAIN
// int main() {
//   Derived derived(20.5, 10);
//   derived.test();
// }

// // ==========================================
// // </22>
// // ==========================================
// // BASE CLASS
// class Base {
// public:
//   Base(int base_value) : base_member_{base_value} {}
//   void test() { std::cout << "Base::test() called" << '\n'; }

// protected:
//   int base_member_;
// }; // class Base

// // DERIVED CLASS
// class Derived : public Base {
// public:
//   Derived(double derived_value, int base_value)
//       : Base(base_value), derived_member_{derived_value} {}
//   void test() { std::cout << "Derived::test() called" << '\n'; }

// private:
//   double derived_member_;
// }; // class Derived

// // MAIN
// int main() {
//   Derived derived(20.5, 10);
//   derived.test();
// }

// ==========================================
// </23>
// ==========================================
// BASE CLASS
class Base {
public:
  Base(int base_value) : base_member_{base_value} {}
  void test() { std::cout << "Base::test() called" << '\n'; }

protected:
  int base_member_;
}; // class Base

// DERIVED CLASS
class Derived : public Base {
public:
  Derived(double derived_value, int base_value)
      : Base(base_value), derived_member_{derived_value} {}
  void test() { std::cout << "Derived::test() called" << '\n'; }
  void test(int number) {
    std::cout << "Derived::test() called with: " << number << '\n';
  }

private:
  double derived_member_;
}; // class Derived

// MAIN
int main() {
  Derived derived(20.5, 10);
  derived.test();  // Derived::test() called
  derived.test(3); // Derived::test() called with: 3
}