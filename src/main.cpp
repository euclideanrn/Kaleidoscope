//
// Created by Evan Z on 1/7/23.
//
#include <iostream>
#include <fmt/format.h>
#include "lexer.cpp"

using fmt::format;
using std::cout;

int main() {
    // define a string literal
    const char str[] {"Hello, World! 1234567890"};
    for (auto *p = str; *p; p++) {
        if (isspace(*p)) {
            fmt::print("space ");
        } else if (isalpha(*p)) {
            fmt::print("[alpha: {}] ", *p);
        } else {
            fmt::print("{} ", *p);
        }
    }

    fmt::print("\n");
    fmt::print("token: {} \n", gettok());

    return 0;
}