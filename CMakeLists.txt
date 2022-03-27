cmake_minimum_required(VERSION 3.21)
project(OOP_lab3)

set(CMAKE_CXX_STANDARD 17)

add_executable(OOP_lab3 main.cpp operators/conditions/ifConstruction/IfStruct.cpp operators/conditions/ifConstruction/IfStruct.h operators/conditions/swetchConstruction/SwitchStruct.cpp operators/conditions/swetchConstruction/SwitchStruct.h operators/cycle/ForStruct.cpp operators/cycle/ForStruct.h)
