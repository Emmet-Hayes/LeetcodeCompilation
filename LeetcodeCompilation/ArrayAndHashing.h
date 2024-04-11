#pragma once

#include "Solution.h"

#include <unordered_map>
#include <vector>


class ArrayAndHashing : public Solution
{
public:
    ArrayAndHashing() : Solution("ArrayAndHashing", "Common challenge problems involving arrays and hashmaps.") {}
    std::unique_ptr<Solution> clone() const override { return std::make_unique<ArrayAndHashing>(*this); }

    bool containsDuplicate(std::vector<int>& nums);
    bool containsDuplicateFast(const std::vector<int>& nums);
    bool isAnagram(const std::string& s, const std::string& t);
    std::pair<int, int> twoSum(const std::vector<int>& nums, int target);
    std::pair<int, int> twoSumFast(const std::vector<int>& nums, int target);
    std::vector<std::vector<std::string>> groupAnagrams(const std::vector<std::string>& strs);
    std::vector<int> topKFrequent(const std::vector<int>& nums, int k);
    std::vector<int> topKFrequentAlt(const std::vector<int>& nums, int k);
    std::vector<int> productExceptSelf(const std::vector<int>& nums);
    bool isValidSudoku(const std::vector<std::vector<char>>& board);
    int longestConsecutiveSequence(const std::vector<int>& nums);

    void mergeSortedArray(std::vector<int>& nums1, int m, const std::vector<int>& nums2, int n);
    int removeElement(std::vector<int>& nums, int val);
    int removeDuplicatesSortedArray(std::vector<int>& nums);
    int removeDuplicatesSortedArrayMostTwice(std::vector<int>& nums);
    int majorityElement(const std::vector<int>& nums);
    void rotateArray(std::vector<int>& nums, int k);
    int hIndex(std::vector<int>& citations);
    int candy(std::vector<int>& ratings);
    int romanToInteger(std::string s);
    std::string integerToRoman(int num);

    // Length of Last Word
    // Longest Common Prefix
    // Reverse Words in String
    // Zigzag Conversion
    // Find the Index of the First Occurrence in a String
    // Text Justification
    // Ransom Note
    // Isomorphic Strings
    // Word Pattern
    // Contains Duplicate 2
    // Merge Strings Alternately
    // Greates Common Divisor of Strings
    // Can Place Flowers
    // Reverse Vowels of a String
    // Increasing Triplet Sequence
    // String Compression
    // Difference of Two Arrays
    // Unique Number of Occurrences
    // Determine if Two Strings are Close
    // Equal Row and Column Pairs
    // Next Permutation
    // Sort Colors

    class RandomizedSet
    {
    public:
        RandomizedSet() {}

        bool insert(int val);

        bool remove(int val);

        int getRandom();

    private:
        std::vector<int> nums;
        std::unordered_map<int, int> numMap;
    };

private:
    void reverseArray(std::vector<int>::iterator begin, std::vector<int>::iterator end);
};