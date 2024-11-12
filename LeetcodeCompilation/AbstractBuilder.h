#pragma once

#include "Solution.h"
#include "Tester.h"

#include <memory>


class AbstractBuilder
{
public:
    virtual std::unique_ptr<Solution> buildSolution() = 0;
    virtual std::unique_ptr<Tester> buildTester()     = 0;
    virtual ~AbstractBuilder() = default;

    AbstractBuilder* setVerbose(bool _verbose)
    {
        verbose = _verbose;
        return this;
    }

    AbstractBuilder* setIsSolutionOnly(bool _isSolutionOnly)
    {
        isSolutionOnly = _isSolutionOnly;
        return this;
    }

    AbstractBuilder* setIsParallel(bool _isParallel)
    {
        isParallel =_isParallel;
        return this;
    }

    AbstractBuilder* setCustomName(std::string _customName)
    {
        customName = _customName;
        return this;
    }

protected:
    bool verbose = false;
    bool isSolutionOnly = false;
    bool isParallel = false;
    std::string customName = "Not Set";
};