//
// Created by FANYI ZHAO on 1/7/23.
//
#pragma once

#include "ExprAST.h"

/// NumberExprAST - Expression class for numeric literals like "1.0".
class NumberExprAST : public ExprAST {
private:
    double Val;

public:
    NumberExprAST(double Val) : Val(Val) {}
};
