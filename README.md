# CMake and Google Test

This is a sample template for using CMake with Google Test.

This example just contains the basic project structure with a sample `CMakeLists.txt` file. You should be able to easily adapt this sample with your own projects code.

## Project structure

The sample project directory structure looks like

```
.
├── build
└── source
    ├── CMakeLists.txt
    ├── func.cpp
    ├── func.h
    ├── main.cpp
    └── tests.cpp
```

## Create the CMakeLists.txt

The CMakeList has to declare a dependency to Google Test. 

```
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
```
Then the CMakeLists.txt has to be declate the library and executable.

```
add_library(FuncLib func.cpp func.h)

add_executable(ExampleExe main.cpp)

target_link_libraries(ExampleExe PRIVATE FuncLib)
```

Finally a test section has to be defined.

```
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
```
## Prepare the build files

A first the build files have to be prepared.

```
-> % cmake -S source -B build          
-- The C compiler identification is AppleClang 15.0.0.15000040
-- The CXX compiler identification is AppleClang 15.0.0.15000040
...
-- Configuring done (3.4s)
-- Generating done (0.0s)
-- Build files have been written to: /Users/me/codework/cmake/cmake and goggletest/build
```

## Build the project

The project with google test can be build.

```
-> % cmake --build build               
[  7%] Building CXX object CMakeFiles/FuncLib.dir/func.cpp.o
[ 14%] Linking CXX static library libFuncLib.a
[ 14%] Built target FuncLib
[ 21%] Building CXX object CMakeFiles/ExampleExe.dir/main.cpp.o
[ 28%] Linking CXX executable ExampleExe
[ 28%] Built target ExampleExe
[ 35%] Building CXX object _deps/googletest-build/googletest/CMakeFiles/gtest.dir/src/gtest-all.cc.o
[ 42%] Linking CXX static library ../../../lib/libgtest.a
[ 42%] Built target gtest
[ 50%] Building CXX object _deps/googletest-build/googletest/CMakeFiles/gtest_main.dir/src/gtest_main.cc.o
[ 57%] Linking CXX static library ../../../lib/libgtest_main.a
[ 57%] Built target gtest_main
[ 64%] Building CXX object CMakeFiles/mytest.dir/tests.cpp.o
[ 71%] Linking CXX executable mytest
[ 71%] Built target mytest
[ 78%] Building CXX object _deps/googletest-build/googlemock/CMakeFiles/gmock.dir/src/gmock-all.cc.o
[ 85%] Linking CXX static library ../../../lib/libgmock.a
[ 85%] Built target gmock
[ 92%] Building CXX object _deps/googletest-build/googlemock/CMakeFiles/gmock_main.dir/src/gmock_main.cc.o
[100%] Linking CXX static library ../../../lib/libgmock_main.a
[100%] Built target gmock_main
```

Google Test is only build once. After some source code changes only the projects changed source files are build again.

```
-> % cmake --build build 
[ 14%] Built target FuncLib
[ 21%] Building CXX object CMakeFiles/ExampleExe.dir/main.cpp.o
[ 28%] Linking CXX executable ExampleExe
[ 28%] Built target ExampleExe
[ 42%] Built target gtest
[ 57%] Built target gtest_main
[ 71%] Built target mytest
[ 85%] Built target gmock
[100%] Built target gmock_main
```

## Run the tests

The test does not run automatically during the build process. The tests have to run seperate after the build proces.

```
-> % cd build && ctest  
Test project /Users/me/codework/cmake/cmake and goggletest/build
    Start 1: FunctionTests.AddTwoPositives
1/2 Test #1: FunctionTests.AddTwoPositives .......   Passed    0.00 sec
    Start 2: FunctionTests.MultiplyTwoPositivs
2/2 Test #2: FunctionTests.MultiplyTwoPositivs ...   Passed    0.00 sec

100% tests passed, 0 tests failed out of 2

Total Test time (real) =   0.01 sec
```

## Further information

- [Quickstart: Building with CMake](http://google.github.io/googletest/quickstart-cmake.html)