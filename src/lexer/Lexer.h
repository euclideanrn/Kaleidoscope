//
// Created by Evan Z on 1/8/23.
//
#pragma once

#include <string>

class Lexer {
    // define a default public constructor with no arguments
public:
    Lexer() = default;

    // define a private function gettok() of type int
    int gettok();

    // define a private function getNextChar() of type char
    static char getNextChar();

private:
    // define a private variable IdentifierStr of type std::string
    std::string identifierStr{};
    // define a private variable NumVal of type double
    double numVal{};
    // define a private variable LastChar of type char
    int lastChar{' '};

    /**
    * Each token returned by the lexer includes a token code and potentially some metadata
    * (e.g. the numeric value of a number).
    */
    enum Token {
        tok_eof = -1,

        // commands
        tok_def = -2,
        tok_extern = -3,

        // primary
        tok_identifier = -4,
        tok_number = -5,
    };
};