#include "ArrayAndHashingTester.h"


bool ArrayAndHashingTester::testAllProblems() 
{
    addTestCase(testContainsDuplicate({ 1, 2, 3, 1 }, true));
    addTestCase(testContainsDuplicate({ 1, 2, 3, 4 }, false));
    addTestCase(testContainsDuplicate({ 1, 1, 1, 3, 3, 4, 3, 2, 4, 2 }, true));

    addTestCase(testContainsDuplicateFast({ 1, 2, 3, 1 }, true));
    addTestCase(testContainsDuplicateFast({ 1, 2, 3, 4 }, false));
    addTestCase(testContainsDuplicateFast({ 1, 1, 1, 3, 3, 4, 3, 2, 4, 2 }, true));
    
    addTestCase(testIsAnagram("anagram", "nagaram", true));
    addTestCase(testIsAnagram("rat", "car", false));

    addTestCase(testTwoSum({ 2, 7, 11, 15}, 9, { 0, 1 }));
    addTestCase(testTwoSum({ 3, 2, 4 }, 6, { 1, 2 }));
    addTestCase(testTwoSum({ 3, 3 }, 6, { 0, 1 }));

    addTestCase(testTwoSumFast({ 2, 7, 11, 15 }, 9, { 0, 1 }));
    addTestCase(testTwoSumFast({ 3, 2, 4 }, 6, { 1, 2 }));
    addTestCase(testTwoSumFast({ 3, 3 }, 6, { 0, 1 }));

    addTestCase(testGroupAnagrams({ "eat", "tea", "tan", "ate", "nat", "bat" }, 
                                          { { "eat", "tea", "ate" }, { "tan", "nat" }, { "bat" } }));
    addTestCase(testGroupAnagrams({ "" }, { { "" } }));
    addTestCase(testGroupAnagrams({ "a" }, { { "a" } }));

    addTestCase(testTopKFrequentElements({ 1, 1, 1, 2, 2, 3 }, 2, { 1, 2 }));
    addTestCase(testTopKFrequentElements({ 1 }, 1, { 1 }));

    addTestCase(testTopKFrequentElementsAlt({ 1, 1, 1, 2, 2, 3 }, 2, { 1, 2 }));
    addTestCase(testTopKFrequentElementsAlt({ 1 }, 1, { 1 }));

    addTestCase(testProductExceptSelf({ 1, 2, 3, 4 }, { 24, 12, 8, 6 }));
    addTestCase(testProductExceptSelf({ -1, 1, 0, -3, 3 }, { 0, 0, 9, 0, 0 }));

    addTestCase(testIsValidSudoku({ { '5', '3', '.', '.', '7', '.', '.', '.', '.' },
                                    { '6', '.', '.', '1', '9', '5', '.', '.', '.' },
                                    { '.', '9', '8', '.', '.', '.', '.', '6', '.' },
                                    { '8', '.', '.', '.', '6', '.', '.', '.', '3' },
                                    { '4', '.', '.', '8', '.', '3', '.', '.', '1' },
                                    { '7', '.', '.', '.', '2', '.', '.', '.', '6' },
                                    { '.', '6', '.', '.', '.', '.', '2', '8', '.' },
                                    { '.', '.', '.', '4', '1', '9', '.', '.', '5' },
                                    { '.', '.', '.', '.', '8', '.', '.', '7', '9' } }, true));

    addTestCase(testIsValidSudoku({ { '8', '3', '.', '.', '7', '.', '.', '.', '.' },
                                    { '6', '.', '.', '1', '9', '5', '.', '.', '.' },
                                    { '.', '9', '8', '.', '.', '.', '.', '6', '.' },
                                    { '8', '.', '.', '.', '6', '.', '.', '.', '3' },
                                    { '4', '.', '.', '8', '.', '3', '.', '.', '1' },
                                    { '7', '.', '.', '.', '2', '.', '.', '.', '6' },
                                    { '.', '6', '.', '.', '.', '.', '2', '8', '.' },
                                    { '.', '.', '.', '4', '1', '9', '.', '.', '5' },
                                    { '.', '.', '.', '.', '8', '.', '.', '7', '9' } }, false));

    addTestCase(testLongestConsecutiveSubsequence({ 100, 4, 200, 1, 3, 2 }, 4));
    addTestCase(testLongestConsecutiveSubsequence({ 0, 3, 7, 2, 5, 8, 4, 6, 0, 1 }, 9));

    return runAllTests();
}

