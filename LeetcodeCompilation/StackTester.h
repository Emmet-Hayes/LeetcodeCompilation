#pragma once

#include "Stack.h"
#include "Tester.h"


class StackTester : public Tester
{
public:
    StackTester() : Tester { "Stack" } {}
    bool testAllProblems() override;
    std::unique_ptr<Tester> clone() const override { return std::make_unique<StackTester>(*this); }

private:
    bool testValidParentheses(std::string s, bool expected);
    bool testMinStack(); // one test case
    bool testEvaluateReversePolishNotation(std::vector<std::string> tokens, int expected);
    bool testGenerateParentheses(int n, std::vector<std::string> expected);
    bool testDailyTemperatures(std::vector<int> temperatures, std::vector<int> expected);
    bool testCarFleet(int target, std::vector<int> position, std::vector<int> speed, int expected);
    bool testLargestRectangleHistogram(std::vector<int> heights, int expected);

    // Simplify Path
    // Basic Calculator
    // Removing Stars from a string
    // Asteroid Collision
    // Decode String
    // Online Stock Span

    Stack stack;
};