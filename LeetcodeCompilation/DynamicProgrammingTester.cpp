#include "DynamicProgrammingTester.h"


bool DynamicProgrammingTester::testAllProblems()
{
    addTestCase(testClimbingStairs(2, 2));
    addTestCase(testClimbingStairs(3, 3));
    
    addTestCase(testMinCostClimbingStairs({ 10, 15, 20 }, 15));
    addTestCase(testMinCostClimbingStairs({ 1, 100, 1, 1, 1, 100, 1, 1, 100, 1 }, 6));

    addTestCase(testHouseRobber({ 1, 2, 3, 1 }, 4));
    addTestCase(testHouseRobber({ 2, 7, 9, 3, 1 }, 12));

    addTestCase(testHouseRobberCircular({ 2, 3, 2 }, 3));
    addTestCase(testHouseRobberCircular({ 1, 2, 3, 1 }, 4));
    addTestCase(testHouseRobberCircular({ 1, 2, 3 }, 3));

    addTestCase(testLongestPalindrome("babad", "bab"));
    addTestCase(testLongestPalindrome("cbbd", "bb"));

    addTestCase(testCountPalindromicSubstrings("abc", 3));
    addTestCase(testCountPalindromicSubstrings("aaa", 6));

    addTestCase(testNumWaysToDecode("12", 2));
    addTestCase(testNumWaysToDecode("226", 3));
    addTestCase(testNumWaysToDecode("06", 0));

    addTestCase(testCoinChange({ 1, 2, 5 }, 11, 3));
    addTestCase(testCoinChange({ 2 }, 3, -1));
    addTestCase(testCoinChange({ 1 }, 0, 0));

    addTestCase(testMaximumProductSubarray({ 2, 3, -2, 4 }, 6));
    addTestCase(testMaximumProductSubarray({ -2, 0, -1 }, 0));

    addTestCase(testWordBreak("leetcode", { "leet", "code" }, true));
    addTestCase(testWordBreak("applepenapple", { "apple", "pen" }, true));
    addTestCase(testWordBreak("catsandog", { "cats", "dog", "sand", "and", "cat" }, false));

    addTestCase(testLongestIncreasingSubsequence({ 10, 9, 2, 5, 3, 7, 101, 18 }, 4));
    addTestCase(testLongestIncreasingSubsequence({ 0, 1, 0, 3, 2, 3 }, 4));
    addTestCase(testLongestIncreasingSubsequence({ 7, 7, 7, 7, 7, 7, 7 }, 1));

    addTestCase(testCanPartition({ 1, 5, 11, 5 }, true));
    addTestCase(testCanPartition({ 1, 2, 3, 5 }, false));

    addTestCase(testUniquePaths(3, 7, 28));
    addTestCase(testUniquePaths(3, 2, 3));

    addTestCase(testLongestCommonSubsequence("abcde", "ace", 3));
    addTestCase(testLongestCommonSubsequence("abc", "abc", 3));
    addTestCase(testLongestCommonSubsequence("abc", "def", 0));

    addTestCase(testBuyAndSellStockWithCooldown({ 1, 2, 3, 0, 2 }, 3));
    addTestCase(testBuyAndSellStockWithCooldown({ 1 }, 0));

    addTestCase(testCoinChangeNumCombinations({ 1, 2, 5 }, 5, 4));
    addTestCase(testCoinChangeNumCombinations({ 2 }, 3, 0));
    addTestCase(testCoinChangeNumCombinations({ 10 }, 10, 1));

    addTestCase(testFindTargetSumWays({ 1, 1, 1, 1, 1 }, 3, 5));
    addTestCase(testFindTargetSumWays({ 1 }, 1, 1));

    addTestCase(testIsInterleaved("aabcc", "dbbca", "aadbbcbcac", true));
    addTestCase(testIsInterleaved("aabcc", "dbbca", "aadbbbaccc", false));

    addTestCase(testLongestIncreasingPath({ { 9, 9, 4 },
                                            { 6, 6, 8 },
                                            { 2, 1, 1 } }, 4));
    addTestCase(testLongestIncreasingPath({ { 3, 4, 5 },
                                            { 3, 2, 6 },
                                            { 2, 2, 1 } }, 4));
    addTestCase(testLongestIncreasingPath({ { 1 } }, 1));

    addTestCase(testDistinctSubsequences("rabbbit", "rabbit", 3));
    addTestCase(testDistinctSubsequences("babgbag", "bag", 5));

    addTestCase(testEditDistance("horse", "ros", 3));
    addTestCase(testEditDistance("intention", "execution", 5));

    addTestCase(testMaxBurstBalloons({ 3, 1, 5, 8 }, 167));
    addTestCase(testMaxBurstBalloons({ 1, 5 }, 10));

    addTestCase(testIsMatchRegex("aa", "a", false));
    addTestCase(testIsMatchRegex("aa", "a*", true));
    addTestCase(testIsMatchRegex("ab", ".*", true));

    return runAllTests();
}

