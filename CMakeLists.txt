cmake_minimum_required(VERSION 3.10)
project(MyProject)

# Set C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Include directories
include_directories(include)

# Add source files
set(SOURCES
    src/TemperatureControl.cpp
    tst/maincpp.cpp
)

# Add executable target
add_executable(MyExecutable ${SOURCES})

# Google Test
#find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})



#target_link_libraries(MyTestExecutable ${GTEST_LIBRARIES} pthread)
