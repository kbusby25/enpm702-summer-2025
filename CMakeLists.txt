cmake_minimum_required(VERSION 3.10.0)
project(enpm702_summer2025 VERSION 0.1.0 LANGUAGES C CXX)

add_compile_options(-Wall -pedantic-errors)
include_directories(lecture7/include)

add_executable(lecture1_cpp lecture1/src/lecture1.cpp)
add_executable(lecture2_cpp lecture2/src/lecture2.cpp)
add_executable(lecture3_cpp lecture3/src/lecture3.cpp)
add_executable(lecture4_cpp lecture4/src/lecture4.cpp)
add_executable(lecture5_cpp lecture5/src/lecture5.cpp lecture5/src/main.cpp)
add_executable(lecture6_cpp lecture6/src/lecture6.cpp lecture6/src/utils.cpp)
add_executable(lecture7_cpp lecture7/src/main.cpp lecture7/src/robot.cpp)

# Set C++17 standard for the target
set_property(TARGET lecture1_cpp PROPERTY CXX_STANDARD 17)
set_property(TARGET lecture1_cpp PROPERTY CXX_STANDARD_REQUIRED ON)
set_property(TARGET lecture2_cpp PROPERTY CXX_STANDARD 17)
set_property(TARGET lecture2_cpp PROPERTY CXX_STANDARD_REQUIRED ON)
set_property(TARGET lecture3_cpp PROPERTY CXX_STANDARD 17)
set_property(TARGET lecture3_cpp PROPERTY CXX_STANDARD_REQUIRED ON)
set_property(TARGET lecture4_cpp PROPERTY CXX_STANDARD 17)
set_property(TARGET lecture4_cpp PROPERTY CXX_STANDARD_REQUIRED ON)
set_property(TARGET lecture5_cpp PROPERTY CXX_STANDARD 17)
set_property(TARGET lecture5_cpp PROPERTY CXX_STANDARD_REQUIRED ON)
set_property(TARGET lecture6_cpp PROPERTY CXX_STANDARD 17)
set_property(TARGET lecture6_cpp PROPERTY CXX_STANDARD_REQUIRED ON)
set_property(TARGET lecture7_cpp PROPERTY CXX_STANDARD 17)
set_property(TARGET lecture7_cpp PROPERTY CXX_STANDARD_REQUIRED ON)

# # Add Valgrind target for lecture6_cpp
# find_program(VALGRIND_EXECUTABLE valgrind)
# if(VALGRIND_EXECUTABLE)
#     add_custom_target(valgrind_lecture6
#         COMMAND ${VALGRIND_EXECUTABLE} --tool=memcheck --leak-check=full --show-leak-kinds=all --track-origins=yes $<TARGET_FILE:lecture6_cpp>
#         DEPENDS lecture6_cpp
#         COMMENT "Running Valgrind on lecture6_cpp"
#     )
# endif()