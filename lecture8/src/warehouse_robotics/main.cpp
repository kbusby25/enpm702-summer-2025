#include <iostream>
#include <memory>

//=================
// Composition
//=================
#include "warehouse_robotics/robot.hpp"

int main() {
  auto robot =
      std::make_shared<robotics::Robot>("WH-AMR-001", "AutoNav-Pro-X5",
      "BATX1", 200.0);
}

// //=================
// // AGGREGATION
// //=================
// #include "warehouse_robotics/robot.hpp"
// #include "warehouse_robotics/task.hpp"

// int main() {
//   auto robot =
//       std::make_unique<robotics::Robot>("WH-AMR-001", "AutoNav-Pro-X5");

//   auto maintenance_task = std::make_shared<robotics::Task>(
//       "TSK-004", robotics::TaskType::MAINTENANCE, robotics::Priority::LOW);

//       robot->assign_task(maintenance_task);
// }

//=================
// Inheritance
//=================
// #include "warehouse_robotics/carrier_robot.hpp"
// #include "warehouse_robotics/scanner_robot.hpp"
// #include "warehouse_robotics/sorter_robot.hpp"

// int main() {
//   //================
//   // Stack objects
//   //================
//   auto carrier_stack = robotics::CarrierRobot("CarrierX100", 5.0);
//   std::cout << "============" << '\n';

//   auto sorter_stack = robotics::SorterRobot("SorterX100", 1.0);
//   std::cout << "============" << '\n';

//   auto scanner_stack = robotics::ScannerRobot("ScannerX100", 5.0, 50.0);
//   std::cout << "============" << '\n';

//   //================
//   // Pointers
//   //================
//   auto carrier_pointer =
//       std::make_unique<robotics::CarrierRobot>("CarrierX200", 5.0);
//   std::cout << "============" << '\n';
//   auto sorter_pointer =
//       std::make_unique<robotics::SorterRobot>("SorterX200", 1.0);
//   std::cout << "============" << '\n';
//   auto scanner_pointer =
//       std::make_unique<robotics::ScannerRobot>("ScannerX200", 5.0, 50.0);
// }

//=================
// Polymorphism
//=================
// #include "warehouse_robotics/carrier_robot.hpp"
// #include "warehouse_robotics/scanner_robot.hpp"
// #include "warehouse_robotics/sorter_robot.hpp"

// void command_robot(robotics::CarrierRobot &robot) { robot.execute_task(); }
// void command_robot(robotics::SorterRobot &robot) { robot.execute_task(); }
// void command_robot(robotics::ScannerRobot &robot) { robot.execute_task(); }

// void command_robot(std::unique_ptr<robotics::CarrierRobot> robot) {
//   robot->execute_task();
// }
// void command_robot(std::unique_ptr<robotics::SorterRobot> robot) {
//   robot->execute_task();
// }
// void command_robot(std::unique_ptr<robotics::ScannerRobot> robot) {
//   robot->execute_task();
// }

// int main() {
//   //================
//   // Stack objects
//   //================
//   auto carrier_stack = robotics::CarrierRobot("CarrierX100", 5.0);
//   command_robot(carrier_stack);
//   std::cout << "============" << '\n';

//   auto sorter_stack = robotics::SorterRobot("SorterX100", 1.0);
//   command_robot(sorter_stack);
//   std::cout << "============" << '\n';

//   auto scanner_stack = robotics::ScannerRobot("ScannerX100", 5.0, 50.0);
//   command_robot(scanner_stack);
//   std::cout << "============" << '\n';

//   //================
//   // Pointers
//   //================
//   auto carrier_pointer =
//       std::make_unique<robotics::CarrierRobot>("CarrierX200", 5.0);
//   command_robot(std::move(carrier_pointer));
//   std::cout << "============" << '\n';
//   auto sorter_pointer =
//       std::make_unique<robotics::SorterRobot>("SorterX200", 1.0);
//   command_robot(std::move(sorter_pointer));
//   std::cout << "============" << '\n';
//   auto scanner_pointer =
//       std::make_unique<robotics::ScannerRobot>("ScannerX200", 5.0, 50.0);
//   command_robot(std::move(scanner_pointer));
// }


//=================
// Polymorphism </20>
//=================
// void command_robot(robotics::Robot &robot) { robot.execute_task(); }
// void command_robot(std::unique_ptr<robotics::Robot> robot) {
//   robot->execute_task();
// }

// int main() {
//   //================
//   // Stack objects
//   //================
//   auto carrier_stack = robotics::CarrierRobot("CarrierX100", 5.0);
//   command_robot(carrier_stack);
//   std::cout << "============" << '\n';

//   auto sorter_stack = robotics::SorterRobot("SorterX100", 1.0);
//   command_robot(sorter_stack);
//   std::cout << "============" << '\n';

//   auto scanner_stack = robotics::ScannerRobot("ScannerX100", 5.0, 50.0);
//   command_robot(scanner_stack);
//   std::cout << "============" << '\n';

//   //================
//   // Pointers
//   //================
//   auto carrier_pointer =
//       std::make_unique<robotics::CarrierRobot>("CarrierX200", 5.0);
//   command_robot(std::move(carrier_pointer));
//   std::cout << "============" << '\n';
//   auto sorter_pointer =
//       std::make_unique<robotics::SorterRobot>("SorterX200", 1.0);
//   command_robot(std::move(sorter_pointer));
//   std::cout << "============" << '\n';
//   auto scanner_pointer =
//       std::make_unique<robotics::ScannerRobot>("ScannerX200", 5.0, 50.0);
//   command_robot(std::move(scanner_pointer));
// }