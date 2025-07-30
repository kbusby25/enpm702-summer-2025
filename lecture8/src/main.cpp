#include <iostream>
#include <memory>

#include "carrier_robot.hpp"
#include "robot.hpp"
#include "scanner_robot.hpp"
#include "sorter_robot.hpp"

void command_robot(robotics::CarrierRobot &robot) { robot.execute_task(); }
void command_robot(robotics::SorterRobot &robot) { robot.execute_task(); }
void command_robot(robotics::ScannerRobot &robot) { robot.execute_task(); }

void command_robot(std::unique_ptr<robotics::CarrierRobot> robot) {
  robot->execute_task();
}
void command_robot(std::unique_ptr<robotics::SorterRobot> robot) {
  robot->execute_task();
}
void command_robot(std::unique_ptr<robotics::ScannerRobot> robot) {
  robot->execute_task();
}

int main() {
  // Stack objects
  auto carrier_stack = robotics::CarrierRobot("CarrierX100", 5.0);
  command_robot(carrier_stack);
  std::cout << "============" << '\n';

  auto sorter_stack = robotics::SorterRobot("SorterX100", 1.0);
  command_robot(sorter_stack);
  std::cout << "============" << '\n';

  auto scanner_stack = robotics::ScannerRobot("ScannerX100", 5.0, 50.0);
  command_robot(scanner_stack);

  // Pointers
  auto carrier_pointer =
      std::make_unique<robotics::CarrierRobot>("CarrierX200", 5.0);
  command_robot(std::move(carrier_pointer));

  auto sorter_pointer =
      std::make_unique<robotics::SorterRobot>("SorterX200", 1.0);
  command_robot(std::move(sorter_pointer));

  auto scanner_pointer =
      std::make_unique<robotics::ScannerRobot>("ScannerX200", 5.0, 50.0);
  command_robot(std::move(scanner_pointer));
}