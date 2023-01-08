//
// Created by Evan Z on 1/7/23.
//

#ifndef KALEIDOSCOPE_PERSON_H
#define KALEIDOSCOPE_PERSON_H


#include <string>

class Person {
public:
    // Constructor
    Person(const std::string& name, int age);

    // Greet the person
    std::string greet() const;

private:
    std::string name_;
    int age_;
};


#endif //KALEIDOSCOPE_PERSON_H
