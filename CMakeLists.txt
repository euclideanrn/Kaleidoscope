cmake_minimum_required(VERSION 3.14)  # CMake version check
project(Kaleidoscope)

# set standard c++ version to c++20
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# us pkg-config to locate a preinstalled fmt library
# find pkg-config, make sure it's installed
find_package(PkgConfig REQUIRED)
# find fmt, make sure it's installed
pkg_check_modules(FMT REQUIRED IMPORTED_TARGET fmt)

# set the source files, only one file with main() method is allowed
set(SOURCE_FILES
        src/main.cpp

        #lexer
        src/lexer/impl/Lexer.cpp

        #parser
        src/parser/impl/ExprAST.cpp
        src/parser/impl/NumberExprAST.cpp
        src/parser/impl/VariableExprAST.cpp
        src/parser/impl/CallExprAST.cpp
        src/parser/impl/BinaryExprAST.cpp)

# add the executable files to the project
add_executable(Kaleidoscope ${SOURCE_FILES})

# use pkg-config to get the cflags and libs for fmt
target_link_libraries(Kaleidoscope PUBLIC PkgConfig::FMT)

add_subdirectory(test)