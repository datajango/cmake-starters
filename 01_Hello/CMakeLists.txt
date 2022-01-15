cmake_minimum_required(VERSION 3.22)

# Change this to your project name
set(PROJECT_NAME "cpp starter" CACHE INTERNAL "C++ Project Starter")

project(${PROJECT_NAME} VERSION 0.0.1)

include_directories(Source)
file(GLOB SOURCES "Source/Hello.cpp")
add_executable(hello ${SOURCES})