bool DynamicProgrammingTester::testClimbingStairs(int n, int expected)
{
    int actual = dp.climbingStairs(n);
    if (getVerbose())
        ss << "\nClimbing Stairs Test Run On Input Value: " << n << "\nResult: " << actual << " | Expected: " << expected << "\n";
    return actual == expected;
}

bool DynamicProgrammingTester::testMinCostClimbingStairs(std::vector<int> cost, int expected)
{
    int actual = dp.minCostClimbingStairs(cost);
    if (getVerbose())
    {
        ss << "\nMinimum Cost Climbing Stairs Test Run On Input Vector:\n[ ";
        for (int val : cost)
            ss << val << " ";
        ss << "]\nResult: " << actual << " | Expected: " << expected << "\n";
    }
    return actual == expected;
}

bool DynamicProgrammingTester::testHouseRobber(std::vector<int> nums, int expected)
{
    int actual = dp.houseRobber(nums);
    if (getVerbose())
    {
        ss << "\nHouse Robber Test Run On Input Vector:\n[ ";
        for (int val : nums)
            ss << val << " ";
        ss << "]\nResult: " << actual << " | Expected: " << expected << "\n";
    }
    return actual == expected;
}

bool DynamicProgrammingTester::testHouseRobberCircular(std::vector<int> nums, int expected)
{
    int actual = dp.houseRobberCircular(nums);
    if (getVerbose())
    {
        ss << "\nHouse Robber Test Run On Input Vector:\n[ ";
        for (int val : nums)
            ss << val << " ";
        ss << "]\nResult: " << actual << " | Expected: " << expected << "\n";
    }
    return actual == expected;
}

bool DynamicProgrammingTester::testLongestPalindrome(std::string s, std::string expected)
{
    std::string actual = dp.longestPalindrome(s);
    if (getVerbose())
        ss << "\nLongest Palindrome Test Run On Input String: " << s << "\nResult: " << actual << " | Expected: " << expected << "\n";
    return actual.compare(expected) == 0;
}

bool DynamicProgrammingTester::testCountPalindromicSubstrings(std::string s, int expected)
{
    int actual = dp.countPalindromicSubstrings(s);
    if (getVerbose())
        ss << "\nCount Palindromic Substrings Test Run On Input String: " << s << "\nResult: " << actual << " | Expected: " << expected << "\n";
    return actual == expected;
}

bool DynamicProgrammingTester::testNumWaysToDecode(std::string s, int expected)
{
    int actual = dp.numWaysToDecode(s);
    if (getVerbose())
        ss << "\nNumber of Ways to Decode Test Run On Input String: " << s << "\nResult: " << actual << " | Expected: " << expected << "\n";
    return actual == expected;
}

bool DynamicProgrammingTester::testCoinChange(std::vector<int> coins, int amount, int expected)
{
    int actual = dp.coinChange(coins, amount);
    if (getVerbose())
    {
        ss << "\nCoin Change Test Run On Input Vector:\n[ ";
        for (int val : coins)
            ss << val << " ";
        ss << "]\nAmount: " << amount << "\nResult: " << actual << " | Expected : " << expected << "\n";
    }
    return actual == expected;
}

bool DynamicProgrammingTester::testMaximumProductSubarray(std::vector<int> nums, int expected)
{
    int actual = dp.maximumProductSubarray(nums);
    if (getVerbose())
    {
        ss << "\nMaximum Product Subarray Test Run On Input Vector:\n[ ";
        for (int val : nums)
            ss << val << " ";
        ss << "]\nResult: " << actual << " | Expected: " << expected << "\n";
    }
    return actual == expected;
}

bool DynamicProgrammingTester::testWordBreak(std::string s, std::vector<std::string> wordDict, bool expected)
{
    bool actual = dp.wordBreak(s, wordDict);
    if (getVerbose())
    {
        ss << "\nWord Break Test Run On Input String: " << s << "\nWord Dictionary: [ ";
        for (std::string word : wordDict)
            ss << word << " ";
        ss << "]\nResult: " << actual << " | Expected: " << expected << "\n";
    }
    return actual == expected;
}

bool DynamicProgrammingTester::testLongestIncreasingSubsequence(std::vector<int> nums, int expected)
{
    int actual = dp.longestIncreasingSubsequence(nums);
    if (getVerbose())
    {
        ss << "\nLongest Increasing Subsequence Test Run On Input Vector:\n[ ";
        for (int val : nums)
            ss << val << " ";
        ss << "]\nResult: " << actual << " | Expected: " << expected << "\n";
    }
    return actual == expected;
}

bool DynamicProgrammingTester::testCanPartition(std::vector<int> nums, bool expected)
{
    bool actual = dp.canPartition(nums);
    if (getVerbose())
    {
        ss << "\nCan Partition Test Run On Input Vector:\n[ ";
        for (int val : nums)
            ss << val << " ";
        ss << "]\nResult: " << actual << " | Expected: " << expected << "\n";
    }
    return actual == expected;
}

