cmake_minimum_required(VERSION 3.10.0)
project(enpm702_summer2025 VERSION 0.1.0 LANGUAGES C CXX)

add_compile_options(-Wall -pedantic-errors)
# include_directories(lecture5/include)
# include_directories(lecture6/include)
# include_directories(lecture7/include)

# add_executable(lecture1_cpp lecture1/src/lecture1.cpp)
# add_executable(lecture2_cpp lecture2/src/lecture2.cpp)
# add_executable(lecture3_cpp lecture3/src/lecture3.cpp)
# add_executable(lecture4_cpp lecture4/src/lecture4.cpp)
# add_executable(lecture5_cpp lecture5/src/lecture5.cpp lecture5/src/main.cpp)
# add_executable(lecture6_cpp lecture6/src/lecture6.cpp lecture6/src/utils.cpp)
# add_executable(lecture7_cpp lecture7/src/main.cpp lecture7/src/robot.cpp)

# Set C++17 standard for the target
# set_property(TARGET lecture1_cpp PROPERTY CXX_STANDARD 17)
# set_property(TARGET lecture1_cpp PROPERTY CXX_STANDARD_REQUIRED ON)
# set_property(TARGET lecture2_cpp PROPERTY CXX_STANDARD 17)
# set_property(TARGET lecture2_cpp PROPERTY CXX_STANDARD_REQUIRED ON)
# set_property(TARGET lecture3_cpp PROPERTY CXX_STANDARD 17)
# set_property(TARGET lecture3_cpp PROPERTY CXX_STANDARD_REQUIRED ON)
# set_property(TARGET lecture4_cpp PROPERTY CXX_STANDARD 17)
# set_property(TARGET lecture4_cpp PROPERTY CXX_STANDARD_REQUIRED ON)
# set_property(TARGET lecture5_cpp PROPERTY CXX_STANDARD 17)
# set_property(TARGET lecture5_cpp PROPERTY CXX_STANDARD_REQUIRED ON)
# set_property(TARGET lecture6_cpp PROPERTY CXX_STANDARD 17)
# set_property(TARGET lecture6_cpp PROPERTY CXX_STANDARD_REQUIRED ON)
# set_property(TARGET lecture7_cpp PROPERTY CXX_STANDARD 17)
# set_property(TARGET lecture7_cpp PROPERTY CXX_STANDARD_REQUIRED ON)


# ========================
# Lecture 8 executables
# ========================
include_directories(lecture8/include)

# -- string_view
add_executable(string_view_demo lecture8/src/modern_features/string_view_demo.cpp)
set_property(TARGET string_view_demo PROPERTY CXX_STANDARD 17)
set_property(TARGET string_view_demo PROPERTY CXX_STANDARD_REQUIRED ON)

# -- explicit
add_executable(explicit_demo lecture8/src/modern_features/explicit_demo.cpp)
set_property(TARGET explicit_demo PROPERTY CXX_STANDARD 17)
set_property(TARGET explicit_demo PROPERTY CXX_STANDARD_REQUIRED ON)

# -- [[nodiscard]]
add_executable(nodiscard_demo lecture8/src/modern_features/nodiscard_demo.cpp)
set_property(TARGET nodiscard_demo PROPERTY CXX_STANDARD 17)
set_property(TARGET nodiscard_demo PROPERTY CXX_STANDARD_REQUIRED ON)

# -- std::optional
add_executable(optional_demo lecture8/src/modern_features/optional_demo.cpp)
set_property(TARGET optional_demo PROPERTY CXX_STANDARD 17)
set_property(TARGET optional_demo PROPERTY CXX_STANDARD_REQUIRED ON)

# -- static
add_executable(static_demo lecture8/src/modern_features/static_demo.cpp lecture8/src/modern_features/counter.cpp)
set_property(TARGET static_demo PROPERTY CXX_STANDARD 17)
set_property(TARGET static_demo PROPERTY CXX_STANDARD_REQUIRED ON)

# -- The this pointer
add_executable(this_pointer_demo lecture8/src/modern_features/this_pointer_demo.cpp)
set_property(TARGET this_pointer_demo PROPERTY CXX_STANDARD 17)
set_property(TARGET this_pointer_demo PROPERTY CXX_STANDARD_REQUIRED ON)

# -- Inheritance
add_executable(inheritance_demo lecture8/src/inheritance/inheritance_demo.cpp)
set_property(TARGET inheritance_demo PROPERTY CXX_STANDARD 17)
set_property(TARGET inheritance_demo PROPERTY CXX_STANDARD_REQUIRED ON)

# -- Inheritance Constructor
add_executable(inheritance_constructor_demo lecture8/src/inheritance/inheritance_constructor_demo.cpp)
set_property(TARGET inheritance_constructor_demo PROPERTY CXX_STANDARD 17)
set_property(TARGET inheritance_constructor_demo PROPERTY CXX_STANDARD_REQUIRED ON)

# -- Polymorphism 
add_executable(polymorphism_demo lecture8/src/polymorphism/polymorphism_demo.cpp)
set_property(TARGET polymorphism_demo PROPERTY CXX_STANDARD 17)
set_property(TARGET polymorphism_demo PROPERTY CXX_STANDARD_REQUIRED ON)

# -- Robotics: Composition and Aggregation
add_executable(robot_composition_aggregation_demo 
lecture8/src/warehouse_robotics/main.cpp 
lecture8/src/warehouse_robotics/robot.cpp 
lecture8/src/warehouse_robotics/task.cpp
lecture8/src/warehouse_robotics/battery.cpp
)
set_property(TARGET robot_composition_aggregation_demo PROPERTY CXX_STANDARD 17)
set_property(TARGET robot_composition_aggregation_demo PROPERTY CXX_STANDARD_REQUIRED ON)

# -- Robotics: Inheritance and polymorphism
add_executable(robot_polymorphism_demo 
lecture8/src/warehouse_robotics/main.cpp 
lecture8/src/warehouse_robotics/robot.cpp 
lecture8/src/warehouse_robotics/carrier_robot.cpp 
lecture8/src/warehouse_robotics/sorter_robot.cpp 
lecture8/src/warehouse_robotics/scanner_robot.cpp 
lecture8/src/warehouse_robotics/battery.cpp 
lecture8/src/warehouse_robotics/task.cpp)

set_property(TARGET robot_polymorphism_demo PROPERTY CXX_STANDARD 17)
set_property(TARGET robot_polymorphism_demo PROPERTY CXX_STANDARD_REQUIRED ON)









# # Add Valgrind target for lecture6_cpp
# find_program(VALGRIND_EXECUTABLE valgrind)
# if(VALGRIND_EXECUTABLE)
#     add_custom_target(valgrind_lecture6
#         COMMAND ${VALGRIND_EXECUTABLE} --tool=memcheck --leak-check=full --show-leak-kinds=all --track-origins=yes $<TARGET_FILE:lecture6_cpp>
#         DEPENDS lecture6_cpp
#         COMMENT "Running Valgrind on lecture6_cpp"
#     )
# endif()