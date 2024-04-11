#pragma once

#include "SlidingWindow.h"
#include "Tester.h"


class SlidingWindowTester : public Tester
{
public:
    SlidingWindowTester() : Tester { "Sliding Window" } {}
    bool testAllProblems() override;
    std::unique_ptr<Tester> clone() const override { return std::make_unique<SlidingWindowTester>(*this); }

private:
    bool testMaxProfit(std::vector<int> prices, int expected);
    bool testLengthOfLongestSubstring(std::string s, int expected);
    bool testLongestRepeatingCharacterReplacement(std::string s, int k, int expected);
    bool testPermutationInString(std::string s1, std::string s2, bool expected);
    bool testMinimumWindowSubstring(std::string s, std::string t, std::string expected);
    bool testSlidingWindowMaximum(std::vector<int> nums, int k, std::vector<int> expected);

    // Minimum Size Subarray Sum
    // Substring with Concatenation of All Words
    // Maximum Average Subarray
    // Max Consecutive Ones 3
    // Maximum Number of Vowels in a Substring of Given Length
    // Find all anagrams in String

    SlidingWindow sw;
};