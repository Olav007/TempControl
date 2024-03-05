cmake_minimum_required(VERSION 3.10)
project(TempControl)

# Set C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Enable testing with CTest
enable_testing()

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)


# Add source files
set(SOURCES
    tst/maincpp.cpp
)

# Google Test and Mock
find_package(GTest REQUIRED)

# Include Google Test and your project's header directories
include_directories(${GTEST_INCLUDE_DIRS} ${PROJECT_SOURCE_DIR}/include)

# Add executable target
add_executable(TempControlTest ${SOURCES})


target_link_libraries(TempControlTest GTest::gtest GTest::gmock GTest::gtest_main GTest::gmock_main)

# If GMOCK_BOTH_LIBRARIES is not found or you have trouble with dynamic linking,
# you can fallback to directly linking the static library as you did:
# target_link_libraries(MyTestExecutable ${GTEST_BOTH_LIBRARIES} /usr/lib/x86_64-linux-gnu/libgmock.a pthread)
