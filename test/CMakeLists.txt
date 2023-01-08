cmake_minimum_required(VERSION 3.10)
project(test)

find_package(PkgConfig REQUIRED)
pkg_check_modules(GTEST REQUIRED IMPORTED_TARGET gtest)

find_package(PkgConfig REQUIRED)
pkg_check_modules(FMT REQUIRED IMPORTED_TARGET fmt)

add_executable(test Person.cpp test_person.cpp test_main.cpp)
target_link_libraries(test PkgConfig::GTEST PkgConfig::FMT)

enable_testing()
add_test(NAME test COMMAND test)