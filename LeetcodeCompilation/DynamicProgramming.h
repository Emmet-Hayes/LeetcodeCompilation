#pragma once

#include "Solution.h"

#include <vector>


class DynamicProgramming : public Solution
{
public:
    DynamicProgramming() : Solution("DynamicProgramming", "Common challenge problems involving dynamic programming algorithms.") {}
    std::unique_ptr<Solution> clone() const override { return std::make_unique<DynamicProgramming>(*this); }
    
    // 1D problems
    int climbingStairs(int n);
    int minCostClimbingStairs(std::vector<int>& cost);
    int houseRobber(const std::vector<int>& nums);
    int houseRobberCircular(const std::vector<int>& nums);
    std::string longestPalindrome(const std::string& s);
    int countPalindromicSubstrings(const std::string& s);
    int numWaysToDecode(const std::string& s);
    int coinChange(const std::vector<int>& coins, int amount);
    int maximumProductSubarray(const std::vector<int>& nums);
    bool wordBreak(const std::string& s, const std::vector<std::string>& wordDict);
    int longestIncreasingSubsequence(const std::vector<int>& nums);
    bool canPartition(const std::vector<int>& nums);

    // 2D problems
    int uniquePaths(int m, int n);
    int longestCommonSubsequence(const std::string& text1, const std::string& text2);
    int buyAndSellStockWithCooldown(const std::vector<int>& prices);
    int coinChangeNumCombinations(const std::vector<int>& coins, int amount);
    int findTargetSumWays(const std::vector<int>& nums, int target);
    int editDistance(const std::string& word1, const std::string& word2);
    bool isInterleaved(const std::string& s1, const std::string& s2, const std::string& s3);
    unsigned long long distinctSubsequences(const std::string& s, const std::string& t);
    int longestIncreasingPath(const std::vector<std::vector<int>>& matrix);
    bool isMatchRegex(const std::string& s, const std::string& p);
    int maxBurstBalloons(std::vector<int>& nums);

    // Triangle
    // Minimum Path Sum
    // Unique Paths 2
    // Longest Palindromic Substring    
    // Best Time To Buy And Sell Stock
    // Best Time To Buy And Sell Stock 2
    // Buy And Sell Stock 4
    // Maximal Square
    // N-th Tribonacci Number
    // Domino and Tromino Tiling
    // Buy and Sell with Transaction Fee
    // Pascals Triangle
    // Perfect Squares
    // Partition equal Subset Sum

private:
    int houseRobberHelper(const std::vector<int>& nums, int start, int end);
    int expandPalindrome(const std::string& s, int left, int right);
    int expandPalindromeCount(const std::string& s, int left, int right);
    int dfsLIP(const std::vector<std::vector<int>>& matrix, std::vector<std::vector<int>>& dp, int i, int j, int prevVal);
};