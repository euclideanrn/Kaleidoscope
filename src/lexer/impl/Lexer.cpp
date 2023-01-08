//
// Created by FANYI ZHAO on 1/8/23.
//

#include "../Lexer.h"
#include "fmt/core.h"

// implementation of Lexer class
// implement gettok() function

int Lexer::gettok() {
    // skip whitespaces
    while (isspace(lastChar)) {
        lastChar = getNextChar();
    }

    // handle identifiers and keywords
    if (isalpha(lastChar)) {
        identifierStr = lastChar;
        while (isalpha((lastChar = getNextChar()))) {
            identifierStr += lastChar;
        }

        if (identifierStr == "def") {
            // print log using fmt
            fmt::print("Found keyword: {} \n", identifierStr);
            return Token::tok_def;
        }
        if (identifierStr == "extern") {
            // print log using fmt
            fmt::print("Found keyword: {} \n", identifierStr);
            return Token::tok_extern;
        }
        return Token::tok_identifier;
    }

    // handle numbers
    if (isdigit(lastChar) || lastChar == '.') {
        std::string numStr;
        int dotCount = 0;
        do {
            numStr += lastChar;
            lastChar = getNextChar();
            if (lastChar == '.') {
                dotCount++;
            }
        } while (isdigit(lastChar) || lastChar == '.');

        if (dotCount > 1) {
            fmt::print("Error: invalid number \n");
            return Token::tok_eof;
        }

        numVal = strtod(numStr.c_str(), nullptr);
        // print log using fmt
        fmt::print("Found number: {} \n", numVal);
        return Token::tok_number;
    }

    // handle comments
    if (lastChar == '#') {
        fmt::print("Found comment: ");
        do {
            auto ch = getNextChar();
            lastChar = ch;
            fmt::print("{}", ch);
        } while (lastChar != EOF && lastChar != '\n' && lastChar != '\r');
        fmt::print("\n");
        if (lastChar != EOF) {
            return gettok();
        }
    }

    // handle EOF
    if (lastChar == EOF) {
        // print log using fmt
        fmt::print("Found EOF: {} \n", lastChar);
        return Token::tok_eof;
    }

    // handle operators
    int thisChar = lastChar;
    lastChar = getNextChar();
    // print log using fmt
    fmt::print("Found operator: {} \n", thisChar);
    return thisChar;
}

char Lexer::getNextChar() {
    return getchar();
}