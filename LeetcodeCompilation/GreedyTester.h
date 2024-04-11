#pragma once

#include "Greedy.h"
#include "Tester.h"


class GreedyTester : public Tester
{
public:
    GreedyTester() : Tester { "Greedy" } {}
    bool testAllProblems() override;
    std::unique_ptr<Tester> clone() const override { return std::make_unique<GreedyTester>(*this); }

private:
    bool testMaximumSubarray(std::vector<int> nums, int expected);
    bool testJumpGame(std::vector<int> nums, bool expected);
    bool testJumpGameMinJumps(std::vector<int> nums, int expected);
    bool testCanCompleteCircuit(std::vector<int> gas, std::vector<int> cost, int expected);
    bool testHandOfStraights(std::vector<int> hand, int groupSize, bool expected);
    bool testMergeTriplets(std::vector<std::vector<int>> triplets, std::vector<int> target, bool expected);
    bool testPartitionLabels(std::string s, std::vector<int> expected);
    bool testCheckValidParenthesis(std::string s, bool expected);

    // Maximum Sum Circular Subarray

    Greedy g;
};