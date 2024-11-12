#pragma once

#include "AbstractFactory.h"
#include "DynamicProgrammingTester.h"


class DynamicProgrammingFactory : public AbstractFactory
{
public:
    std::unique_ptr<Solution> createSolution() { return std::make_unique<DynamicProgramming>(); }
    std::unique_ptr<Tester>   createTester()   { return std::make_unique<DynamicProgrammingTester>(); }

    class Builder : public AbstractBuilder
    {
    public:
        std::unique_ptr<Solution> buildSolution() override
        {
            auto solution = std::make_unique<DynamicProgramming>();
            // Apply other configurations...
            return solution;
        }

        std::unique_ptr<Tester> buildTester() override
        {
            auto tester = std::make_unique<DynamicProgrammingTester>();
            tester->setVerbose(this->verbose);
            // Apply other configurations...
            return tester;
        }
    };
};
