//
// Created by FANYI ZHAO on 1/7/23.
//
#pragma once

#include <string>
#include <utility>
#include "ExprAST.h"

/// VariableExprAST - Expression class for referencing a variable, like "a".
class VariableExprAST : public ExprAST {
private:
    std::string Name;

public:
    VariableExprAST(std::string Name) : Name(std::move(Name)) {}
};