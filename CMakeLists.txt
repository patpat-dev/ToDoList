cmake_minimum_required(VERSION 3.29)
project(ToDoList)

set(CMAKE_CXX_STANDARD 20)

set(SOURCE_FILES
        src/Task.cpp
        src/Task.h
        src/ToDoList.cpp
        src/ToDoList.h
        src/MemoryManager.cpp
        src/MemoryManager.h
)

add_executable(ToDoList main.cpp ${SOURCE_FILES})

# -- SEZIONE TESTING --

#set(gtest_SOURCE_DIR
#    tests/lib/googletest/
#)
#include_directories(${gtest_SOURCE_DIR}/include)

#add_executable(runUnitTests
#    tests/test_main.cpp
#        ${SOURCE__FILES}
#)

#enable_testing()
include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

find_package(Threads REQUIRED)

FetchContent_MakeAvailable(googletest)

enable_testing()
add_executable(runUnitTests tests/test_main.cpp ${SOURCE_FILES})
target_link_libraries(runUnitTests GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(runUnitTests)


