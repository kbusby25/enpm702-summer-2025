#include <iostream>
#include <memory>

#include "robot.hpp"

int main() {
    std::cout << "=== Warehouse robotics::Robot Management System Demo ===\n";

    // Stack allocation example
    std::cout << "\n--- Stack Allocation Example ---\n";
    robotics::Robot stack_robot;
    std::cout << "Size of stack_robot: " << sizeof stack_robot << '\n';

    std::cout << "robotics::Robot ID: " << stack_robot.robot_id_ << '\n';
    std::cout << "Model: " << stack_robot.model_ << '\n';
    std::cout << "Task Description: " << stack_robot.get_task_description() << '\n';
    std::cout << "Initial Status: " << static_cast<int>(stack_robot.get_status()) << '\n';

    stack_robot.move();
    stack_robot.execute_task();
    std::cout << "Status after task: " << static_cast<int>(stack_robot.get_status()) << '\n';

    // Unique pointer allocation example
    std::cout << "\n--- Unique Pointer Allocation Example ---\n";
    auto heap_robot = std::make_unique<robotics::Robot>();
    std::cout << "Size of heap_robot: " << sizeof heap_robot << '\n';

    std::cout
        << "robotics::Robot ID: " << heap_robot->robot_id_ << '\n';
    std::cout << "Model: " << heap_robot->model_ << '\n';
    std::cout << "Task Description: " << heap_robot->get_task_description() << '\n';
    std::cout << "Initial Status: " << static_cast<int>(heap_robot->get_status()) << '\n';

    heap_robot->move();
    heap_robot->execute_task();
    heap_robot->update_position();
    std::cout << "Status after operations: " << static_cast<int>(heap_robot->get_status()) << '\n';

    // // Direct member access demonstration (since all members are public)
    // std::cout << "\n--- Direct Member Access Example ---\n";
    // robotics::Robot direct_robot("R003", "GenericModel-Direct");

    // // Direct access to public members
    // std::cout << "Direct access - robotics::Robot ID: " << direct_robot.robot_id_ << '\n';
    // std::cout << "Direct access - Model: " << direct_robot.model_ << '\n';

    // // Modify status directly
    // direct_robot.operational_status_ = robotics::RobotStatus::MAINTENANCE;
    // std::cout << "Status set to MAINTENANCE: " << static_cast<int>(direct_robot.get_status()) << '\n';

    // // Try to execute task while in maintenance (should fail validation)
    // direct_robot.execute_task();

    // // Reset to IDLE and try again
    // direct_robot.operational_status_ = robotics::RobotStatus::IDLE;
    // std::cout << "Status reset to IDLE: " << static_cast<int>(direct_robot.get_status()) << '\n';
    // direct_robot.execute_task();

    std::cout << "\n=== Demo Complete ===\n";
}

//=============
//====== </> 5
//=============

// int main() {
//     std::cout << "=== Warehouse robotics::Robot Management System Demo ===\n";

//     // Stack allocation example
//     std::cout << "\n--- Stack Allocation Example ---\n";

//     robotics::Robot stack_robot1; // default ctor
//     std::cout << "Model: " << stack_robot1.get_model() << '\n';

//     robotics::Robot stack_robot2("X234", "UR10e");  // parameterized ctor
//     std::cout << "Model: " << stack_robot2.get_model() << '\n';

//     // Unique pointer allocation example
//     std::cout << "\n--- Unique Pointer Allocation Example ---\n";
//     auto heap_robot1 = std::make_unique<robotics::Robot>();  // default ctor
//     std::cout << "Model: " << heap_robot1->get_model() << '\n';

//     auto heap_robot2 = std::make_unique<robotics::Robot>("X234", "UR10e");  // parameterized ctor
//     std::cout << "Model: " << heap_robot2->get_model() << '\n';

//     std::cout << "\n=== Demo Complete ===\n";
// }

// //=============
// //====== </> 6
// //=============

// class A {
//    public:
//     A() {
//         std::cout << "default ctor A\n";
//     }
//     A(int x) : v_{x} {
//         std::cout << "param ctor A\n";
//     }

//    private:
//     int v_;
// };  // class A

// class B {
//    public:
//     B() {
//         std::cout << "default ctor B\n";
//         a_ = A(2);  // calls param ctor for A
//     }

//    private:
//     A a_;  // calls default ctor for A
// };  // class B

// int main() {
//     B b;
// }

//=============
//====== </> 7
//=============

// class DemoConstAndRef {
//    public:
//     DemoConstAndRef(int constant, int reference) {
//         const_ = constant;  // error
//         ref_ = reference;   // error
//     }

//    private:
//     const int const_;
//     int &ref_;

// };  // class DemoConstAndRef

// int main() {
//     int some_value{43};
//     DemoConstAndRef demo(10, some_value);
// }