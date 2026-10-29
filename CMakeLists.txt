cmake_minimum_required(VERSION 4.3)
project(lab2)

set(CMAKE_CXX_SCAN_FOR_MODULES OFF)

set(CMAKE_CXX_STANDARD 20)

add_executable(lab2 main.cpp
        RentalCar.h
        RentalCar.cpp)
