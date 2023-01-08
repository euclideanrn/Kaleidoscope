//
// Created by Evan Z on 1/7/23.
//
#include "ExprAST.h"

#ifndef KALEIDOSCOPE_NUMBEREXPRAST_H
#define KALEIDOSCOPE_NUMBEREXPRAST_H

/// NumberExprAST - Expression class for numeric literals like "1.0".
class NumberExprAST : public ExprAST {
    double Val;

public:
    NumberExprAST(double Val) : Val(Val) {}
};


#endif //KALEIDOSCOPE_NUMBEREXPRAST_H
