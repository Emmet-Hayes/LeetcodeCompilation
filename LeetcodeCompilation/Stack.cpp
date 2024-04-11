#include "Stack.h"

#include <stack>
#include <algorithm>


/** Valid Parentheses (Meta - Easy)
* Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', 
* determine if the input string is valid.
* 
* An input string is valid if:
*
* Open brackets must be closed by the same type of brackets.
* Open brackets must be closed in the correct order.
* Every close bracket has a corresponding open bracket of the same type.
* 
* Time: O(n)
* Space: O(n)
*/
bool Stack::validParentheses(const std::string& s)
{
    std::stack<char> brackets;
    for (const char& c : s)
    {
        switch (c)
        {
        // push opening parentheses, brackets and braces onto the stack
        case '(': case '[': case '{':
            brackets.push(c);
            break;
        // make sure each closing symbol corresponds to a valid open one on the stack
        case ')':
            if (brackets.empty() || brackets.top() != '(')
                return false;
            brackets.pop();
            break;
        case '}':
            if (brackets.empty() || brackets.top() != '{')
                return false;
            brackets.pop();
            break;
        case ']':
            if (brackets.empty() || brackets.top() != '[')
                return false;
            brackets.pop();
            break;
        }
    }

    return brackets.empty();
}


/** Evaluate Reverse Polish Notation (Amazon - Medium)
* You are given an array of strings tokens that represents an arithmetic expression 
* in a Reverse Polish Notation.
*
* Evaluate the expression. Return an integer that represents the value of the expression.
* 
* Complexity:
* Time: O(n)
* Space: O(n)
*/
int Stack::evaluateReversePolishNotation(const std::vector<std::string>& tokens)
{
    std::stack<int> rpnstack;
    for (const std::string& token : tokens)
    {
        if (token == "+" || token == "-" || token == "*" || token == "/")
        {
            int op2 = rpnstack.top();
            rpnstack.pop();
            int op1 = rpnstack.top();
            rpnstack.pop();
            if (token == "+") rpnstack.push(op1 + op2);
            else if (token == "-") rpnstack.push(op1 - op2);
            else if (token == "*") rpnstack.push(op1 * op2);
            else if (token == "/") rpnstack.push(op1 / op2);
        }
        else
        {
            rpnstack.push(stoi(token));
        }
    }
    return rpnstack.top();
}


/** Generate Parentheses (Amazon - Medium)
* Given n pairs of parentheses, write a function to generate 
* all combinations of well-formed parentheses.
* 
* Complexity:
* Time: O(4^n)
* Space: O(4^n)
*/
std::vector<std::string> Stack::generateParenthesis(int n)
{
    std::vector<std::string> result;
    std::stack<char> current;
    generateParenthesisRecursive(0, 0, n, current, result);
    return result;
}

void Stack::generateParenthesisRecursive(int openCount, int closeCount, int n, std::stack<char> current, std::vector<std::string>& result)
{
    if (current.size() == n * 2)
    {
        std::string str;
        while (!current.empty())
        {
            str += current.top();
            current.pop();
        }
        std::reverse(str.begin(), str.end());
        result.push_back(str);
        return;
    }

    if (openCount < n) // start by adding open parentheses
    {
        current.push('(');
        generateParenthesisRecursive(openCount + 1, closeCount, n, current, result);
        current.pop();
    }

    if (closeCount < openCount) // we can only add closing parentheses if theres less than open
    {
        current.push(')');
        generateParenthesisRecursive(openCount, closeCount + 1, n, current, result);
        current.pop();
    }
}


/** Daily Temperatures (Meta - Medium)
* Given an array of integers temperatures represents the daily temperatures, 
* return an array answer such that answer[i] is the number of days you have 
* to wait after the ith day to get a warmer temperature. If there is no future day 
* for which this is possible, keep answer[i] == 0 instead.
* 
* Complexity:
* Time: O(n)
* Space: O(n)
*/
std::vector<int> Stack::dailyTemperatures(const std::vector<int>& temperatures)
{
    std::vector<int> answer(temperatures.size(), 0);
    std::stack<int> indexstack; // storing indexes of non-increasing temperatures

    for (int i = 0; i < temperatures.size(); ++i)
    {
        while (!indexstack.empty() && temperatures[i] > temperatures[indexstack.top()])
        {
            int index = indexstack.top();
            indexstack.pop();
            answer[index] = i - index; // number of indexes away the greater temp occurred
        }
        indexstack.push(i);
    }

    return answer;
}


