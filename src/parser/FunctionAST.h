//
// Created by FANYI ZHAO on 1/8/23.
//
#pragma once

#include <string>
#include <vector>
#include <memory>
#include "PrototypeAST.h"
#include "ExprAST.h"

using std::unique_ptr;

class FunctionAST {
private:
    std::unique_ptr<PrototypeAST> Proto;
    std::unique_ptr<ExprAST> Body;

public:
    FunctionAST(unique_ptr<PrototypeAST> Proto, unique_ptr<ExprAST> Body) : Proto(std::move(Proto)), Body(std::move(Body)) {}
};
