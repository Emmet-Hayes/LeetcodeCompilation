#include "BacktrackingTester.h"


bool BacktrackingTester::testAllProblems()
{
    addTestCase(testSubsets({ 1, 2, 3 }, { { 1, 2, 3 }, { 1, 2 }, { 1, 3 }, { 1 },
                                           { 2, 3 }, { 2 }, { 3 }, { } }));
    addTestCase(testSubsets({ 0 }, { { 0 }, { } }));

    addTestCase(testCombinationSum({ 2, 3, 6, 7 }, 7, { { 2, 2, 3 }, { 7 } }));
    addTestCase(testCombinationSum({ 2, 3, 5 }, 8, { { 2, 2, 2, 2 }, { 2, 3, 3 }, { 3, 5 } }));
    addTestCase(testCombinationSum({ 2 }, 1, { }));

    addTestCase(testPermutations({ 1, 2, 3 }, { { 1, 2, 3 }, { 1, 3, 2 }, { 2, 1, 3 }, 
                                 { 2, 3, 1 }, { 3, 2, 1 }, { 3, 1, 2 } }));
    addTestCase(testPermutations({ 0, 1 }, { { 0, 1 }, { 1, 0 } }));
    addTestCase(testPermutations({ 1 }, { { 1 } }));

    addTestCase(testSubsetsWithDup({ 1, 2, 2 }, { { }, { 1 }, { 1, 2 }, { 1, 2, 2}, { 2 }, { 2, 2 } }));
    addTestCase(testSubsetsWithDup({ 0 }, { {}, { 0 } }));

    addTestCase(testCombinationSumNoDup({ 10, 1, 2, 7, 6, 1, 5 }, 8, { { 1, 1, 6 }, { 1, 2, 5 }, { 1, 7 }, { 2, 6 } }));
    addTestCase(testCombinationSumNoDup({ 2, 5, 2, 1, 2 }, 5, { { 1, 2, 2 }, { 5 } }));

    addTestCase(testWordSearch({ { 'A', 'B', 'C', 'E' },
                                 { 'S', 'F', 'C', 'S' },
                                 { 'A', 'D', 'E', 'E' }}, "ABCCED", true));
    addTestCase(testWordSearch({ { 'A', 'B', 'C', 'E' },
                                 { 'S', 'F', 'C', 'S' },
                                 { 'A', 'D', 'E', 'E' } }, "SEE", true));
    addTestCase(testWordSearch({ { 'A', 'B', 'C', 'E' },
                                 { 'S', 'F', 'C', 'S' },
                                 { 'A', 'D', 'E', 'E' } }, "ABCB", false));
    
    addTestCase(testPalindromePartition("aab", { { "a", "a", "b" }, { "aa", "b" } }));
    addTestCase(testPalindromePartition("a", { { "a" } }));
    
    addTestCase(testLetterCombinations("23", { "ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf" }));
    addTestCase(testLetterCombinations("", {}));
    addTestCase(testLetterCombinations("2", {"a", "b", "c"}));

    addTestCase(testSolveNQueens(4, { { ".Q..", "...Q", "Q...", "..Q." },
                                      { "..Q.", "Q...", "...Q", ".Q.."} }));
    addTestCase(testSolveNQueens(1, { { "Q" } }));

    return runAllTests();
}

bool BacktrackingTester::testSubsets(std::vector<int> nums, std::vector<std::vector<int>> expected)
{
    std::vector<std::vector<int>> actual = bt.subsets(nums);
    if (getVerbose())
    {
        ss << "\nSubsets Test Run On Input String Vector:\n[ ";
        for (int val : nums)
            ss << val << " ";
        ss << "]\nResult:   [ [ ";
        for (int i = 0; i < actual.size(); ++i)
        {
            for (int val : actual[i])
                ss << val << " ";
            if (i + 1 < actual.size())
                ss << "], [ ";
            else
                ss << "] ";
        }
        ss << "]\nExpected: [ [ ";
        for (int i = 0; i < expected.size(); ++i)
        {
            for (int val : expected[i])
                ss << val << " ";
            if (i + 1 < expected.size())
                ss << "], [ ";
            else
                ss << "] ";
        }
        ss << "]\n";
    }
    if (actual.size() != expected.size()) return false;
    for (int i = 0; i < expected.size(); ++i)
    {
        if (actual[i].size() != expected[i].size()) return false;
        for (int j = 0; j < expected[i].size(); ++j)
            if (actual[i][j] != expected[i][j])
                return false;
    }
    return true;
}

