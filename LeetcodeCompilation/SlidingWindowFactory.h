#pragma once

#include "AbstractFactory.h"
#include "SlidingWindowTester.h"


class SlidingWindowFactory : public AbstractFactory
{
public:
    std::unique_ptr<Solution> createSolution() { return std::make_unique<SlidingWindow>(); }
    std::unique_ptr<Tester>   createTester()   { return std::make_unique<SlidingWindowTester>(); }

    class Builder : public AbstractBuilder
    {
    public:
        std::unique_ptr<Solution> buildSolution() override
        {
            auto solution = std::make_unique<SlidingWindow>();
            // Apply other configurations...
            return solution;
        }

        std::unique_ptr<Tester> buildTester() override
        {
            auto tester = std::make_unique<SlidingWindowTester>();
            tester->setVerbose(this->verbose);
            // Apply other configurations...
            return tester;
        }
    };
};
