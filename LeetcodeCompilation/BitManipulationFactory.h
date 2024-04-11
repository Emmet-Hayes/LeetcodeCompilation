#pragma once

#include "AbstractFactory.h"
#include "BitManipulationTester.h"


class BitManipulationFactory : public AbstractFactory
{
public:
    std::unique_ptr<Solution> createSolution() { return std::make_unique<BitManipulation>(); }
    std::unique_ptr<Tester>   createTester() { return std::make_unique<BitManipulationTester>(); }

    class Builder : public AbstractBuilder
    {
    public:
        std::unique_ptr<Solution> buildSolution() override
        {
            auto solution = std::make_unique<BitManipulation>();
            // Apply other configurations...
            return solution;
        }

        std::unique_ptr<Tester> buildTester() override
        {
            auto tester = std::make_unique<BitManipulationTester>();
            tester->setVerbose(this->verbose);
            // Apply other configurations...
            return tester;
        }
    };
};
