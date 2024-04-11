#pragma once

#include "Solution.h"

#include <stack>
#include <vector>


class Stack : public Solution
{
public:
    Stack() : Solution("Stack", "Common challenge problems involving stacks.") {}
    std::unique_ptr<Solution> clone() const override { return std::make_unique<Stack>(*this); }
    
    bool validParentheses(const std::string& s);

    class MinStack
    {
    public:
        void push(int val);
        void pop();
        int top();
        int getMin();

    private:
        std::stack<int> stack;
        std::stack<int> minstack;
    };

    int evaluateReversePolishNotation(const std::vector<std::string>& tokens);
    std::vector<std::string> generateParenthesis(int n);
    std::vector<int> dailyTemperatures(const std::vector<int>& temperatures);
    int carFleet(int target, const std::vector<int>& position, const std::vector<int>& speed);
    int largestRectangleHistogram(const std::vector<int>& heights);

    // Simplify Path
    // Basic Calculator
    // Removing Stars from a string
    // Asteroid Collision
    // Decode String
    // Online Stock Span

private:
    void generateParenthesisRecursive(int openCount, int closeCount, int n,
                                      std::stack<char> current, std::vector<std::string>& result);
};