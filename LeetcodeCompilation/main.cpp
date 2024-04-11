#include "TestRunner.h"


int main()
{
    TestRunner runner = TestRunner::getInstance();
    runner.runAllTests();
    return 0;
} 