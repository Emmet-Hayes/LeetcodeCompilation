#pragma once

#include "Backtracking.h"
#include "Tester.h"


class BacktrackingTester : public Tester
{
public:
    BacktrackingTester() : Tester { "Backtracking" } {}
    bool testAllProblems() override;
    std::unique_ptr<Tester> clone() const override { return std::make_unique<BacktrackingTester>(*this); }

private:
    bool testSubsets(std::vector<int> nums, std::vector<std::vector<int>> expected);
    bool testCombinationSum(std::vector<int> candidates, int target, std::vector<std::vector<int>> expected);
    bool testPermutations(std::vector<int> nums, std::vector<std::vector<int>> expected);
    bool testSubsetsWithDup(std::vector<int> nums, std::vector<std::vector<int>> expected);
    bool testCombinationSumNoDup(std::vector<int> candidates, int target, std::vector<std::vector<int>> expected);
    bool testWordSearch(std::vector<std::vector<char>> board, std::string word, bool expected);
    bool testPalindromePartition(std::string s, std::vector<std::vector<std::string>> expected);
    bool testLetterCombinations(std::string digits, std::vector<std::string> expected);
    bool testSolveNQueens(int n, std::vector<std::vector<std::string>> expected);

    // Generate Parentheses
    // N-Queens 2
    // Combination Sum 3

    Backtracking bt;
};