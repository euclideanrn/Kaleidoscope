//
// Created by FANYI ZHAO on 1/8/23.
//
#pragma once

#include <string>
#include <vector>


class PrototypeAST {
private:
    std::string Name;
    std::vector<std::string> Args;

public:
    PrototypeAST(const std::string &name, std::vector<std::string> Args) : Name(name), Args(std::move(Args)) {}

    const std::string &getName() const { return Name; }
};