cmake_minimum_required(VERSION 3.10) 
project(LB_1)

set(CMAKE_CXX_STANDARD 20)

option(USE_STATIC "Use static library" ON) 
message(STATUS "OS: &{CMAKE_SYSTEM_NAME}")
message(STATUS "Compiler: &{CMAKE_CXX_COMPILER_ID}")

add_executable(LB_1 example.cpp)

add_library(message-objs 
    OBJECT
    class_Matrix/matrix.cpp
    class_Matrix/Matrix.h
)

if(USE_STATIC)
    add_library(message-a 
    STATIC 
    $<TARGET_OBJECTS:message-objs>)
    target_link_libraries(LB_1 message-a)
else() 
    add_library(message-d 
    SHARED 
    $<TARGET_OBJECTS:message-objs>)
    target_link_libraries(LB_1 message-d)
endif() 