/** Car Fleet (Google - Medium)
* There are n cars going to the same destination along a one-lane road. 
* The destination is target miles away.
*
* You are given two integer array position and speed, both of length n, where 
* position[i] is the position of the ith car and speed[i] is the speed of the ith car 
* (in miles per hour).
*
* A car can never pass another car ahead of it, but it can catch up to it and drive 
* bumper to bumper at the same speed. The faster car will slow down to match the 
* slower car's speed. The distance between these two cars is ignored (i.e., they are 
* assumed to have the same position).
*
* A car fleet is some non-empty set of cars driving at the same position and same speed. 
* Note that a single car is also a car fleet.
*
* If a car catches up to a car fleet right at the destination point, it will still be 
* considered as one car fleet.
*
* Return the number of car fleets that will arrive at the destination.
* 
* Complexity:
* Time: O(n log n)
* Space: O(n)
*/
int Stack::carFleet(int target, const std::vector<int>& position, const std::vector<int>& speed)
{
    int numFleets = 0;
    int n = static_cast<int>(position.size());
    std::vector<std::pair<int, int>> cars;
    for (int i = 0; i < n; ++i)
        cars.push_back({ position[i], speed[i] });

    // sort cars in reverse order based on starting position
    std::sort(cars.begin(), cars.end());
    std::reverse(cars.begin(), cars.end());

    // storing time-to-target calculations for each car in the stack
    // stack in C++ doesn't support peeking at anything other than the top
    // this vector is used like a stack that supports peeking elsewhere
    std::vector<double> stack;

    for (int i = 0; i < cars.size(); ++i)
    {
        // adding all time-to-target calculations for cars to the stack
        stack.push_back((double)(target - cars[i].first) / cars[i].second);

        // if the last two cars will collide, we decrease the stack by the last car in
        // since that car is stuck with the car deeper in the stack
        if (stack.size() >= 2 && stack[stack.size() - 1] <= stack[stack.size() - 2])
            stack.pop_back();
    }

    return static_cast<int>(stack.size());
}

/** Largest Rectangle in Histogram (Google - Hard)
* Given an array of integers heights representing the histogram's bar height where 
* the width of each bar is 1, return the area of the largest rectangle in the histogram.
*/
int Stack::largestRectangleHistogram(const std::vector<int>& heights)
{
    std::stack<std::pair<int, int>> stack; // pair: index, height
    int maxarea = 0;
    int n = static_cast<int>(heights.size());

    // check as we iterate through the heights if we can
    // extend the rectangle to the right (if next height is same or greater)
    for (int i = 0; i < n; ++i)
    {
        int start = i;
        while (!stack.empty() && stack.top().second > heights[i])
        {
            int index = stack.top().first;
            int height = stack.top().second;
            maxarea = std::max(maxarea, height * (i - index));
            start = index; // we can include this index in our next area calc
            stack.pop();
        }
        stack.push({ start, heights[i] });
    }

    // check the potential areas remaining in the stack 
    // the remaining areas must extend to the end of the histogram
    while (!stack.empty())
    {
        int index = stack.top().first;
        int height = stack.top().second;
        maxarea = std::max(maxarea, height * (n - index));
        stack.pop();
    }

    return maxarea;
}


/** MinStack (Amazon - Medium)
* Design a stack that supports push, pop, top, and retrieving the minimum element 
* in constant time.
*
* MinStack Class Definition:
* 
* MinStack() initializes the stack object.
* void push(int val) pushes the element val onto the stack.
* void pop() removes the element on the top of the stack.
* int top() gets the top element of the stack.
* int getMin() retrieves the minimum element in the stack.
* 
* Complexity (All Operations):
* Time: O(1)
* Space: O(1)
*/
void Stack::MinStack::push(int val)
{
    stack.push(val);
    if (minstack.empty() || val <= minstack.top())
        minstack.push(val);
}

void Stack::MinStack::pop()
{
    if (stack.top() == minstack.top())
        minstack.pop();
    stack.pop();
}

int Stack::MinStack::top()
{
    return stack.top();
}

int Stack::MinStack::getMin()
{
    return minstack.top();
}
