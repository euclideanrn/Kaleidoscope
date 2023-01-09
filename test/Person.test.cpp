//
// Created by FANYI ZHAO on 1/8/23.
//
#include "Person.h"
#include <gtest/gtest.h>

TEST(PersonTest, Greet) {
    Person p("John", 30);
    EXPECT_EQ(p.greet(), "Hello, my name is John and I am 30 years old.");
}