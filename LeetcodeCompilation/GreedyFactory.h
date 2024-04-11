#pragma once

#include "AbstractFactory.h"
#include "GreedyTester.h"


class GreedyFactory : public AbstractFactory
{
public:
    std::unique_ptr<Solution> createSolution() { return std::make_unique<Greedy>(); }
    std::unique_ptr<Tester>   createTester() { return std::make_unique<GreedyTester>(); }

    class Builder : public AbstractBuilder
    {
    public:
        std::unique_ptr<Solution> buildSolution() override
        {
            auto solution = std::make_unique<Greedy>();
            // Apply other configurations...
            return solution;
        }

        std::unique_ptr<Tester> buildTester() override
        {
            auto tester = std::make_unique<GreedyTester>();
            tester->setVerbose(this->verbose);
            // Apply other configurations...
            return tester;
        }
    };
};
