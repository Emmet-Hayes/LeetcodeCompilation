#pragma once

#include "Solution.h"

#include <vector>


class SlidingWindow : public Solution
{
public:
    SlidingWindow() : Solution("SlidingWindow", "Common challenge problems involving variants of the sliding window algorithm.") {}
    std::unique_ptr<Solution> clone() const override { return std::make_unique<SlidingWindow>(*this); }
    
    int bestTimeToBuyAndSellStock(const std::vector<int>& prices);
    int lengthOfLongestSubstring(const std::string& s);
    int longestRepeatingCharacterReplacement(const std::string& s, int k);
    bool permutationInString(const std::string& s1, const std::string& s2);
    std::string minimumWindowSubstring(const std::string& s, const std::string& t);
    std::vector<int> maxSlidingWindow(const std::vector<int>& nums, int k);

    // Minimum Size Subarray Sum
    // Substring with Concatenation of All Words
    // Maximum Average Subarray
    // Max Consecutive Ones 3
    // Maximum Number of Vowels in a Substring of Given Length
    // Find all anagrams in String
};