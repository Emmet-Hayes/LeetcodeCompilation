#pragma once

#include "Solution.h"

#include <tuple>
#include <vector>


class TwoPointers : public Solution
{
public:
    TwoPointers() : Solution("TwoPointers", "Common challenge problems involving variants of two-pointer algorithms.") {}
    std::unique_ptr<Solution> clone() const override { return std::make_unique<TwoPointers>(*this); }
    
    bool isPalindrome(std::string& s);
    std::pair<int, int> twoSumSorted(const std::vector<int>& nums, int target);
    std::vector<std::tuple<int, int, int>> threeSum(std::vector<int>& nums, int target);
    int containerWithMostWater(const std::vector<int>& height);
    int trappingRainWater(const std::vector<int>& height);

    // Is Subsequence
    // Move Zeroes
    // Max number of K-Sum Pairs
};