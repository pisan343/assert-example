cmake_minimum_required(VERSION 3.5)
project(assert_example)

set(CMAKE_CXX_STANDARD 14)

# have compiler give warnings, but not for signed/unsigned
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -Wall -Wextra -Wno-sign-compare")

add_executable(assert_example main.cpp rational.cpp rational.h factorial_test.cpp vector_test.cpp rational_test.cpp)