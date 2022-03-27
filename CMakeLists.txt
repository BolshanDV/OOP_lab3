cmake_minimum_required(VERSION 3.21)
project(OOP_lab3)

set(CMAKE_CXX_STANDARD 17)

add_executable(OOP_lab3 main.cpp operators/conditions/ifConstruction/IfStruct.cpp operators/conditions/ifConstruction/IfStruct.h operators/conditions/switchConstruction/SwitchStruct.cpp operators/conditions/switchConstruction/SwitchStruct.h operators/cycle/ForStruct.cpp operators/cycle/ForStruct.h parser/Parser.cpp parser/Parser.h)
