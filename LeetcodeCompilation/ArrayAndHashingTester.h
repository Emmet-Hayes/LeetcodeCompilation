#pragma once

#include "Tester.h"
#include "ArrayAndHashing.h"


class ArrayAndHashingTester : public Tester
{
public:
    ArrayAndHashingTester() : Tester { "Array and Hashing" } {}
    bool testAllProblems() override;
    std::unique_ptr<Tester> clone() const override { return std::make_unique<ArrayAndHashingTester>(*this); }

private:
    bool testContainsDuplicate(std::vector<int> nums, bool expected);
    bool testContainsDuplicateFast(std::vector<int> nums, bool expected);
    bool testIsAnagram(std::string s, std::string t, bool expected);
    bool testTwoSum(std::vector<int> nums, int target, std::pair<int, int> expected);
    bool testTwoSumFast(std::vector<int> nums, int target, std::pair<int, int> expected);
    bool testGroupAnagrams(std::vector<std::string> strs, std::vector<std::vector<std::string>> expected);
    bool testTopKFrequentElements(std::vector<int> nums, int k, std::vector<int> expected);
    bool testTopKFrequentElementsAlt(std::vector<int> nums, int k, std::vector<int> expected);
    bool testProductExceptSelf(std::vector<int> nums, std::vector<int> expected);
    bool testIsValidSudoku(std::vector<std::vector<char>> board, bool expected);
    bool testLongestConsecutiveSubsequence(std::vector<int> nums, int expected);
    
    // Merged Sorted Array
    // Remove Element
    // Remove Duplicates
    // Remove Duplicates 2
    // Majority Element
    // Rotate Array
    // Best Time To Buy And Sell Stock
    // Best Time To Buy And Sell Stock 2
    // H-Index
    // Insert-Delete-GetRandom
    // Candy
    // Roman to Integer
    // Integer to Roman
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

    ArrayAndHashing aah;
};