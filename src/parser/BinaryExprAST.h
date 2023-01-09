//
// Created by FANYI ZHAO on 1/8/23.
//
#pragma once

#include <string>
#include <memory>
#include "ExprAST.h"

using std::unique_ptr;

class BinaryExprAST : public ExprAST {
private:
    char Op;
    unique_ptr<ExprAST> LHS, RHS;

public:
    BinaryExprAST(char op, unique_ptr<ExprAST> LHS, unique_ptr<ExprAST> RHS): Op(op), LHS(std::move(LHS)), RHS(std::move(RHS)) {}
};