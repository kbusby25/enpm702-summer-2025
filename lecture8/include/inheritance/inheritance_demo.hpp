/**
 * @file inheritance_demo.hpp
 * @brief Simple inheritance example demonstrating access specifiers
 * @author zeidk (zeidk@umd.edu)
 * @version 2.0
 * @date 2025-07-27
 */

#pragma once

#include <string>
#include <iostream>

/**
 * @brief Base class demonstrating different access levels
 */
class Base {
private:
    int private_data_;  ///< Only Base can access

protected:
    std::string protected_data_;  ///< Base and Derived can access

public:
    /**
     * @brief Constructor
     */
    Base(int private_val, const std::string& protected_val);

    /**
     * @brief Public method - everyone can access
     */
    void public_method();

    /**
     * @brief Virtual destructor
     */
    virtual ~Base() = default;

protected:
    /**
     * @brief Protected method - Base and Derived can access
     */
    void protected_method();

private:
    /**
     * @brief Private method - only Base can access
     */
    void private_method();
};

/**
 * @brief Derived class inheriting from Base
 */
class Derived : public Base {
private:
    double derived_data_;  ///< Only Derived can access

public:
    /**
     * @brief Constructor
     */
    Derived(int base_private, const std::string& base_protected, double derived_val);

    /**
     * @brief Derived-specific method
     */
    void derived_method();

    /**
     * @brief Show what Derived can access from Base
     */
    void show_access();
};