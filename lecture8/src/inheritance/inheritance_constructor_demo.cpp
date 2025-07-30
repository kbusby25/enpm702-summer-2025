

#include <iostream>

// ==========================================
// </17>
// ==========================================
// BASE CLASS
class Base {
public:
  Base(int base_value = 50) : base_member_{base_value} { /*empty body*/ }

protected:
  int base_member_;
}; // class Base

// DERIVED CLASS
class Derived : public Base {
public:
  Derived(double derived_value) : derived_member_{derived_value} {
    std::cout << "base_member_:" << base_member_ << '\n';
    std::cout << "derived_member_:" << derived_member_ << '\n';
  }

private:
  double derived_member_;
}; // class Derived

// MAIN
int main() { Derived derived(20.5); }

// // ==========================================
// // </18>
// // ==========================================
// // BASE CLASS
// class Base {
// public:
//   Base(int base_value = 50) : base_member_{base_value} { /*empty body*/ }

// protected:
//   int base_member_;
// }; // class Base

// // DERIVED CLASS
// class Derived : public Base {
// public:
//   Derived(double derived_value, int base_value) :
//   derived_member_{derived_value}, base_member_{base_value} {
//     std::cout << "base_member_:" << base_member_ << '\n';
//     std::cout << "derived_member_:" << derived_member_ << '\n';
//   }

// private:
//   double derived_member_;
// }; // class Derived

// // MAIN
// int main() { Derived derived(20.5, 10); }

// // ==========================================
// // </19>
// // ==========================================
// // BASE CLASS
// class Base {
// public:
//   Base(int base_value = 50) : base_member_{base_value} {
//     std::cout << "Base constructor called: " << base_member_ << '\n';
//   }

// protected:
//   int base_member_;
// }; // class Base

// // DERIVED CLASS
// class Derived : public Base {
// public:
//   Derived(double derived_value, int base_value)
//       : derived_member_{derived_value} {
//     base_member_ = base_value;
//     std::cout << "base_member_:" << base_member_ << '\n';
//     std::cout << "derived_member_:" << derived_member_ << '\n';
//   }

// private:
//   double derived_member_;
// }; // class Derived

// // MAIN
// int main() { Derived derived(20.5, 10); }

// // ==========================================
// // </20>
// // ==========================================
// // BASE CLASS
// class Base {
// public:
//   Base(int base_value = 50) : base_member_{base_value} {
//     std::cout << "Base constructor called: " << base_member_ << '\n';
//   }

// protected:
//   int base_member_;
// }; // class Base

// // DERIVED CLASS
// class Derived : public Base {
// public:
//   Derived(double derived_value, int base_value)
//       : Base(base_value), derived_member_{derived_value} {
//     std::cout << "base_member_:" << base_member_ << '\n';
//     std::cout << "derived_member_:" << derived_member_ << '\n';
//   }

// private:
//   double derived_member_;
// }; // class Derived

// // MAIN
// int main() { Derived derived(20.5, 10); }