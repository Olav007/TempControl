cmake_minimum_required(VERSION 3.10)
project(MyTestExecutable)

# Set C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Enable testing with CTest
enable_testing()

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)


# Add source files
set(SOURCES
    src/TemperatureControl.cpp
    tst/maincpp.cpp
)

# Google Test and Mock
find_package(GTest REQUIRED)
#find_package(GMock REQUIRED)

# Include Google Test and your project's header directories
include_directories(${GTEST_INCLUDE_DIRS} ${PROJECT_SOURCE_DIR}/include)

# Add executable target
add_executable(MyTestExecutable ${SOURCES})

# If find_package(GTest REQUIRED) and find_package(GMock REQUIRED) are successful,
# they define GTEST_BOTH_LIBRARIES and GMOCK_BOTH_LIBRARIES respectively.
# If for some reason GMOCK_BOTH_LIBRARIES isn't defined, linking directly to the static library is a good fallback.
#target_link_libraries(MyTestExecutable ${GTEST_BOTH_LIBRARIES} ${GMOCK_BOTH_LIBRARIES} pthread)
#target_link_libraries(MyTestExecutable ${GTEST_LIBRARIES} ${GTEST_MAIN_LIBRARIES} pthread)
#target_link_libraries(MyTestExecutable GTest::GTest GTest::Main pthread)
target_link_libraries(MyTestExecutable GTest::gtest GTest::gmock GTest::gtest_main GTest::gmock_main)

# If GMOCK_BOTH_LIBRARIES is not found or you have trouble with dynamic linking,
# you can fallback to directly linking the static library as you did:
# target_link_libraries(MyTestExecutable ${GTEST_BOTH_LIBRARIES} /usr/lib/x86_64-linux-gnu/libgmock.a pthread)
