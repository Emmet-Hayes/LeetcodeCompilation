#pragma once

#include "Solution.h"
#include "Tester.h"

#include <memory>


class AbstractFactory
{
public:
    virtual std::unique_ptr<Solution> createSolution() = 0;
    virtual std::unique_ptr<Tester>   createTester()   = 0;
};