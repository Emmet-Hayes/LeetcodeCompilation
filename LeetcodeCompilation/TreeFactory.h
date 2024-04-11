#pragma once

#include "AbstractFactory.h"
#include "TreeTester.h"


class TreeFactory : public AbstractFactory
{
public:
    std::unique_ptr<Solution> createSolution() { return std::make_unique<Tree>(); }
    std::unique_ptr<Tester>   createTester() { return std::make_unique<TreeTester>(); }

    class Builder : public AbstractBuilder
    {
    public:
        std::unique_ptr<Solution> buildSolution() override
        {
            auto solution = std::make_unique<Tree>();
            // Apply other configurations...
            return solution;
        }

        std::unique_ptr<Tester> buildTester() override
        {
            auto tester = std::make_unique<TreeTester>();
            tester->setVerbose(this->verbose);
            // Apply other configurations...
            return tester;
        }
    };
};
