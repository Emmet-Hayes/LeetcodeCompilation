#pragma once

#include "AbstractFactory.h"

#include <string>


class TestRunner
{
public:
    static TestRunner& getInstance();
    void runAllTests();

private:
    TestRunner() {};
    void printTestResults(bool result, const std::string& name);
    std::unique_ptr<AbstractFactory> buildFactory(const std::string& factoryName);
    std::unique_ptr<Tester> buildConfiguredTester(const std::string& factoryName, bool verbose = false);

    static std::unique_ptr<TestRunner> instance;
};