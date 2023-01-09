//
// Created by FANYI ZHAO on 1/8/23.
//
#pragma once

#include <string>
#include <memory>
#include <utility>
#include <vector>
#include "ExprAST.h"

using std::unique_ptr;
using std::vector;
using std::string;

class CallExprAST : public ExprAST {
private:
    std::string Callee;
    std::vector<std::unique_ptr<ExprAST>> args;

public:
    CallExprAST(string Callee, vector<unique_ptr<ExprAST>> args): Callee(std::move(Callee)), args(std::move(args)) {}
};
