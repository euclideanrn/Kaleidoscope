cmake_minimum_required(VERSION 3.10)
project(test)
include(FetchContent)

FetchContent_Declare(gtest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG        release-1.11.0
)
FetchContent_MakeAvailable(gtest)
#find_package(PkgConfig REQUIRED)
#pkg_check_modules(GTEST REQUIRED IMPORTED_TARGET gtest)

# use FetchContent to download fmt library
FetchContent_Declare(fmt
        GIT_REPOSITORY https://github.com/fmtlib/fmt.git
        GIT_TAG 9.1.0
)
FetchContent_MakeAvailable(fmt)
#find_package(PkgConfig REQUIRED)
#pkg_check_modules(FMT REQUIRED IMPORTED_TARGET fmt)

add_executable(test Person.cpp Person.test.cpp main.test.cpp)
target_link_libraries(test gtest gtest_main fmt)

enable_testing()
add_test(NAME test COMMAND test)