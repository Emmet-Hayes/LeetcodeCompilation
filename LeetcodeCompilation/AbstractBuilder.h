#pragma once

#include "Solution.h"
#include "Tester.h"

#include <memory>


class AbstractBuilder
{
public:
    virtual std::unique_ptr<Solution> buildSolution() = 0;
    virtual std::unique_ptr<Tester> buildTester() = 0;
    virtual ~AbstractBuilder() = default;

    AbstractBuilder& setVerbose(bool _verbose)
    {
        verbose = _verbose;
        return *this;
    }

protected:
    bool verbose = false;
};