#pragma once

#include "BinarySearch.h"
#include "Tester.h"


class BinarySearchTester : public Tester
{
public:
    BinarySearchTester() : Tester { "Binary Search" } {}
    bool testAllProblems() override;
    std::unique_ptr<Tester> clone() const override { return std::make_unique<BinarySearchTester>(*this); }

private:
    bool testBinarySearch(std::vector<int> nums, int target, int expected);
    bool testSearchMatrix(std::vector<std::vector<int>> matrix, int target, std::pair<int, int> expected);
    bool testKokoEatingBananas(std::vector<int> piles, int h, int expected);
    bool testMinRotatedSortedArray(std::vector<int> nums, int expected);
    bool testSearchRotatedSortedArray(std::vector<int> nums, int target, int expected);
    bool testTimeMap(); // test case baked in
    bool testMedianTwoSortedArrays(std::vector<int> nums1, std::vector<int> nums2, double expected);

    // Search insert position
    // Find Peak Element
    // First and Last Position of Element in Sorted Array
    // Guess Number Higher or Lower
    // Successful Pairs of Spells and Potions

    BinarySearch bs;
};