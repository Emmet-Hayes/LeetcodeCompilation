#pragma once

#include "AbstractFactory.h"
#include "BacktrackingTester.h"


class BacktrackingFactory : public AbstractFactory
{
public:
    std::unique_ptr<Solution> createSolution() { return std::make_unique<Backtracking>(); }
    std::unique_ptr<Tester>   createTester()   { return std::make_unique<BacktrackingTester>(); }

    class Builder : public AbstractBuilder
    {
    public:
        std::unique_ptr<Solution> buildSolution() override
        {
            auto solution = std::make_unique<Backtracking>();
            // Apply other configurations...
            return solution;
        }

        std::unique_ptr<Tester> buildTester() override
        {
            auto tester = std::make_unique<BacktrackingTester>();
            tester->setVerbose(this->verbose);
            // Apply other configurations...
            return tester;
        }
    };
};