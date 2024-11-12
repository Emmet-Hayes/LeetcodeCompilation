#include "StackTester.h"


bool StackTester::testAllProblems()
{
    addTestCase(testValidParentheses("()", true));
    addTestCase(testValidParentheses("()[]{}", true));
    addTestCase(testValidParentheses("(]", false));

    addTestCase(testMinStack());

    addTestCase(testEvaluateReversePolishNotation({ "2", "1", "+", "3", "*" }, 9));
    addTestCase(testEvaluateReversePolishNotation({ "4", "13", "5", "/", "+" }, 6));
    addTestCase(testEvaluateReversePolishNotation(
        { "10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+" }, 22));

    addTestCase(testGenerateParentheses(3, { "((()))", "(()())", "(())()", "()(())", "()()()" }));
    addTestCase(testGenerateParentheses(1, { "()" }));

    addTestCase(testDailyTemperatures({ 73, 74, 75, 71, 69, 72, 76, 73 }, 
                                      { 1, 1, 4, 2, 1, 1, 0, 0 }));
    addTestCase(testDailyTemperatures({ 30, 40, 50, 60 }, { 1, 1, 1, 0 }));
    addTestCase(testDailyTemperatures({ 30, 60, 90 }, { 1, 1, 0 }));

    addTestCase(testCarFleet(12, { 10, 8, 0, 5, 3 }, { 2, 4, 1, 1, 3 }, 3));
    addTestCase(testCarFleet(10, { 3 }, { 3 }, 1));
    addTestCase(testCarFleet(100, { 0, 2, 4 }, { 4, 2, 1 }, 1));

    addTestCase(testLargestRectangleHistogram({ 2, 1, 5, 6, 2, 3 }, 10));
    addTestCase(testLargestRectangleHistogram({ 2, 4 }, 4));

    return runAllTests();
}

bool StackTester::testValidParentheses(std::string s, bool expected)
{
    bool actual = stack.validParentheses(s);
    if (getVerbose())
        ss << "\nValid Parentheses Test Run on Input String: " << s << "\nResult: " << actual
           << " | Expected: " << expected << "\n";
    return actual == expected;
}

bool StackTester::testMinStack()
{
    Stack::MinStack minStack;
    minStack.push(-2);
    minStack.push(0);
    minStack.push(-3);
    if (minStack.getMin() != -3)
        return false;
    minStack.pop();
    if (minStack.top() != 0)
        return false;
    if (minStack.getMin() != -2)
        return false;
    return true;
}

bool StackTester::testEvaluateReversePolishNotation(std::vector<std::string> tokens, int expected)
{
    int actual = stack.evaluateReversePolishNotation(tokens);
    if (getVerbose())
    {
        ss << "\nEvaluate Reverse Polish Notation Test Run on Input String Vector: [ ";
        for (std::string token : tokens)
            ss << token << " ";
        ss << "]\nResult: " << actual << " | Expected: " << expected << "\n";
    }
    return actual == expected;
}

bool StackTester::testGenerateParentheses(int n, std::vector<std::string> expected)
{
    std::vector<std::string> actual = stack.generateParenthesis(n);
    if (getVerbose())
    {
        ss << "\nGenerate Parentheses Test Run on Input Value: " << n << "\nResult:   [ ";
        for (std::string token : actual)
            ss << token << " ";
        ss << "]\nExpected: [ ";
        for (std::string token : expected)
            ss << token << " ";
        ss << "]\n";
    }
    if (actual.size() != expected.size()) return false;
    for (unsigned i = 0; i < expected.size(); ++i)
    {
        if (actual[i].size() != expected[i].size()) return false;
        for (unsigned j = 0; j < expected[i].size(); ++j)
            if (actual[i][j] != expected[i][j])
                return false;
    }
    return true;
}

bool StackTester::testDailyTemperatures(std::vector<int> temperatures, std::vector<int> expected)
{
    std::vector<int> actual = stack.dailyTemperatures(temperatures);
    if (getVerbose())
    {
        ss << "\nDaily Temperatures Test Run On Input Vector:\nTemperature: [ ";
        for (int val : temperatures)
            ss << val << " ";
        ss << "]\nResult:      [ ";
        for (int val : actual)
            ss << val << " ";
        ss << "]\nExpected:    [ ";
        for (int val : expected)
            ss << val << " ";
        ss << "]\n";
    }
    if (actual.size() != expected.size()) return false;
    for (unsigned i = 0; i < expected.size(); ++i)
        if (actual[i] != expected[i])
            return false;
    return true;
}

bool StackTester::testCarFleet(int target, std::vector<int> position, std::vector<int> speed, int expected)
{
    int actual = stack.carFleet(target, position, speed);
    if (getVerbose())
    {
        ss << "\nCar Fleet Test Run On Input Vectors:\nPosition: [ ";
        for (int val : position)
            ss << val << " ";
        ss << "]\nSpeed:    [ ";
        for (int val : speed)
            ss << val << " ";
        ss << "]\nResult: " << actual << " | Expected : " << expected << "\n";
    }
    return actual == expected;
}

bool StackTester::testLargestRectangleHistogram(std::vector<int> heights, int expected)
{
    int actual = stack.largestRectangleHistogram(heights);
    if (getVerbose())
    {
        ss << "\nLargest Rectangle Histogram Test Run On Input Vector:\n[ ";
        for (int val : heights)
            ss << val << " ";
        ss << "]\nResult: " << actual << " | Expected: " << expected << "\n";
    }
    return actual == expected;
}