bool ArrayAndHashingTester::testContainsDuplicate(std::vector<int> nums, bool expected)
{
    bool actual = aah.containsDuplicate(nums);
    if (getVerbose())
    {
        ss << "\nContains Duplicate Test Run On Input Vector:\n[ ";
        for (int val : nums)
            ss << val << " ";
        ss << "]\nResult: " << actual << " | Expected: " << expected << "\n";
    }
    return actual == expected;
}

bool ArrayAndHashingTester::testContainsDuplicateFast(std::vector<int> nums, bool expected)
{
    bool actual = aah.containsDuplicateFast(nums);
    if (getVerbose())
    {
        ss << "\nContains Duplicate (Fast) Test Run On Input Vector:\n[ ";
        for (int val : nums)
            ss << val << " ";
        ss << "]\nResult: " << actual << " | Expected: " << expected << "\n";
    }
    return actual == expected;
}

bool ArrayAndHashingTester::testIsAnagram(std::string s, std::string t, bool expected)
{
    bool actual = aah.isAnagram(s, t);
    if (getVerbose())
    {
        ss << "\nIs Anagram Test Run On Input Strings:\ns: "
                  << s << "\nt: " << t
                  << "\nResult: " << actual << " | Expected: " << expected << "\n";
    }
    return actual == expected;
}

bool ArrayAndHashingTester::testTwoSum(std::vector<int> nums, int target, std::pair<int, int> expected)
{
    std::pair<int, int> actual = aah.twoSum(nums, target);
    if (getVerbose())
    {
        ss << "\nTwo Sum Test Run On Input Vector:\n[ ";
        for (int val : nums)
            ss << val << " ";
        ss << "]\nTarget: " << target << "\nResult: [ " << actual.first << ", " << actual.second 
                  << " ] | Expected: [ " << expected.first << ", " << expected.second << " ]\n";
    }
    return actual.first == expected.first && actual.second == expected.second;
}

bool ArrayAndHashingTester::testTwoSumFast(std::vector<int> nums, int target, std::pair<int, int> expected)
{
    std::pair<int, int> actual = aah.twoSumFast(nums, target);
    if (getVerbose())
    {
        ss << "\nTwo Sum (Fast) Test Run On Input Vector:\n[ ";
        for (int val : nums)
            ss << val << " ";
        ss << "]\nTarget: " << target << "\nResult: [ " << actual.first << ", " << actual.second
            << " ] | Expected: [ " << expected.first << ", " << expected.second << " ]\n";
    }
    return actual.first == expected.first && actual.second == expected.second;
}

bool ArrayAndHashingTester::testGroupAnagrams(std::vector<std::string> strs, std::vector<std::vector<std::string>> expected)
{
    std::vector<std::vector<std::string>> actual = aah.groupAnagrams(strs);
    if (getVerbose())
    {
        ss << "\nGroup Anagrams Test Run On Input String Vector:\n[ ";
        for (std::string str : strs)
            ss << str << " ";
        ss << "]\nResult:   [ [ ";
        for (int i = 0; i < actual.size(); ++i)
        {
            for (std::string str : actual[i])
                ss << str << " ";
            if (i + 1 < actual.size())
                ss << "], [ ";
            else
                ss << "] ";
        }
        ss << "]\nExpected: [ [ ";
        for (int i = 0; i < expected.size(); ++i)
        {
            for (std::string str : expected[i])
                ss << str << " ";
            if (i + 1 < expected.size())
                ss << "], [ ";
            else
                ss << "] ";
        }
        ss << "]\n";
    }
    if (expected.size() != actual.size()) return false;
    for (int i = 0; i < expected.size(); ++i)
    {
        if (expected[i].size() != actual[i].size()) return false;
        for (int j = 0; j < expected[i].size(); ++j)
            if (expected[i][j].compare(actual[i][j]) != 0)
                return false;
    }
    return true;
}

