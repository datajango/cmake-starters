cmake_minimum_required(VERSION 3.22)

# Change this to your project name
set(PROJECT_NAME "cpp starter" CACHE INTERNAL "C++ Project Starter")

project(${PROJECT_NAME} VERSION 0.0.1)

include_directories(Source)
file(GLOB SOURCES "Source/Hello.cpp")
add_executable(hello2 ${SOURCES})

##############################################
# Unit Test Setup Section
################################################
enable_testing()

# All test .cpp files should be listed here
set(TestFiles
    Tests/Factorial.cpp)

# BEGIN Catch2 integration
# This will download the tagged version of Catch2
include(FetchContent)
FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG        v3.0.0-preview3
)
FetchContent_MakeAvailable(Catch2)
# END Catch2 integration

# Setup the test executable, again C++ 20 please
add_executable(tests ${TestFiles})
#target_compile_features(Tests PRIVATE cxx_std_20)
target_link_libraries(tests PRIVATE Catch2::Catch2WithMain)