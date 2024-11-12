#pragma once

#include "AbstractFactory.h"
#include "AbstractBuilder.h"


class TestRunner
{
public:
    static TestRunner& getInstance();
    void runAllTests();

private:
    TestRunner() {};
    void printTestResults(bool result, const std::string& name);
    std::unique_ptr<AbstractBuilder> makeFactoryBuilder(const std::string& factoryName);
    std::unique_ptr<Tester> buildConfiguredTester(const std::string& factoryName, bool verbose = false, bool isSolutionOnly = false, bool isParallel = false, std::string customName = "Not Set");

    static std::unique_ptr<TestRunner> instance;
};