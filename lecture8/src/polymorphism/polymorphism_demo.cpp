#include <iostream>

// ==========================================
// </18>
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

private:
  double derived_member_;
}; // class Derived

// MAIN
int main() {
  Derived derived(20.5, 10);
  derived.test();
}

// // ==========================================
// // </19>
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
