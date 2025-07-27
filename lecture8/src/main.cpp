#include <iostream>
#include <memory>

#include "robot.hpp"

// Function to demonstrate working with stack-allocated Robot objects
void demonstrate_stack_robots() {
    std::cout << "\n=== demonstrate_stack_robots() ===\n";

    // Create robots on the stack using parameterized constructor
    robotics::Robot robot1("STACK-001", "WarehouseBot-Pro");
    robotics::Robot robot2("STACK-002", "ScannerBot-Elite");

    std::cout << "Created two stack robots:\n";
    std::cout << "  " << robot1.get_robot_id() << " (" << robot1.get_model() << ")\n";
    std::cout << "  " << robot2.get_robot_id() << " (" << robot2.get_model() << ")\n";

    // Demonstrate operations
    std::cout << "\nPerforming operations on stack robots:\n";

    // Robot1 operations
    std::cout << "Robot1 task: " << robot1.get_task_description() << '\n';
    robot1.move();
    robot1.execute_task();

    // Robot2 operations
    std::cout << "Robot2 task: " << robot2.get_task_description() << '\n';
    robot2.update_position();
    robot2.execute_task();

    // Test validation with maintenance status
    // Note: Since there's no set_status() method in your header, we'll simulate
    // an error condition by trying to move a robot that's already active
    std::cout << "\nTesting error conditions:\n";

    // Try to perform operations when robot is busy (already active from previous operations)
    try {
        // Robot1 is already ACTIVE from previous execute_task() call
        std::cout << "Attempting to move robot1 while it may be busy...\n";
        robot1.move();  // This might work since validation may allow ACTIVE status
    } catch (const std::exception& e) {
        std::cout << "Expected failure: " << e.what() << '\n';
    }

    std::cout << "Stack robots demo complete (objects will be destroyed when function exits)\n";
    // Note: robot1 and robot2 are automatically destroyed here
}

// Function to demonstrate working with heap-allocated Robot pointers
void demonstrate_pointer_robots() {
    std::cout << "\n=== demonstrate_pointer_robots() ===\n";

    // Create robots on the heap using smart pointers with parameterized constructor
    auto robot_ptr1 = std::make_unique<robotics::Robot>("HEAP-001", "CarrierBot-Heavy");
    auto robot_ptr2 = std::make_unique<robotics::Robot>("HEAP-002", "SorterBot-Fast");

    std::cout << "Created two heap robots using smart pointers:\n";
    std::cout << "  " << robot_ptr1->get_robot_id() << " (" << robot_ptr1->get_model() << ")\n";
    std::cout << "  " << robot_ptr2->get_robot_id() << " (" << robot_ptr2->get_model() << ")\n";

    // Demonstrate pointer operations
    std::cout << "\nPerforming operations through pointers:\n";

    // Operations using -> operator
    robot_ptr1->move();
    robot_ptr1->execute_task();
    std::cout << "Robot1 status: " << static_cast<int>(robot_ptr1->get_status()) << '\n';

    robot_ptr2->update_position();
    robot_ptr2->execute_task();
    std::cout << "Robot2 status: " << static_cast<int>(robot_ptr2->get_status()) << '\n';

    // Demonstrate pointer transfer/movement
    std::cout << "\nDemonstrating pointer ownership transfer:\n";
    auto robot_ptr3 = std::move(robot_ptr1);  // Transfer ownership

    if (!robot_ptr1) {
        std::cout << "robot_ptr1 is now null after move\n";
    }

    if (robot_ptr3) {
        std::cout << "robot_ptr3 now owns: " << robot_ptr3->get_robot_id() << '\n';

        // Since there's no set_status() method, let's demonstrate other operations
        std::cout << "Updating model for robot_ptr3...\n";
        robot_ptr3->set_model("AdvancedBot-V2");
        std::cout << "New model: " << robot_ptr3->get_model() << '\n';
    }

    // Show memory usage difference
    std::cout << "\nMemory information:\n";
    std::cout << "Size of Robot object: " << sizeof(robotics::Robot) << " bytes\n";
    std::cout << "Size of unique_ptr: " << sizeof(robot_ptr2) << " bytes\n";

    std::cout << "Pointer robots demo complete (smart pointers will auto-cleanup)\n";
    // Note: unique_ptrs automatically delete their objects when going out of scope
}

// Additional function to demonstrate model changes and task descriptions
void demonstrate_robot_features() {
    std::cout << "\n=== demonstrate_robot_features() ===\n";

    // Create a robot and demonstrate various features
    robotics::Robot demo_robot("DEMO-001", "InitialModel");

    std::cout << "Initial robot configuration:\n";
    std::cout << "  ID: " << demo_robot.get_robot_id() << '\n';
    std::cout << "  Model: " << demo_robot.get_model() << '\n';
    std::cout << "  Status: " << static_cast<int>(demo_robot.get_status()) << '\n';
    std::cout << "  Task: " << demo_robot.get_task_description() << '\n';

    // Change model and show updated task description
    std::cout << "\nChanging robot model...\n";
    demo_robot.set_model("AdvancedScanner-Pro");
    std::cout << "  New Model: " << demo_robot.get_model() << '\n';
    std::cout << "  Updated Task: " << demo_robot.get_task_description() << '\n';

    // Demonstrate validation
    std::cout << "\nTesting operation validation:\n";
    if (demo_robot.validate_operation()) {
        std::cout << "Robot can perform operations\n";
        demo_robot.move();
        demo_robot.execute_task();
    } else {
        std::cout << "Robot cannot perform operations\n";
    }

    std::cout << "Final status: " << static_cast<int>(demo_robot.get_status()) << '\n';
}

int main() {
    std::cout << "=== Warehouse robotics::Robot Management System Demo ===\n";

    // Call our demonstration functions
    demonstrate_stack_robots();
    demonstrate_pointer_robots();
    demonstrate_robot_features();

    std::cout << "\n=== Demo Complete ===\n";
}