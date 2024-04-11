#include "TwoPointersTester.h"


bool TwoPointersTester::testAllProblems()
{
    addTestCase(testIsPalindrome("A man, a plan, a canal: Panama", true));
    addTestCase(testIsPalindrome("race a car", false));
    addTestCase(testIsPalindrome(" ", true));

    addTestCase(testTwoSumSorted({ 2, 7, 11, 15 }, 9, { 0, 1 }));
    addTestCase(testTwoSumSorted({ 2, 3, 4 }, 6, { 0, 2 }));
    addTestCase(testTwoSumSorted({ -1, 0 }, -1, { 0, 1 }));

    addTestCase(testThreeSum({ -1, 0, 1, 2, -1, -4 }, 0, { { -1, -1, 2 }, { -1, 0, 1 } }));
    addTestCase(testThreeSum({ 0, 1, 1 }, 0, {}));
    addTestCase(testThreeSum({ 0, 0, 0 }, 0, { { 0, 0, 0 } }));

    addTestCase(testContainerWithMostWater({ 1, 8, 6, 2, 5, 4, 8, 3, 7 }, 49));
    addTestCase(testContainerWithMostWater({ 1, 1 }, 1));

    addTestCase(testTrappingRainWater({ 0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1 }, 6));
    addTestCase(testTrappingRainWater({ 4, 2, 0, 3, 2, 5 }, 9));

    return runAllTests();
}

bool TwoPointersTester::testIsPalindrome(std::string s, bool expected)
{
    bool actual = tp.isPalindrome(s);
    if (getVerbose())
        ss << "\nIs Palindrome Test Run on Given String: " << s << "\nResult: " << actual << " | Expected: " << expected << "\n";
    return actual == expected;
}

bool TwoPointersTester::testTwoSumSorted(std::vector<int> nums, int target, std::pair<int, int> expected)
{
    std::pair<int, int> actual = tp.twoSumSorted(nums, target);
    if (getVerbose())
    {
        ss << "\nTwo Sum Sorted Test Run on Given Vector: [ ";
        for (int val : nums)
            ss << val << " ";
        ss << "]\nTarget: " << target << "\nResult:   { " << actual.first << ", " << actual.second 
           << " }\nExpected: { " << expected.first << ", " << expected.second << " }\n";
    }
    return actual.first == expected.first && actual.second == expected.second;
}

bool TwoPointersTester::testThreeSum(std::vector<int> nums, int target, std::vector<std::tuple<int, int, int>> expected)
{
    std::vector<std::tuple<int, int, int>> actual = tp.threeSum(nums, target);
    if (getVerbose())
    {
        ss << "\nThree Sum Test Run on Given Vector: [ ";
        for (int val : nums)
            ss << val << " ";
        ss << "]\nTarget: " << target << "\nResult:   [ ";
        for (std::tuple<int, int, int> tup : actual)
            ss << "{ " << std::get<0>(tup) << ", " << std::get<1>(tup) << ", " << std::get<2>(tup) << " } ";
        ss << "]\nExpected: [ "; 
        
        for (std::tuple<int, int, int> tup : expected)
            ss << "{ " << std::get<0>(tup) << ", " << std::get<1>(tup) << ", " << std::get<2>(tup) << " } ";
        ss << "]\n";
    }
    if (actual.size() != expected.size()) return false;
    for (int i = 0; i < expected.size(); ++i)
        if (std::get<0>(actual[i]) != std::get<0>(expected[i]) ||
            std::get<1>(actual[i]) != std::get<1>(expected[i]) ||
            std::get<2>(actual[i]) != std::get<2>(expected[i]))
            return false;
    return true;
}

bool TwoPointersTester::testContainerWithMostWater(std::vector<int> height, int expected)
{
    int actual = tp.containerWithMostWater(height);
    if (getVerbose())
    {
        ss << "\nContainer With Most Water Test Run On Input Vector:\n[ ";
        for (int val : height)
            ss << val << " ";
        ss << "]\nResult: " << actual << " | Expected: " << expected << "\n";
    }
    return actual == expected;
}

bool TwoPointersTester::testTrappingRainWater(std::vector<int> height, int expected)
{
    int actual = tp.trappingRainWater(height);
    if (getVerbose())
    {
        ss << "\nTrapping Rain Water Test Run On Input Vector:\n[ ";
        for (int val : height)
            ss << val << " ";
        ss << "]\nResult: " << actual << " | Expected: " << expected << "\n";
    }
    return actual == expected;
}
