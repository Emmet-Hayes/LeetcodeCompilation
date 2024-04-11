#pragma once

#include "Solution.h"

#include <set>
#include <unordered_map>
#include <vector>


class Backtracking : public Solution
{
public:
    Backtracking() : Solution("Backtracking", "Common challenge problems involving variants of backtracking algorithms.") {}
    std::unique_ptr<Solution> clone() const override { return std::make_unique<Backtracking>(*this); }
    
    std::vector<std::vector<int>> subsets(const std::vector<int>& nums);
    std::vector<std::vector<int>> combinationSum(const std::vector<int>& candidates, int target);
    std::vector<std::vector<int>> permutations(std::vector<int>& nums);
    std::vector<std::vector<int>> subsetsWithDup(std::vector<int>& nums);
    std::vector<std::vector<int>> combinationSumNoDup(std::vector<int>& candidates, int target);
    bool wordSearch(std::vector<std::vector<char>>& board, std::string word);
    std::vector<std::vector<std::string>> palindromePartition(const std::string& s);
    std::vector<std::string> letterCombinations(const std::string& digits);
    std::vector<std::vector<std::string>> solveNQueens(int n);

    // Generate Parentheses
    // N-Queens 2
    // Combination Sum 3

private:
    void dfsSubsets(std::vector<std::vector<int>>& subsets, std::vector<int>& subset, 
                    int i, const std::vector<int>& nums);
    void dfsCombinationSum(std::vector<std::vector<int>>& combinations,
                           const std::vector<int>& candidates, int n,
                           std::vector<int>& combo, int i, int sum, int target);
    void dfsPermutations(std::vector<std::vector<int>>& answer, std::vector<int>& nums, int start);
    void dfsSubsetsWithDup(std::vector<std::vector<int>>& subsets, const std::vector<int>& nums,
                           std::vector<int>& subset, int start);
    void dfsCombinationSumNoDup(std::vector<std::vector<int>>& answer, const std::vector<int>& candidates,
                            std::vector<int>& combo, int target, int i, int sum);
    void dfsWordSearch(std::vector<std::vector<char>>& board, const std::string& word,
                       int i, int j, std::string& curr, bool& isFound);
    void dfsPalindrome(std::vector<std::vector<std::string>>& answer, 
                       std::vector<std::string>& partition, const std::string& s, int i);
    bool isPalindrome(const std::string& s);
    void dfsPhoneNumber(std::vector<std::string>& combinations, std::string& combo, 
                        const std::string& digits, std::unordered_map<char, std::string>& digitmap, 
                        int i, int k);
    void dfsNQueens(std::vector <std::vector<std::string>>& boards, std::vector<std::string>& board,
                    int r, int n, std::set<int>& cols, std::set<int>& posDiag, std::set<int>& negDiag);
};