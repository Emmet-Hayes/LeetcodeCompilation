#include "BinarySearchTester.h"

#include <cmath>


bool BinarySearchTester::testAllProblems()
{
    addTestCase(testBinarySearch({ -1, 0, 3, 5, 9, 12 }, 9, 4));
    addTestCase(testBinarySearch({ -1, 0, 3, 5, 9, 12 }, 2, -1));

    addTestCase(testSearchMatrix({ { 1,  3,  5,  7  },
                                   { 10, 11, 16, 20 },
                                   { 23, 30, 34, 60 } }, 3,  {  0,  1 }));
    addTestCase(testSearchMatrix({ { 1,  3,  5,  7  },
                                   { 10, 11, 16, 20 },
                                   { 23, 30, 34, 60 } }, 13, { -1, -1 }));
    
    addTestCase(testKokoEatingBananas({ 3, 6, 7, 11 }, 8, 4));
    addTestCase(testKokoEatingBananas({ 30, 11, 23, 4, 20 }, 5, 30));
    addTestCase(testKokoEatingBananas({ 30, 11, 23, 4, 20 }, 6, 23));

    addTestCase(testMinRotatedSortedArray({ 3, 4, 5, 1, 2 }, 1));
    addTestCase(testMinRotatedSortedArray({ 4, 5, 6, 7, 0, 1, 2 }, 0));
    addTestCase(testMinRotatedSortedArray({ 11, 13, 15, 17 }, 11));

    addTestCase(testSearchRotatedSortedArray({ 4, 5, 6, 7, 0, 1, 2 }, 0, 4));
    addTestCase(testSearchRotatedSortedArray({ 4, 5, 6, 7, 0, 1, 2 }, 3, -1));
    addTestCase(testSearchRotatedSortedArray({ 1 }, 0, -1));

    addTestCase(testTimeMap());

    addTestCase(testMedianTwoSortedArrays({ 1, 3 }, { 2 }, 2.0000));
    addTestCase(testMedianTwoSortedArrays({ 1, 2 }, { 3, 4 }, 2.5000));

    return runAllTests();
}

bool BinarySearchTester::testBinarySearch(std::vector<int> nums, int target, int expected)
{
    int actual = bs.binarySearch(nums, target);
    if (getVerbose())
    {
        ss << "\nBinary Search Test Run On Input Vector:\n[ ";
        for (int val : nums)
            ss << val << " ";
        ss << "]\nTarget: " << target << "\nResult: " << actual << " | Expected: " << expected << "\n";
    }
    return actual == expected;
}

bool BinarySearchTester::testSearchMatrix(std::vector<std::vector<int>> matrix, int target, std::pair<int, int> expected)
{
    std::pair<int, int> actual = bs.searchMatrix(matrix, target);
    if (getVerbose())
    {
        ss << "\nBinary Search Test Run On Input Matrix:\n[ ";
        for (int i = 0; i < matrix.size(); ++i)
        {
            ss << "[ ";
            for (int val : matrix[i])
                ss << val << " ";
            ss << "] ";
            if (i + 1 != matrix.size())
                ss << "\n";
        }
        ss << "]\nTarget: " << target << "\nResult: { " << actual.first << ", " << actual.second << " } | Expected: { " 
                  << expected.first << ", " << expected.second << " }\n";
    }
    return actual.first == expected.first && actual.second == expected.second;
}

bool BinarySearchTester::testKokoEatingBananas(std::vector<int> piles, int h, int expected)
{
    int actual = bs.kokoEatingBananas(piles, h);
    if (getVerbose())
    {
        ss << "\nKoko Eating Bananas Test Run On Input Pile of Bananas:\n[ ";
        for (int val : piles)
            ss << val << " ";
        ss << "]\nHours: " << h << "\nResult: " << actual << " | Expected: " << expected << "\n";
    }
    return actual == expected;
}

bool BinarySearchTester::testMinRotatedSortedArray(std::vector<int> nums, int expected)
{
    int actual = bs.minRotatedSortedArray(nums);
    if (getVerbose())
    {
        ss << "\nMinimum Rotated Sorted Array Test Run On Input Vector:\n[ ";
        for (int val : nums)
            ss << val << " ";
        ss << "]\nResult: " << actual << " | Expected: " << expected << "\n";
    }
    return actual == expected;
}

bool BinarySearchTester::testSearchRotatedSortedArray(std::vector<int> nums, int target, int expected)
{
    int actual = bs.searchRotatedSortedArray(nums, target);
    if (getVerbose())
    {
        ss << "\nSearch Rotated Sorted Array Test Run On Input Vector:\n[ ";
        for (int val : nums)
            ss << val << " ";
        ss << "]\nTarget: " << target << "\nResult: " << actual << " | Expected: " << expected << "\n";
    }
    return actual == expected;
}

bool BinarySearchTester::testTimeMap()
{
    BinarySearch::TimeMap tm;
    tm.set("foo", "bar", 1);
    if (tm.get("foo", 1).compare("bar") != 0) return false;
    if (tm.get("foo", 3).compare("bar") != 0) return false;
    tm.set("foo", "bar2", 4);
    if (tm.get("foo", 4).compare("bar2") != 0) return false;
    if (tm.get("foo", 5).compare("bar2") != 0) return false;

    return true;
}

bool BinarySearchTester::testMedianTwoSortedArrays(std::vector<int> nums1, std::vector<int> nums2, double expected)
{
    double epsilon = 1e-9; // helpful for floating-point comparisons
    double actual = bs.medianTwoSortedArrays(nums1, nums2);
    if (getVerbose())
    {
        ss << "\nContains Duplicate Test Run On Input Vectors:\n[ ";
        for (int val : nums1)
            ss << val << " ";
        ss << "]\n[ ";
        for (int val : nums2)
            ss << val << " ";
        ss << "]\nResult: " << actual << " | Expected: " << expected << "\n";
    }
    return std::fabs(actual - expected) < epsilon;
}
