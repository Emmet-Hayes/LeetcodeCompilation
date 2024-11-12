#pragma once

#include "AbstractFactory.h"
#include "TwoPointersTester.h"


class TwoPointersFactory : public AbstractFactory
{
public:
    std::unique_ptr<Solution> createSolution() { return std::make_unique<TwoPointers>(); }
    std::unique_ptr<Tester>   createTester()   { return std::make_unique<TwoPointersTester>(); }

    class Builder : public AbstractBuilder
    {
    public:
        std::unique_ptr<Solution> buildSolution() override
        {
            auto solution = std::make_unique<TwoPointers>();
            // Apply other future configurations...
            return solution;
        }

        std::unique_ptr<Tester> buildTester() override
        {
            auto tester = std::make_unique<TwoPointersTester>();
            tester->setVerbose(this->verbose);
            // Apply other future configurations...
            return tester;
        }
    };
};
