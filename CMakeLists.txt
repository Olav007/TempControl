cmake_minimum_required(VERSION 3.10)
project(MyProject)

# Set C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)


# Add source files
set(SOURCES
    src/TemperatureControl.cpp
    tst/maincpp.cpp
)

# Google Test and Mock
find_package(GTest REQUIRED)

# No need to explicitly include directories if find_package works correctly
include_directories(${GTEST_INCLUDE_DIRS})

# Add executable target
add_executable(MyTestExecutable ${SOURCES})

# If find_package(GTest REQUIRED) and find_package(GMock REQUIRED) are successful,
# they define GTEST_BOTH_LIBRARIES and GMOCK_BOTH_LIBRARIES respectively.
# If for some reason GMOCK_BOTH_LIBRARIES isn't defined, linking directly to the static library is a good fallback.
target_link_libraries(MyTestExecutable ${GTEST_BOTH_LIBRARIES} ${GMOCK_BOTH_LIBRARIES} pthread)

# If GMOCK_BOTH_LIBRARIES is not found or you have trouble with dynamic linking,
# you can fallback to directly linking the static library as you did:
# target_link_libraries(MyTestExecutable ${GTEST_BOTH_LIBRARIES} /usr/lib/x86_64-linux-gnu/libgmock.a pthread)