bool ArrayAndHashingTester::testTopKFrequentElements(std::vector<int> nums, int k, std::vector<int> expected)
{
    std::vector<int> actual = aah.topKFrequent(nums, k);
    if (getVerbose())
    {
        ss << "\nTop K Frequent Elements Test Run On Input Vector:\n[ ";
        for (int val : nums)
            ss << val << " ";
        ss << "]\n Result: [ ";
        for (int val : actual)
            ss << val << " ";
        ss << "] | Expected: [ ";
        for (int val : expected)
            ss << val << " ";
        ss << "]\n";
    }
    for (int i = 0; i < expected.size(); ++i)
        if (actual[i] != expected[i])
            return false;
    return true;
}

bool ArrayAndHashingTester::testTopKFrequentElementsAlt(std::vector<int> nums, int k, std::vector<int> expected)
{
    std::vector<int> actual = aah.topKFrequentAlt(nums, k);
    if (getVerbose())
    {
        ss << "\nTop K Frequent Elements (Alternative) Test Run On Input Vector:\n[ ";
        for (int val : nums)
            ss << val << " ";
        ss << "]\nResult: [ ";
        for (int val : actual)
            ss << val << " ";
        ss << "] | Expected: [ ";
        for (int val : expected)
            ss << val << " ";
        ss << "]\n";
    }
    for (int i = 0; i < expected.size(); ++i)
        if (actual[i] != expected[i])
            return false;
    return true;
}

bool ArrayAndHashingTester::testProductExceptSelf(std::vector<int> nums, std::vector<int> expected)
{
    std::vector<int> actual = aah.productExceptSelf(nums);
    if (getVerbose())
    {
        ss << "\nProduct Except Self Test Run On Input Vector:\n[ ";
        for (int val : nums)
            ss << val << " ";
        ss << "]\nResult: [ ";
        for (int val : actual)
            ss << val << " ";
        ss << "] | Expected: [ ";
        for (int val : expected)
            ss << val << " ";
        ss << "]\n";
    }
    for (int i = 0; i < expected.size(); ++i)
        if (actual[i] != expected[i])
            return false;
    return true;
}

bool ArrayAndHashingTester::testIsValidSudoku(std::vector<std::vector<char>> board, bool expected)
{
    bool actual = aah.isValidSudoku(board);
    if (getVerbose())
    {
        ss << "\nIs Valid Sudoku Test Run On Input Board:\n ";
        int i = 0;
        for (std::vector<char> row : board)
        {
            int j = 0;
            for (char val : row)
            {
                ss << val << " ";
                j++;
                if (j % 3 == 0 && j + 1 < board[0].size())
                    ss << "| ";
            }
            ss << "\n ";
            i++;
            if (i % 3 == 0 && i + 1 < board.size())
                ss << "---------------------\n ";
        }
        ss << "\nResult: " << actual << " | Expected: " << expected << "\n";
    }
    return actual == expected;
}

bool ArrayAndHashingTester::testLongestConsecutiveSubsequence(std::vector<int> nums, int expected)
{
    int actual = aah.longestConsecutiveSequence(nums);
    if (getVerbose())
    {
        ss << "\nLongest Consecutive Sequence Test Run On Input Vector:\n[ ";
        for (int val : nums)
            ss << val << " ";
        ss << "]\nResult: " << actual << " | Expected: " << expected << "\n";
    }
    return actual == expected;
}

