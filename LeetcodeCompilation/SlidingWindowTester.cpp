#include "SlidingWindowTester.h"


bool SlidingWindowTester::testAllProblems()
{
    addTestCase(testMaxProfit({ 7, 1, 5, 3, 6, 4 }, 5));
    addTestCase(testMaxProfit({ 7, 6, 4, 3, 1 }, 0));

    addTestCase(testLengthOfLongestSubstring("abcabcbb", 3));
    addTestCase(testLengthOfLongestSubstring("bbbbb", 1));
    addTestCase(testLengthOfLongestSubstring("pwwkew", 3));

    addTestCase(testLongestRepeatingCharacterReplacement("ABAB", 2, 4));
    addTestCase(testLongestRepeatingCharacterReplacement("AABABBA", 1, 4));

    addTestCase(testPermutationInString("ab", "eidbaooo", true));
    addTestCase(testPermutationInString("ab", "eidboaoo", false));

    addTestCase(testMinimumWindowSubstring("ADOBECODEBANC", "ABC", "BANC"));
    addTestCase(testMinimumWindowSubstring("a", "a", "a"));
    addTestCase(testMinimumWindowSubstring("a", "aa", ""));

    addTestCase(testSlidingWindowMaximum({ 1, 3, -1, -3, 5, 3, 6, 7 }, 3, { 3, 3, 5, 5, 6, 7 }));
    addTestCase(testSlidingWindowMaximum({ 1 }, 1, { 1 }));

    return runAllTests();
}

bool SlidingWindowTester::testMaxProfit(std::vector<int> prices, int expected)
{
    int actual = sw.bestTimeToBuyAndSellStock(prices);
    if (getVerbose())
    {
        ss << "\nMax Profit Test Run On Input Vector:\n[ ";
        for (int val : prices)
            ss << val << " ";
        ss << "]\nResult: " << actual << " | Expected: " << expected << "\n";
    }
    return actual == expected;
}

bool SlidingWindowTester::testLengthOfLongestSubstring(std::string s, int expected)
{
    int actual = sw.lengthOfLongestSubstring(s);
    if (getVerbose())
        ss << "\nLength of Longest Substring Test Run on Input String: " << s << "\nResult: " << actual 
           << " | Expected: " << expected << "\n";
    return actual == expected;
}

bool SlidingWindowTester::testLongestRepeatingCharacterReplacement(std::string s, int k, int expected)
{
    int actual = sw.longestRepeatingCharacterReplacement(s, k);
    if (getVerbose())
        ss << "\nLongest Character Replacement Test Run on Input String: " << s << "\nk: " << k 
           << "\nResult: " << actual << " | Expected: " << expected << "\n";
    return actual == expected;
}

bool SlidingWindowTester::testPermutationInString(std::string s1, std::string s2, bool expected)
{
    bool actual = sw.permutationInString(s1, s2);
    if (getVerbose())
        ss << "\nPermutation in String Test Run on Input Strings: " << s1 << " and " << s2
        << "\nResult: " << actual << " | Expected: " << expected << "\n";
    return actual == expected;
}

bool SlidingWindowTester::testMinimumWindowSubstring(std::string s, std::string t, std::string expected)
{
    std::string actual = sw.minimumWindowSubstring(s, t);
    if (getVerbose())
        ss << "\nMinimum Window Substring Test Run on Input Strings: " << s << " and " << t
        << "\nResult: " << actual << " | Expected: " << expected << "\n";
    return actual.compare(expected) == 0;
}

bool SlidingWindowTester::testSlidingWindowMaximum(std::vector<int> nums, int k, std::vector<int> expected)
{
    std::vector<int> actual = sw.maxSlidingWindow(nums, k);
    if (getVerbose())
    {
        ss << "\nSliding Window Maximum Test Run on Input Vector: [ ";
        for (int val : nums)
            ss << val << " ";
        ss << "\nk: " << k << "\nResult:   [ ";
        for (int val : actual)
            ss << val << " "; 
        ss << "]\nExpected: [ ";
        for (int val : expected)
            ss << val << " "; 
        ss << "]\n";
    }
    if (actual.size() != expected.size()) return false;
    for (int i = 0; i < expected.size(); ++i)
        if (actual[i] != expected[i])
            return false;
    return true;
}
