//
// Created by Evan Z on 1/7/23.
//
#include <string>
#include "ExprAST.h"

#ifndef KALEIDOSCOPE_VARIABLEEXPRAST_H
#define KALEIDOSCOPE_VARIABLEEXPRAST_H


/// VariableExprAST - Expression class for referencing a variable, like "a".
class VariableExprAST : public ExprAST {
    std::string Name;

public:
    VariableExprAST(const std::string &Name) : Name(Name) {}
};


#endif //KALEIDOSCOPE_VARIABLEEXPRAST_H
