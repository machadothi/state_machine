cmake_minimum_required(VERSION 2.8)

project(state_machine)
set(APP_NAME ${PROJECT_NAME})

# Enable C++11 standard
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall -Wextra -ggdb3")

# add source folder!
add_subdirectory(src)


