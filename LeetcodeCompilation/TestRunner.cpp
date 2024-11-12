#include "TestRunner.h"
#include "ArrayAndHashingFactory.h"
#include "BacktrackingFactory.h"
#include "BinarySearchFactory.h"
#include "BitManipulationFactory.h"
#include "DynamicProgrammingFactory.h"
#include "GraphFactory.h"
#include "GreedyFactory.h"
#include "HeapAndPriorityQueueFactory.h"
#include "IntervalsFactory.h"
#include "LinkedListFactory.h"
#include "MathAndGeometryFactory.h"
#include "SlidingWindowFactory.h"
#include "StackFactory.h"
#include "TreeFactory.h"
#include "TrieFactory.h"
#include "TwoPointersFactory.h"

#include <iostream>


std::unique_ptr<TestRunner> TestRunner::instance = nullptr;

TestRunner& TestRunner::getInstance()
{
    if (!instance)
        instance = std::unique_ptr<TestRunner>(new TestRunner);
    return *instance;
}

void TestRunner::runAllTests()
{
    std::vector<std::string> testerTypes =
    {
        "ArrayAndHashing", "Backtracking", "BinarySearch",
        "BitManipulation", "DynamicProgramming", "Graph",
        "Greedy", "HeapAndPriorityQueue", "Intervals",
        "LinkedList", "MathAndGeometry", "SlidingWindow",
        "Stack", "Tree", "Trie", "TwoPointers"
    };

    std::vector<std::unique_ptr<Tester>> testers;
    for (std::string testerType : testerTypes)
        testers.push_back(buildConfiguredTester(testerType, true));

    int numTests = 0;
    for (auto& tester : testers)
    {
        bool result = tester->testAllProblems();
        std::cout << tester->getTestLog();
        printTestResults(result, tester->getName());
        numTests += static_cast<int>(tester->getNumTests());
    }

    std::cout << "\nALL TESTS PASSED!!! \n";
    std::cout << "\nTests Run: " << numTests << "\n";
    std::cout << "\nExiting Test Runner...\n";
}


void TestRunner::printTestResults(bool result, const std::string& name)
{
    if (result)
    {
        std::cout << "\n##########################################\n"
                  << "All " << name << " tests passed.\n"
                  << "##########################################\n";
    }
    else
    {
        std::cout << "\n##########################################\n"
                  << "Something in " << name << " tests failed.\n"
                  << "##########################################\n";
    }
}

std::unique_ptr<AbstractBuilder> TestRunner::makeFactoryBuilder(const std::string& factoryName)
{
    if      (factoryName.compare("ArraysAndHashing") == 0)
        return   std::make_unique<ArrayAndHashingFactory::Builder>();
    else if (factoryName.compare("Backtracking") == 0)
        return   std::make_unique<BacktrackingFactory::Builder>();
    else if (factoryName.compare("BinarySearch") == 0)
        return   std::make_unique<BinarySearchFactory::Builder>();
    else if (factoryName.compare("BitManipulation") == 0)
        return   std::make_unique<BitManipulationFactory::Builder>();
    else if (factoryName.compare("DynamicProgramming") == 0)
        return   std::make_unique<DynamicProgrammingFactory::Builder>();
    else if (factoryName.compare("Graph") == 0)
        return   std::make_unique<GraphFactory::Builder>();
    else if (factoryName.compare("Greedy") == 0)
        return   std::make_unique<GreedyFactory::Builder>();
    else if (factoryName.compare("HeapAndPriorityQueue") == 0)
        return   std::make_unique<HeapAndPriorityQueueFactory::Builder>();
    else if (factoryName.compare("Intervals") == 0)
        return   std::make_unique<IntervalsFactory::Builder>();
    else if (factoryName.compare("LinkedList") == 0)
        return   std::make_unique<LinkedListFactory::Builder>();
    else if (factoryName.compare("MathAndGeometry") == 0)
        return   std::make_unique<MathAndGeometryFactory::Builder>();
    else if (factoryName.compare("SlidingWindow") == 0)
        return   std::make_unique<SlidingWindowFactory::Builder>();
    else if (factoryName.compare("Stack") == 0)
        return   std::make_unique<StackFactory::Builder>();
    else if (factoryName.compare("Tree") == 0)
        return   std::make_unique<TreeFactory::Builder>();
    else if (factoryName.compare("Trie") == 0)
        return   std::make_unique<TrieFactory::Builder>();
    else if (factoryName.compare("TwoPointers") == 0)
        return   std::make_unique<TwoPointersFactory::Builder>();
    else return  std::make_unique<ArrayAndHashingFactory::Builder>(); // default
}

std::unique_ptr<Tester> TestRunner::buildConfiguredTester(const std::string& factoryName, bool verbose, bool isSolutionOnly, bool isParallel, std::string customName)
{
    return makeFactoryBuilder(factoryName)
            ->setVerbose(verbose)
            ->setIsSolutionOnly(isSolutionOnly)
            ->setIsParallel(isParallel)
            ->setCustomName(customName)
            ->buildTester();
}

