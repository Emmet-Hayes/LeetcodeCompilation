#pragma once

#include "AbstractFactory.h"
#include "BinarySearchTester.h"


class BinarySearchFactory : public AbstractFactory
{
public:
    std::unique_ptr<Solution> createSolution() { return std::make_unique<BinarySearch>(); }
    std::unique_ptr<Tester>   createTester()   { return std::make_unique<BinarySearchTester>(); }

    class Builder : public AbstractBuilder
    {
    public:
        std::unique_ptr<Solution> buildSolution() override
        {
            auto solution = std::make_unique<BinarySearch>();
            // Apply other configurations...
            return solution;
        }

        std::unique_ptr<Tester> buildTester() override
        {
            auto tester = std::make_unique<BinarySearchTester>();
            tester->setVerbose(this->verbose);
            // Apply other configurations...
            return tester;
        }
    };
};
