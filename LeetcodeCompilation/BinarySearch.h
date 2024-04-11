#pragma once

#include "Solution.h"

#include <map>
#include <unordered_map>
#include <vector>


class BinarySearch : public Solution
{
public:
    BinarySearch() : Solution("BinarySearch", "Common challenge problems involving variants of the binary search algorithm.") {}
    std::unique_ptr<Solution> clone() const override { return std::make_unique<BinarySearch>(*this); }
    
    int binarySearch(const std::vector<int>& nums, int target);
    std::pair<int, int> searchMatrix(const std::vector<std::vector<int>>& matrix, int target);
    int kokoEatingBananas(const std::vector<int>& piles, int h);
    int minRotatedSortedArray(const std::vector<int>& nums);
    int searchRotatedSortedArray(const std::vector<int>& nums, int target);
    double medianTwoSortedArrays(const std::vector<int>& nums1, const std::vector<int>& nums2);

    // Search insert position
    // Find Peak Element
    // First and Last Position of Element in Sorted Array
    // Guess Number Higher or Lower
    // Successful Pairs of Spells and Potions

    class TimeMap
    {
    public:
        TimeMap() {}

        void set(const std::string& key, const std::string& value, int timestamp);
        std::string get(const std::string& key, int timestamp);

    private:
        std::unordered_map<std::string, std::map<int, std::string>> timeMap;
    };
};