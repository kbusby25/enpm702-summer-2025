#include <iostream>
#include <memory>

#include "robot.hpp"

int main() {
    std::cout << "=== Warehouse Robot Management System Demo ===\n";

    // Stack allocation example
    std::cout << "\n--- Stack Allocation Example ---\n";
    Robot stack_robot("R001", "GenericModel-Stack");
    std::cout << "Size of stack_robot: " << sizeof stack_robot << '\n';
    
    std::cout << "Robot ID: " << stack_robot.robot_id_ << '\n';
    std::cout << "Model: " << stack_robot.model_ << '\n';
    std::cout << "Task Description: " << stack_robot.get_task_description() << '\n';
    std::cout << "Initial Status: " << static_cast<int>(stack_robot.get_status()) << '\n';
    
    stack_robot.move();
    stack_robot.execute_task();
    std::cout << "Status after task: " << static_cast<int>(stack_robot.get_status()) << '\n';
    
    // Unique pointer allocation example
    std::cout << "\n--- Unique Pointer Allocation Example ---\n";
    auto heap_robot = std::make_unique<Robot>("R002", "GenericModel-Heap");
    std::cout << "Size of heap_robot: " << sizeof heap_robot << '\n';

    std::cout
        << "Robot ID: " << heap_robot->robot_id_ << '\n';
    std::cout << "Model: " << heap_robot->model_ << '\n';
    std::cout << "Task Description: " << heap_robot->get_task_description() << '\n';
    std::cout << "Initial Status: " << static_cast<int>(heap_robot->get_status()) << '\n';

    heap_robot->move();
    heap_robot->execute_task();
    heap_robot->update_position();
    std::cout << "Status after operations: " << static_cast<int>(heap_robot->get_status()) << '\n';

    // Direct member access demonstration (since all members are public)
    std::cout << "\n--- Direct Member Access Example ---\n";
    Robot direct_robot("R003", "GenericModel-Direct");

    // Direct access to public members
    std::cout << "Direct access - Robot ID: " << direct_robot.robot_id_ << '\n';
    std::cout << "Direct access - Model: " << direct_robot.model_ << '\n';

    // Modify status directly
    direct_robot.operational_status_ = RobotStatus::MAINTENANCE;
    std::cout << "Status set to MAINTENANCE: " << static_cast<int>(direct_robot.get_status()) << '\n';

    // Try to execute task while in maintenance (should fail validation)
    direct_robot.execute_task();

    // Reset to IDLE and try again
    direct_robot.operational_status_ = RobotStatus::IDLE;
    std::cout << "Status reset to IDLE: " << static_cast<int>(direct_robot.get_status()) << '\n';
    direct_robot.execute_task();

    std::cout << "\n=== Demo Complete ===\n";
}
