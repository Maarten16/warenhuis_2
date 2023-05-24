cmake_minimum_required(VERSION 3.22)
project(warenhuis_2)

set(CMAKE_CXX_STANDARD 23)

add_executable(warenhuis_2 src/main.cpp src/Pallet.cpp src/Employee.cpp src/Warehouse.cpp src/Shelf.cpp src/headers/Shelf.hpp)
target_include_directories(warenhuis_2 PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/headers)