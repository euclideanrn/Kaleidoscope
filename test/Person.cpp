//
// Created by FANYI ZHAO on 1/7/23.
//

#include "Person.h"
#include <iostream>

// Constructor
Person::Person(const std::string& name, int age) : name_(name), age_(age) {}

// Greet the person
std::string Person::greet() const {
    return "Hello, my name is " + name_ + " and I am " + std::to_string(age_) + " years old.";
}