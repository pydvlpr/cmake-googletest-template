cmake_minimum_required(VERSION 3.14)
project(my_project)

# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git 
  GIT_TAG f8d7d77c06936315286eb55f8de22cd23c188571 #current v1.14.0 tag hash
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_library(FuncLib func.cpp func.h)

add_executable(ExampleExe main.cpp)

target_link_libraries(ExampleExe PRIVATE FuncLib)

enable_testing()

add_executable(
    mytest
    tests.cpp
)

target_link_libraries(
  mytest FuncLib
  GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(mytest)
