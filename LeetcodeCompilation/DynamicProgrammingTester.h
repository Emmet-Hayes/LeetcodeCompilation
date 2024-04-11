#pragma once

#include "DynamicProgramming.h"
#include "Tester.h"


class DynamicProgrammingTester : public Tester
{
public:
    DynamicProgrammingTester() : Tester { "Dynamic Programming" } {}
    bool testAllProblems() override;
    std::unique_ptr<Tester> clone() const override { return std::make_unique<DynamicProgrammingTester>(*this); }

private:
    // 1D problems
    bool testClimbingStairs(int n, int expected);
    bool testMinCostClimbingStairs(std::vector<int> cost, int expected);
    bool testHouseRobber(std::vector<int> nums, int expected);
    bool testHouseRobberCircular(std::vector<int> nums, int expected);
    bool testLongestPalindrome(std::string s, std::string expected);
    bool testCountPalindromicSubstrings(std::string s, int expected);
    bool testNumWaysToDecode(std::string s, int expected);
    bool testCoinChange(std::vector<int> coins, int amount, int expected);
    bool testMaximumProductSubarray(std::vector<int> nums, int expected);
    bool testWordBreak(std::string s, std::vector<std::string> wordDict, bool expected);
    bool testLongestIncreasingSubsequence(std::vector<int> nums, int expected);
    bool testCanPartition(std::vector<int> nums, bool expected);

    // 2D problems
    bool testUniquePaths(int m, int n, int expected);
    bool testLongestCommonSubsequence(std::string text1, std::string text2, int expected);
    bool testBuyAndSellStockWithCooldown(std::vector<int> prices, int expected);
    bool testCoinChangeNumCombinations(std::vector<int> coins, int amount, int expected);
    bool testFindTargetSumWays(std::vector<int> nums, int target, int expected);
    bool testEditDistance(std::string word1, std::string word2, int expected);
    bool testIsInterleaved(std::string s1, std::string s2, std::string s3, bool expected);
    bool testDistinctSubsequences(std::string s, std::string t, unsigned long long expected);
    bool testLongestIncreasingPath(std::vector<std::vector<int>> matrix, int expected);
    bool testIsMatchRegex(std::string s, std::string p, bool expected);
    bool testMaxBurstBalloons(std::vector<int> nums, int expected);

    // Triangle
    // Minimum Path Sum
    // Unique Paths 2
    // Longest Palindromic Substring
    // Buy And Sell Stock 4
    // Maximal Square
    // N-th Tribonacci Number
    // Domino and Tromino Tiling
    // Buy and Sell with Transaction Fee
    // Pascals Triangle
    // Perfect Squares
    // Partition equal Subset Sum

    DynamicProgramming dp;
};