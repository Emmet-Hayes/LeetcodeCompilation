#include "Tester.h"

bool Tester::runAllTests()
{
    for (int i = 0; i < testResults.size(); ++i)
        if (testResults[i] != true)
            return false;
    return true;
}

void Tester::addTestCase(bool result)
{
    testResults.push_back(result);
}