bool BacktrackingTester::testCombinationSum(std::vector<int> candidates, int target, std::vector<std::vector<int>> expected)
{
    std::vector<std::vector<int>> actual = bt.combinationSum(candidates, target);
    if (getVerbose())
    {
        ss << "\nCombination Sum Test Run On Input String Vector:\n[ ";
        for (int val : candidates)
            ss << val << " ";
        ss << "]\nTarget: " << target << "\nResult:   [ [ ";
        for (int i = 0; i < actual.size(); ++i)
        {
            for (int val : actual[i])
                ss << val << " ";
            if (i + 1 < actual.size())
                ss << "], [ ";
            else
                ss << "] ";
        }
        ss << "]\nExpected: [ [ ";
        for (int i = 0; i < expected.size(); ++i)
        {
            for (int val : expected[i])
                ss << val << " ";
            if (i + 1 < expected.size())
                ss << "], [ ";
            else
                ss << "] ";
        }
        ss << "]\n";
    }
    if (actual.size() != expected.size()) return false;
    for (int i = 0; i < expected.size(); ++i)
    {
        if (actual[i].size() != expected[i].size()) return false;
        for (int j = 0; j < expected[i].size(); ++j)
            if (actual[i][j] != expected[i][j])
                return false;
    }
    return true;
}

bool BacktrackingTester::testPermutations(std::vector<int> nums, std::vector<std::vector<int>> expected)
{
    std::vector<std::vector<int>> actual = bt.permutations(nums);
    if (getVerbose())
    {
        ss << "\nPermutations Test Run On Input String Vector:\n[ ";
        for (int val : nums)
            ss << val << " ";
        ss << "]\nResult:   [ [ ";
        for (int i = 0; i < actual.size(); ++i)
        {
            for (int val : actual[i])
                ss << val << " ";
            if (i + 1 < actual.size())
                ss << "], [ ";
            else
                ss << "] ";
        }
        ss << "]\nExpected: [ [ ";
        for (int i = 0; i < expected.size(); ++i)
        {
            for (int val : expected[i])
                ss << val << " ";
            if (i + 1 < expected.size())
                ss << "], [ ";
            else
                ss << "] ";
        }
        ss << "]\n";
    }
    if (actual.size() != expected.size()) return false;
    for (int i = 0; i < expected.size(); ++i)
    {
        if (actual[i].size() != expected[i].size()) return false;
        for (int j = 0; j < expected[i].size(); ++j)
            if (actual[i][j] != expected[i][j])
                return false;
    }
    return true;
}

bool BacktrackingTester::testSubsetsWithDup(std::vector<int> nums, std::vector<std::vector<int>> expected)
{
    std::vector<std::vector<int>> actual = bt.subsetsWithDup(nums);
    if (getVerbose())
    {
        ss << "\nSubsets With Duplicates Test Run On Input String Vector:\n[ ";
        for (int val : nums)
            ss << val << " ";
        ss << "]\nResult:   [ [ ";
        for (int i = 0; i < actual.size(); ++i)
        {
            for (int val : actual[i])
                ss << val << " ";
            if (i + 1 < actual.size())
                ss << "], [ ";
            else
                ss << "] ";
        }
        ss << "]\nExpected: [ [ ";
        for (int i = 0; i < expected.size(); ++i)
        {
            for (int val : expected[i])
                ss << val << " ";
            if (i + 1 < expected.size())
                ss << "], [ ";
            else
                ss << "] ";
        }
        ss << "]\n";
    }
    if (actual.size() != expected.size()) return false;
    for (int i = 0; i < expected.size(); ++i)
    {
        if (actual[i].size() != expected[i].size()) return false;
        for (int j = 0; j < expected[i].size(); ++j)
            if (actual[i][j] != expected[i][j])
                return false;
    }
    return true;
}

