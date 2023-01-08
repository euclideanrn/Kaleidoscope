//
// Created by Evan Z on 1/7/23.
//
// The lexer returns tokens [0-255] if it is an unknown character, otherwise one
// of these for known things.
#include <string>
#include <fmt/core.h>

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

static std::string IdentifierStr; // Filled in if tok_identifier
static double NumVal;             // Filled in if tok_number

static int gettok() {
    static int LastChar = ' ';

    // skip any whitespace.
    while (isspace(LastChar))
        LastChar = getchar();

    fmt::print("LastChar: {} \n", LastChar);

    // if last char is an identifier, return an identifier token
    if (isalpha(LastChar)) { // identifier: [a-zA-Z][a-zA-Z0-9]*
        fmt::print("isalpha: {} \n", LastChar);
        IdentifierStr = LastChar;
        while (isalnum((LastChar = getchar())))
            IdentifierStr += LastChar;

        if (IdentifierStr == "def")
            return tok_def;
        if (IdentifierStr == "extern")
            return tok_extern;
        return tok_identifier;
    }

    // if last char is a number, return a number token
    if (isdigit(LastChar) || LastChar == '.') {   // Number: [0-9.]+
        fmt::print("isdigit: {} \n", LastChar);
        std::string NumStr;
        do {
            NumStr += LastChar;
            LastChar = getchar();
        } while (isdigit(LastChar) || LastChar == '.');

        NumVal = strtod(NumStr.c_str(), 0);
        return tok_number;
    }

    // if last char is a comment, skip to the end of the line
    if (LastChar == '#') {
        fmt::print("iscomment: {} \n", LastChar);
        // Comment until end of line.
        do
            LastChar = getchar();
        while (LastChar != EOF && LastChar != '\n' && LastChar != '\r');

        if (LastChar != EOF)
            return gettok();
    }

    // Check for end of file.  Don't eat the EOF.
    if (LastChar == EOF) {
        fmt::print("isEOF: {} \n", LastChar);
        return tok_eof;
    }

    fmt::print("isunknown: {} \n", LastChar);
    // Otherwise, just return the character as its ascii value.
    int ThisChar = LastChar;
    LastChar = getchar();
    return ThisChar;
}