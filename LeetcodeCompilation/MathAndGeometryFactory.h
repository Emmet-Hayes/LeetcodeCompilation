#pragma once

#include "AbstractFactory.h"
#include "MathAndGeometryTester.h"


class MathAndGeometryFactory : public AbstractFactory
{
public:
    std::unique_ptr<Solution> createSolution() { return std::make_unique<MathAndGeometry>(); }
    std::unique_ptr<Tester>   createTester()   { return std::make_unique<MathAndGeometryTester>(); }

    class Builder : public AbstractBuilder
    {
    public:
        std::unique_ptr<Solution> buildSolution() override
        {
            auto solution = std::make_unique<MathAndGeometry>();
            // Apply other configurations...
            return solution;
        }

        std::unique_ptr<Tester> buildTester() override
        {
            auto tester = std::make_unique<MathAndGeometryTester>();
            tester->setVerbose(this->verbose);
            // Apply other configurations...
            return tester;
        }
    };
};