bool BacktrackingTester::testCombinationSumNoDup(std::vector<int> candidates, int target, std::vector<std::vector<int>> expected)
{
    std::vector<std::vector<int>> actual = bt.combinationSumNoDup(candidates, target);
    if (getVerbose())
    {
        ss << "\nCombination Sum No Duplicates Test Run On Input String Vector:\n[ ";
        for (int val : candidates)
            ss << val << " ";
        ss << "]\n" << target << "\nResult:   [ [ ";
        for (int i = 0; i < actual.size(); ++i)
        {
            for (int val : actual[i])
                ss << val << " ";
            if (i + 1 < actual.size())
                ss << "], [ ";
            else
                ss << "] ";
        }
        ss << "]\nExpected: [ [ ";
        for (int i = 0; i < expected.size(); ++i)
        {
            for (int val : expected[i])
                ss << val << " ";
            if (i + 1 < expected.size())
                ss << "], [ ";
            else
                ss << "] ";
        }
        ss << "]\n";
    }
    if (actual.size() != expected.size()) return false;
    for (int i = 0; i < expected.size(); ++i)
    {
        if (actual[i].size() != expected[i].size()) return false;
        for (int j = 0; j < expected[i].size(); ++j)
            if (actual[i][j] != expected[i][j])
                return false;
    }
    return true;
}

bool BacktrackingTester::testWordSearch(std::vector<std::vector<char>> board, std::string word, bool expected)
{
    bool actual = bt.wordSearch(board, word);
    if (getVerbose())
    {
        ss << "\nWord Search Test Run On Input Board:\n";
        for (std::vector<char> row : board)
        {
            for (char square : row)
                ss << square << " ";
            ss << "\n";
        }
        ss << "Actual: " << actual << " | Expected: " << expected << "\n";
    }

    return actual == expected;
}

bool BacktrackingTester::testPalindromePartition(std::string s, std::vector<std::vector<std::string>> expected)
{
    std::vector<std::vector<std::string>> actual = bt.palindromePartition(s);
    if (getVerbose())
    {
        ss << "\nPalindrome Partition Test Run On Input String: " << s;
        ss << "\nResult:   [ [ ";
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
    if (actual.size() != expected.size()) return false;
    for (int i = 0; i < expected.size(); ++i)
    {
        if (actual[i].size() != expected[i].size()) return false;
        for (int j = 0; j < expected[i].size(); ++j)
            if (actual[i][j].compare(expected[i][j]) != 0)
                return false;
    }
    return true;
}

bool BacktrackingTester::testLetterCombinations(std::string digits, std::vector<std::string> expected)
{
    std::vector<std::string> actual = bt.letterCombinations(digits);
    if (getVerbose())
    {
        ss << "\nLetter Combinations Test Run On Input String: " << digits << "\nResult:   [ ";
        for (std::string combo : actual)
            ss << combo << " ";
        ss << "]\nExpected: [ ";
        for (std::string combo : expected)
            ss << combo << " ";
        ss << "]\n";
    }
    if (actual.size() != expected.size()) return false;
    for (int i = 0; i < expected.size(); ++i)
        if (actual[i].compare(expected[i]))
            return false;
    return true;
}

bool BacktrackingTester::testSolveNQueens(int n, std::vector<std::vector<std::string>> expected)
{
    std::vector<std::vector<std::string>> actual = bt.solveNQueens(n);
    if (getVerbose())
    {
        ss << "\nSolve N Queens Test Run On Input Value: " << n;
        ss << "\nResult:\n\n";
        for (int i = 0; i < actual.size(); ++i)
        {
            for (std::string str : actual[i])
                ss << str << "\n";
            ss << "\n";
        }
        ss << "\nExpected:\n\n";
        for (int i = 0; i < expected.size(); ++i)
        {
            for (std::string str : expected[i])
                ss << str << "\n";
            ss << "\n";
        }
    }
    if (actual.size() != expected.size()) return false;
    for (int i = 0; i < expected.size(); ++i)
    {
        if (actual[i].size() != expected[i].size()) return false;
        for (int j = 0; j < expected[i].size(); ++j)
            if (actual[i][j].compare(expected[i][j]) != 0)
                return false;
    }
    return true;
}
