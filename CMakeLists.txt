cmake_minimum_required(VERSION 3.21)
project(SDIZO1)

set(CMAKE_CXX_STANDARD 14)
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static-libstdc++ -static-libgcc")


set(SOURCE_FILES main.cpp)
add_executable(SDIZO1 main.cpp Dynamic_Table.cpp Dynamic_Table.h Double_Linked_List.cpp Double_Linked_List.h Binary_Heap.cpp Binary_Heap.h Counter.cpp Counter.h)