bool DynamicProgrammingTester::testUniquePaths(int m, int n, int expected)
{
    int actual = dp.uniquePaths(m, n);
    if (getVerbose())
        ss << "\nUnique Paths Test Run On Input Values: " << m << " and " << n << "\nResult: " << actual << " | Expected: " << expected << "\n";
    return actual == expected;
}

bool DynamicProgrammingTester::testLongestCommonSubsequence(std::string text1, std::string text2, int expected)
{
    int actual = dp.longestCommonSubsequence(text1, text2);
    if (getVerbose())
        ss << "\nLongest Common Subsequence Test Run On Input Strings: " << text1 << " and " << text2 << "\nResult: " << actual << " | Expected: " << expected << "\n";
    return actual == expected;
}

bool DynamicProgrammingTester::testBuyAndSellStockWithCooldown(std::vector<int> prices, int expected)
{
    int actual = dp.buyAndSellStockWithCooldown(prices);
    if (getVerbose())
    {
        ss << "\nBuy And Sell Stock with Cooldown Test Run On Input Vector:\n[ ";
        for (int val : prices)
            ss << val << " ";
        ss << "]\nResult: " << actual << " | Expected: " << expected << "\n";
    }
    return actual == expected;
}

bool DynamicProgrammingTester::testCoinChangeNumCombinations(std::vector<int> coins, int amount, int expected)
{
    int actual = dp.coinChangeNumCombinations(coins, amount);
    if (getVerbose())
    {
        ss << "\nCoin Change with Number of Combinations Test Run On Input Vector:\n[ ";
        for (int val : coins)
            ss << val << " ";
        ss << "]\nAmount: " << amount << "\nResult: " << actual << " | Expected : " << expected << "\n";
    }
    return actual == expected;
}

bool DynamicProgrammingTester::testFindTargetSumWays(std::vector<int> nums, int target, int expected)
{
    int actual = dp.findTargetSumWays(nums, target);
    if (getVerbose())
    {
        ss << "\nFind Target Sum Ways Test Run On Input Vector:\n[ ";
        for (int val : nums)
            ss << val << " ";
        ss << "]\nTarget: " << target << "\nResult: " << actual << " | Expected : " << expected << "\n";
    }
    return actual == expected;
}

bool DynamicProgrammingTester::testEditDistance(std::string word1, std::string word2, int expected)
{
    int actual = dp.editDistance(word1, word2);
    if (getVerbose())
        ss << "\nEdit Distance Test Run On Input Strings: " << word1 << " and " << word2 << "\nResult: " << actual << " | Expected: " << expected << "\n";
    return actual == expected;
}

bool DynamicProgrammingTester::testIsInterleaved(std::string s1, std::string s2, std::string s3, bool expected)
{
    bool actual = dp.isInterleaved(s1, s2, s3);
    if (getVerbose())
        ss << "\nIs Interleaved Test Run On Input Strings: " << s1 << ", " << s2 << " and " << s3 << "\nResult: " << actual << " | Expected: " << expected << "\n";
    return actual == expected;
}

bool DynamicProgrammingTester::testDistinctSubsequences(std::string s, std::string t, unsigned long long expected)
{
    unsigned long long actual = dp.distinctSubsequences(s, t);
    if (getVerbose())
        ss << "\nDistinct Subsequences Test Run On Input Strings: " << s << " and " << t << "\nResult: " << actual << " | Expected: " << expected << "\n";
    return actual == expected;
}

bool DynamicProgrammingTester::testLongestIncreasingPath(std::vector<std::vector<int>> matrix, int expected)
{
    int actual = dp.longestIncreasingPath(matrix);
    if (getVerbose())
    {
        ss << "\nLongest Increasing Path Test Run On Input Matrix:\n\n"; 
        for (int i = 0; i < matrix.size(); ++i)
        {
            for (int val : matrix[i])
                ss << val << " ";
            ss << "\n";
        }
        
        ss << "\nResult: " << actual << " | Expected: " << expected << "\n";
    }
    return actual == expected;
}

bool DynamicProgrammingTester::testIsMatchRegex(std::string s, std::string p, bool expected)
{
    bool actual = dp.isMatchRegex(s, p);
    if (getVerbose())
        ss << "\nIs Regex Match Test Run On Input Strings: " << s << " and " << p << "\nResult: " << actual << " | Expected: " << expected << "\n";
    return actual == expected;
}

bool DynamicProgrammingTester::testMaxBurstBalloons(std::vector<int> nums, int expected)
{
    int actual = dp.maxBurstBalloons(nums);
    if (getVerbose())
    {
        ss << "\nMaximum Burst Balloons Test Run On Input Vector:\n[ ";
        for (int val : nums)
            ss << val << " ";
        ss << "]\nResult: " << actual << " | Expected : " << expected << "\n";
    }
    return actual == expected;
}
