#include "GreedyTester.h"


bool GreedyTester::testAllProblems()
{
    addTestCase(testMaximumSubarray({ -2, 1, -3, 4, -1, 2, 1, -5, 4 }, 6));
    addTestCase(testMaximumSubarray({ 1 }, 1));
    addTestCase(testMaximumSubarray({ 5, 4, -1, 7, 8 }, 23));

    addTestCase(testJumpGame({ 2, 3, 1, 1, 4 }, true));
    addTestCase(testJumpGame({ 3, 2, 1, 0, 4 }, false));

    addTestCase(testJumpGameMinJumps({ 2, 3, 1, 1, 4 }, 2));
    addTestCase(testJumpGameMinJumps({ 2, 3, 0, 1, 4 }, 2));

    addTestCase(testCanCompleteCircuit({ 1, 2, 3, 4, 5 }, { 3, 4, 5, 1, 2 }, 3));
    addTestCase(testCanCompleteCircuit({ 2, 3, 4 }, { 3, 4, 3 }, -1));

    addTestCase(testHandOfStraights({ 1, 2, 3, 6, 2, 3, 4, 7, 8 }, 3, true));
    addTestCase(testHandOfStraights({ 1, 2, 3, 4, 5 }, 4, false));

    addTestCase(testMergeTriplets({ { 2, 5, 3 }, { 1, 8, 4 }, { 1, 7, 5 } }, { 2, 7, 5 }, true));
    addTestCase(testMergeTriplets({ { 3, 4, 5 }, { 4, 5,  6 } }, { 3, 2, 5 }, false));
    addTestCase(testMergeTriplets({ { 2, 5, 3 }, { 2, 3, 4 }, { 1, 2, 5 }, { 5, 2, 3 } }, { 5, 5, 5 }, true));

    addTestCase(testPartitionLabels("ababcbacadefegdehijhklij", { 9, 7, 8 }));
    addTestCase(testPartitionLabels("eccbbbbdec", { 10 }));

    addTestCase(testCheckValidParenthesis("()", true));
    addTestCase(testCheckValidParenthesis("(*)", true));
    addTestCase(testCheckValidParenthesis("(*))", true));

    return runAllTests();
}

bool GreedyTester::testMaximumSubarray(std::vector<int> nums, int expected)
{
    int actual = g.maximumSubarray(nums);
    if (getVerbose())
    {
        ss << "\nMaximum Subarray Test Run On Input Vector:\n[ ";
        for (int val : nums)
            ss << val << " ";
        ss << "]\nResult: " << actual << " | Expected: " << expected << "\n";
    }
    return actual == expected;
}

bool GreedyTester::testJumpGame(std::vector<int> nums, bool expected)
{
    bool actual = g.jumpGame(nums);
    if (getVerbose())
    {
        ss << "\nJump Game Test Run On Input Vector:\n[ ";
        for (int val : nums)
            ss << val << " ";
        ss << "]\nResult: " << actual << " | Expected: " << expected << "\n";
    }
    return actual == expected;
}

bool GreedyTester::testJumpGameMinJumps(std::vector<int> nums, int expected)
{
    int actual = g.jumpGameMinJumps(nums);
    if (getVerbose())
    {
        ss << "\nJump Game Minimum Jumps Test Run On Input Vector:\n[ ";
        for (int val : nums)
            ss << val << " ";
        ss << "]\nResult: " << actual << " | Expected: " << expected << "\n";
    }
    return actual == expected;
}

bool GreedyTester::testCanCompleteCircuit(std::vector<int> gas, std::vector<int> cost, int expected)
{
    int actual = g.canCompleteCircuit(gas, cost);
    if (getVerbose())
    {
        ss << "\nCan Complete Circuit Test Run On Input Vectors:\nGas: [ ";
        for (int val : gas)
            ss << val << " ";
        ss << "]\nCost: [ ";
        for (int val : cost)
            ss << val << " ";
        ss << "\nResult: " << actual << " | Expected: " << expected << "\n";
    }
    return actual == expected;
}

bool GreedyTester::testHandOfStraights(std::vector<int> hand, int groupSize, bool expected)
{
    bool actual = g.handOfStraights(hand, groupSize);
    if (getVerbose())
    {
        ss << "\nHand of Straights Test Run On Input Vector:\nHand: [ ";
        for (int val : hand)
            ss << val << " ";
        ss << "]\nGroup Size: " << groupSize << "\nResult: " << actual << " | Expected: " << expected << "\n";
    }
    return actual == expected;
}

bool GreedyTester::testMergeTriplets(std::vector<std::vector<int>> triplets, std::vector<int> target, bool expected)
{
    bool actual = g.mergeTriplets(triplets, target);
    if (getVerbose())
    {
        ss << "\nMerge Triplets Test Run On Input Vector:\n[ ";
        for (std::vector<int> triplet : triplets)
            ss << "{ " << triplet[0] << ", " << triplet[1] << ", " << triplet[2] << "} ";
        ss << "]\nTarget Triplet: { " << target[0] << ", " << target[1] << ", " << target[2] 
           << "}\nResult: " << actual << " | Expected: " << expected << "\n";
    }
    return actual == expected;
}

bool GreedyTester::testPartitionLabels(std::string s, std::vector<int> expected)
{
    std::vector<int> actual = g.partitionLabels(s);
    if (getVerbose())
    {
        ss << "\nPartition Labels Test Run on Input String: " << s << "\nResults: [ ";
        for (int val : actual)
            ss << val << " ";
        ss << "]\nExpected: [ ";
        for (int val : expected)
            ss << val << " ";
        ss << "]\n";
    }
    if (actual.size() != expected.size())
        return false;
    for (unsigned i = 0; i < expected.size(); ++i)
        if (actual[i] != expected[i])
            return false;
    return true;
}

bool GreedyTester::testCheckValidParenthesis(std::string s, bool expected)
{
    bool actual = g.checkValidParenthesis(s);
    if (getVerbose())
        ss << "\nCheck Valid Parenthesis Test Run on Input String: " << s << "\nResults: " << actual << " | Expected: " << expected << "\n";
    return actual == expected;
}
