cmake_minimum_required(VERSION 3.0)

set(PROJECT_NAME register_system)

project(${PROJECT_NAME})

add_executable(${PROJECT_NAME} src/user/user.h src/user/user.cpp src/interface/interface.h src/interface/interface.cpp src/main.cpp)

