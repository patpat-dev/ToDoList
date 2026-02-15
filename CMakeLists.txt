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

set(gtest_SOURCE_DIR
    tests/lib/googletest/
)
include_directories(${gtest_SOURCE_DIR}/include)

enable_testing()


