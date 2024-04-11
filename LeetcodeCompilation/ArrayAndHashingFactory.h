#pragma once

#include "AbstractFactory.h"
#include "AbstractBuilder.h"
#include "ArrayAndHashingTester.h"


class ArrayAndHashingFactory : public AbstractFactory
{
public:
    std::unique_ptr<Solution> createSolution() { return std::make_unique<ArrayAndHashing>(); }
    std::unique_ptr<Tester>   createTester()   { return std::make_unique<ArrayAndHashingTester>(); }

    class Builder : public AbstractBuilder
    {
    public:
        std::unique_ptr<Solution> buildSolution() override
        {
            auto solution = std::make_unique<ArrayAndHashing>();
            // Apply other configurations...
            return solution;
        }

        std::unique_ptr<Tester> buildTester() override
        {
            auto tester = std::make_unique<ArrayAndHashingTester>();
            tester->setVerbose(this->verbose);
            // Apply other configurations...
            return tester;
        }
    };
};
