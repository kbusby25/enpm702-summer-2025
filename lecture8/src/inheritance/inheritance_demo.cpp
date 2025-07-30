/**
 * @file inheritance_demo.cpp
 * @brief Implementation of inheritance example demonstrating access specifiers
 * @author zeidk (zeidk@umd.edu)
 * @version 2.0
 * @date 2025-07-27
 */

#include "inheritance/inheritance_demo.hpp"

// ==========================================
// BASE CLASS IMPLEMENTATION
// ==========================================

Base::Base(int private_val, const std::string& protected_val)
    : private_data_(private_val), protected_data_(protected_val) {
    std::cout << "Base constructor called with private_data: " << private_data_ 
              << ", protected_data: " << protected_data_ << "\n";
}

void Base::public_method() {
    std::cout << "Base::public_method() called\n";
    std::cout << "  Can access private_data_: " << private_data_ << "\n";
    std::cout << "  Can access protected_data_: " << protected_data_ << "\n";
    
    // Base can call its own private and protected methods
    private_method();
    protected_method();
}

void Base::protected_method() {
    std::cout << "Base::protected_method() called\n";
    std::cout << "  Accessing private_data_ from protected method: " << private_data_ << "\n";
}

void Base::private_method() {
    std::cout << "Base::private_method() called\n";
    std::cout << "  Only Base class can call this method\n";
}

// ==========================================
// DERIVED CLASS IMPLEMENTATION
// ==========================================

Derived::Derived(int base_private, const std::string& base_protected, double derived_val)
    : Base(base_private, base_protected), derived_data_{derived_val} {
    std::cout << "Derived constructor called with derived_data: " << derived_data_ << "\n";
}

void Derived::derived_method() {
    std::cout << "Derived::derived_method() called\n";
    std::cout << "  Can access derived_data_: " << derived_data_ << "\n";
    
    // Derived can access Base's protected members
    std::cout << "  Can access Base's protected_data_: " << protected_data_ << "\n";
    
    // Derived can call Base's public and protected methods
    public_method();    // Inherited public method
    protected_method(); // Inherited protected method
    
    // private_method();    // ERROR: Cannot access Base's private method
    // private_data_;       // ERROR: Cannot access Base's private data
}

void Derived::show_access() {
    std::cout << "\n=== Derived::show_access() - Access Level Demonstration ===\n";
    
    std::cout << "✓ CAN ACCESS:\n";
    std::cout << "  - Own private data (derived_data_): " << derived_data_ << "\n";
    std::cout << "  - Base's protected data (protected_data_): " << protected_data_ << "\n";
    std::cout << "  - Base's public method: ";
    public_method();
    std::cout << "  - Base's protected method: ";
    protected_method();
    
    std::cout << "\n✗ CANNOT ACCESS (would cause compilation errors):\n";
    std::cout << "  - Base's private data (private_data_)\n";
    std::cout << "  - Base's private method (private_method())\n";
    
    // Uncomment these lines to see compilation errors:
    // std::cout << private_data_;  // ERROR: 'int Base::private_data_' is private
    // private_method();            // ERROR: 'void Base::private_method()' is private
}


// ==========================================
// MAIN
// ==========================================
int main() {
    std::cout << "=== Inheritance and Access Specifiers Demo ===\n\n";
    
    // Create objects
    std::cout << "1. Creating Base object:\n";
    Base base_obj(42, "blue");
    
    std::cout << "\n2. Creating Derived object:\n";
    Derived derived_obj(100, "red", 3.14);
    
    // Use Base object
    std::cout << "\n3. Calling Base object methods:\n";
    base_obj.public_method();
    // base_obj.private_method(); // Error
    // base_obj.protected_method(); // Error
    
    // Use Derived object
    std::cout << "\n4. Calling Derived object methods:\n";
    derived_obj.derived_method();
    
    // Demonstrate access levels
    std::cout << "\n5. Access level demonstration:\n";
    derived_obj.show_access();
    
    std::cout << "\n=== Demo Complete ===\n";
}