#pragma once

#include "TwoPointers.h"
#include "Tester.h"


class TwoPointersTester : public Tester
{
public:
    TwoPointersTester() : Tester { "Two Pointers" } {}
    bool testAllProblems() override;
    std::unique_ptr<Tester> clone() const override { return std::make_unique<TwoPointersTester>(*this); }

private:
    bool testIsPalindrome(std::string s, bool expected);
    bool testTwoSumSorted(std::vector<int> nums, int target, std::pair<int, int> expected);
    bool testThreeSum(std::vector<int> nums, int target, std::vector<std::tuple<int, int, int>> expected);
    bool testContainerWithMostWater(std::vector<int> height, int expected);
    bool testTrappingRainWater(std::vector<int> height, int expected);

    // Is Subsequence
    // Move Zeroes
    // Max number of K-Sum Pairs

    TwoPointers tp;
};