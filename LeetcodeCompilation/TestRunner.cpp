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
    // seems like a good place for a factory pattern
    std::vector<std::unique_ptr<AbstractFactory>> factories;

    std::vector<std::string> testerTypes =
    {
        "ArrayAndHashing", "Backtracking", "BinarySearch",
        "BitManipulation", "DynamicProgramming", "Graph",
        "Greedy", "HeapAndPriorityQueue", "Intervals",
        "LinkedList", "MathAndGeometry", "SlidingWindow",
        "Stack", "Tree", "Trie", "TwoPointers"
    };

    /*
    for (std::string testerType : testerTypes)
        factories.push_back(std::move(buildFactory(testerType)));
    
    std::vector<std::unique_ptr<Tester>> testers;
    for (auto& factory : factories)
        testers.push_back(std::move(factory->createTester())); */

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

    std::cout << "\nTests Run: " << numTests << "\n";
}


void TestRunner::printTestResults(bool result, const std::string& name)
{
    if (result == 1)
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

std::unique_ptr<AbstractFactory> TestRunner::buildFactory(const std::string& factoryName)
{
    if      (factoryName.compare("ArraysAndHashing") == 0)
        return   std::make_unique<ArrayAndHashingFactory>();
    else if (factoryName.compare("Backtracking") == 0)
        return   std::make_unique<BacktrackingFactory>();
    else if (factoryName.compare("BinarySearch") == 0)
        return   std::make_unique<BinarySearchFactory>();
    else if (factoryName.compare("BitManipulation") == 0)
        return   std::make_unique<BitManipulationFactory>();
    else if (factoryName.compare("DynamicProgramming") == 0)
        return   std::make_unique<DynamicProgrammingFactory>();
    else if (factoryName.compare("Graph") == 0)
        return   std::make_unique<GraphFactory>();
    else if (factoryName.compare("Greedy") == 0)
        return   std::make_unique<GreedyFactory>();
    else if (factoryName.compare("HeapAndPriorityQueue") == 0)
        return   std::make_unique<HeapAndPriorityQueueFactory>();
    else if (factoryName.compare("Intervals") == 0)
        return   std::make_unique<IntervalsFactory>();
    else if (factoryName.compare("LinkedList") == 0)
        return   std::make_unique<LinkedListFactory>();
    else if (factoryName.compare("MathAndGeometry") == 0)
        return   std::make_unique<MathAndGeometryFactory>();
    else if (factoryName.compare("SlidingWindow") == 0)
        return   std::make_unique<SlidingWindowFactory>();
    else if (factoryName.compare("Stack") == 0)
        return   std::make_unique<StackFactory>();
    else if (factoryName.compare("Tree") == 0)
        return   std::make_unique<TreeFactory>();
    else if (factoryName.compare("Trie") == 0)
        return   std::make_unique<TrieFactory>();
    else if (factoryName.compare("TwoPointers") == 0)
        return   std::make_unique<TwoPointersFactory>();
    else return  std::make_unique<ArrayAndHashingFactory>(); // default
}

std::unique_ptr<Tester> TestRunner::buildConfiguredTester(const std::string& factoryName, bool verbose)
{
    if (factoryName.compare("ArraysAndHashing") == 0)
    {
        ArrayAndHashingFactory::Builder builder;
        return builder.setVerbose(verbose).buildTester();
    }
    else if (factoryName.compare("Backtracking") == 0)
    {
        BacktrackingFactory::Builder builder;
        return builder.setVerbose(verbose).buildTester();
    }
    else if (factoryName.compare("BinarySearch") == 0)
    {
        BinarySearchFactory::Builder builder;
        return builder.setVerbose(verbose).buildTester();
    }
    else if (factoryName.compare("BitManipulation") == 0)
    {
        BitManipulationFactory::Builder builder;
        return builder.setVerbose(verbose).buildTester();
    }
    else if (factoryName.compare("DynamicProgramming") == 0)
    {
        DynamicProgrammingFactory::Builder builder;
        return builder.setVerbose(verbose).buildTester();
    }
    else if (factoryName.compare("Graph") == 0)
    {
        GraphFactory::Builder builder;
        return builder.setVerbose(verbose).buildTester();
    }
    else if (factoryName.compare("Greedy") == 0)
    {
        GreedyFactory::Builder builder;
        return builder.setVerbose(verbose).buildTester();
    }
    else if (factoryName.compare("HeapAndPriorityQueue") == 0)
    {
        HeapAndPriorityQueueFactory::Builder builder;
        return builder.setVerbose(verbose).buildTester();
    }
    else if (factoryName.compare("Intervals") == 0)
    {
        IntervalsFactory::Builder builder;
        return builder.setVerbose(verbose).buildTester();
    }
    else if (factoryName.compare("LinkedList") == 0)
    {
        LinkedListFactory::Builder builder;
        return builder.setVerbose(verbose).buildTester();
    }
    else if (factoryName.compare("MathAndGeometry") == 0)
    {
        MathAndGeometryFactory::Builder builder;
        return builder.setVerbose(verbose).buildTester();
    }
    else if (factoryName.compare("SlidingWindow") == 0)
    {
        SlidingWindowFactory::Builder builder;
        return builder.setVerbose(verbose).buildTester();
    }
    else if (factoryName.compare("Stack") == 0)
    {
        StackFactory::Builder builder;
        return builder.setVerbose(verbose).buildTester();
    }
    else if (factoryName.compare("Tree") == 0)
    {
        TreeFactory::Builder builder;
        return builder.setVerbose(verbose).buildTester();
    }
    else if (factoryName.compare("Trie") == 0)
    {
        TrieFactory::Builder builder;
        return builder.setVerbose(verbose).buildTester();
    }
    else if (factoryName.compare("TwoPointers") == 0)
    {
        TwoPointersFactory::Builder builder;
        return builder.setVerbose(verbose).buildTester();
    }
    else
    {
        ArrayAndHashingFactory::Builder builder;
        return builder.setVerbose(verbose).buildTester();
    }
}

