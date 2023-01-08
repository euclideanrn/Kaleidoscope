//
// Created by FANYI ZHAO on 1/7/23.
//
#include <iostream>
#include <fmt/format.h>
#include "lexer/Lexer.h"

using fmt::format;
using std::cout;

int main() {
    // access the gettok function in the Lexer class and print the result
    // create a new lexer instance in memory
    Lexer lexer;
    // call the gettok function on the lexer instance and assign the result to a variable
    fmt::print("gettok: {} \n", lexer.gettok());
    return 0;
}