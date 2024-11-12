#include "Backtracking.h"

#include <algorithm>


/** Subsets (Meta - Medium)
* Given an integer array nums of unique elements, return all possible 
* subsets (the power set).
*
* The solution set must not contain duplicate subsets. 
* Return the solution in any order.
* 
* Complexity:
* Time: O(2^n)
* Space: O(n^2)
*/
std::vector<std::vector<int>> Backtracking::subsets(const std::vector<int>& nums)
{
    std::vector<std::vector<int>> subsets;
    std::vector<int> subset;
    dfsSubsets(subsets, subset, 0, nums);
    return subsets;
}

void Backtracking::dfsSubsets(std::vector<std::vector<int>>& subsets, std::vector<int>& subset, unsigned i, const std::vector<int>& nums)
{
    // the decision tree is 2^n, either we add a value to the subset or we dont
    if (i >= nums.size())
    {
        subsets.push_back(subset);
        return;
    }

    // decision to include nums[i]
    subset.push_back(nums[i]);
    dfsSubsets(subsets, subset, i + 1, nums);

    // decision to NOT include nums[i]
    subset.pop_back(); // remove the number we just added (backtrack)
    dfsSubsets(subsets, subset, i + 1, nums);
}

std::vector<std::vector<int>> Backtracking::combinationSum(const std::vector<int>& candidates, int target)
{
    std::vector<std::vector<int>> combinations;
    std::vector<int> combo;
    dfsCombinationSum(combinations, candidates, combo, 0, 0, target);
    return combinations;
}

void Backtracking::dfsCombinationSum(std::vector<std::vector<int>>& combinations, const std::vector<int>& candidates, std::vector<int>& combo, unsigned i, int sum, int target)
{
    if (i >= candidates.size() || sum > target)
        return;
    if (sum == target)
    {
        combinations.push_back(combo);
        return;
    }

    // decision to add another candidate[i] to sum
    combo.push_back(candidates[i]);
    dfsCombinationSum(combinations, candidates, combo, i, sum + candidates[i], target);

    // decision to try adding the next candidate to sum
    combo.pop_back();
    dfsCombinationSum(combinations, candidates, combo, i + 1, sum, target);
}

std::vector<std::vector<int>> Backtracking::permutations(std::vector<int>& nums)
{
    std::vector<std::vector<int>> answer;
    dfsPermutations(answer, nums, 0);
    return answer;
}

void Backtracking::dfsPermutations(std::vector<std::vector<int>>& answer, std::vector<int>& nums, unsigned start)
{
    if (start >= nums.size() - 1)
    {
        answer.push_back(nums);
        return;
    }

    for (unsigned i = start; i < nums.size(); ++i)
    {
        // try swapping to make a new permutation
        std::swap(nums[start], nums[i]);
        dfsPermutations(answer, nums, start + 1);
        std::swap(nums[start], nums[i]); // backtrack
    }
}

std::vector<std::vector<int>> Backtracking::subsetsWithDup(std::vector<int>& nums)
{
    std::sort(nums.begin(), nums.end());
    std::vector<std::vector<int>> subsets;
    std::vector<int> subset;
    dfsSubsetsWithDup(subsets, nums, subset, 0);
    return subsets;
}

void Backtracking::dfsSubsetsWithDup(std::vector<std::vector<int>>& subsets, const std::vector<int>& nums, std::vector<int>& subset, unsigned start)
{
    subsets.push_back(subset);

    for (unsigned j = start; j < nums.size(); ++j)
    {
        if (j > start && nums[j] == nums[j - 1])
            continue; // skip values we already put in the subset

        // decision include the value in the subset
        subset.push_back(nums[j]);
        dfsSubsetsWithDup(subsets, nums, subset, j + 1);

        // decision to not include the value in the subset
        subset.pop_back();
    }
}

std::vector<std::vector<int>> Backtracking::combinationSumNoDup(std::vector<int>& candidates, int target)
{
    std::sort(candidates.begin(), candidates.end());
    std::vector<std::vector<int>> answer;
    std::vector<int> combo;
    dfsCombinationSumNoDup(answer, candidates, combo, 0, 0, target);
    return answer;
}

void Backtracking::dfsCombinationSumNoDup(std::vector<std::vector<int>>& answer, const std::vector<int>& candidates, std::vector<int>& combo, unsigned i, int sum, int target)
{
    if (sum == target)
    {
        answer.push_back(combo);
        return;
    }
    if (i >= candidates.size() || sum > target)
        return;

    for (unsigned j = i; j < candidates.size(); ++j)
    {
        if (j != i && candidates[j] == candidates[j - 1])
            continue; // skip candidates that are equivalent
        // try either adding the current candidate
        combo.push_back(candidates[j]);
        dfsCombinationSumNoDup(answer, candidates, combo, target, j + 1, sum + candidates[j]);
        // or moving to the next candidate
        combo.pop_back();
    }
}

bool Backtracking::wordSearch(std::vector<std::vector<char>>& board, std::string word)
{
    if (word.size() < 1) return true;
    int m = static_cast<int>(board.size());
    int n = static_cast<int>(board[0].size());
    std::vector<std::pair<int, int>> startingcells;

    // search for starting cells
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
            if (board[i][j] == word[0])
                startingcells.push_back({ i, j });

    bool isFound = false;
    std::string curr;
    for (std::pair<int, int> cell : startingcells)
        dfsWordSearch(board, word, cell.first, cell.second, curr, isFound);

    return isFound;
}

void Backtracking::dfsWordSearch(std::vector<std::vector<char>>& board, const std::string& word, int i, int j, std::string& curr, bool& isFound)
{
    if (curr.size() >= word.size() ||
        i < 0 || i >= static_cast<int>(board.size()) ||
        j < 0 || j >= static_cast<int>(board[0].size()) ||
        board[i][j] == '#')
        return;

    char c = board[i][j];
    curr += c;
    board[i][j] = '#'; // marked as visited

    if (curr.compare(word) == 0)
        isFound = true;

    // directions to go
    dfsWordSearch(board, word, i + 1, j, curr, isFound);
    dfsWordSearch(board, word, i - 1, j, curr, isFound);
    dfsWordSearch(board, word, i, j + 1, curr, isFound);
    dfsWordSearch(board, word, i, j - 1, curr, isFound);

    board[i][j] = c; // unmark
    curr.pop_back(); // remove the last letter from string. this is cheaper than pass by value
}

std::vector<std::vector<std::string>> Backtracking::palindromePartition(const std::string& s)
{
    std::vector<std::vector<std::string>> answer;
    std::vector<std::string> partition;
    dfsPalindrome(answer, partition, s, 0);
    return answer;
}

void Backtracking::dfsPalindrome(std::vector<std::vector<std::string>>& answer, std::vector<std::string>& partition, const std::string& s, unsigned i)
{
    if (i >= s.size())
    {
        answer.push_back(partition);
        return;
    }

    for (unsigned j = i; j < s.size(); ++j)
    {
        if (isPalindrome(s.substr(i, j - i + 1)))
        {
            partition.push_back(s.substr(i, j - i + 1));
            dfsPalindrome(answer, partition, s, j + 1);
            partition.pop_back(); // backtrack
        }
    }
}

bool Backtracking::isPalindrome(const std::string& s)
{
    int n = static_cast<int>(s.size());
    for (int i = 0; i < n / 2; ++i)
        if (s[i] != s[n - i - 1])
            return false;
    return true;
}

std::vector<std::string> Backtracking::letterCombinations(const std::string& digits)
{
    std::vector<std::string> combinations;
    if (digits.size() < 1)
        return combinations;

    std::unordered_map<char, std::string> digitmap;
    digitmap['2'] = "abc";
    digitmap['3'] = "def";
    digitmap['4'] = "ghi";
    digitmap['5'] = "jkl";
    digitmap['6'] = "mno";
    digitmap['7'] = "pqrs";
    digitmap['8'] = "tuv";
    digitmap['9'] = "wxyz";

    std::string combo;
    dfsPhoneNumber(combinations, combo, digits, digitmap, 0, 0);
    return combinations;
}


void Backtracking::dfsPhoneNumber(std::vector<std::string>& combinations, std::string& combo, 
                                  const std::string& digits, std::unordered_map<char, std::string>& digitmap, 
                                  unsigned i, unsigned k)
{
    if (combo.size() == digits.size())
    {
        combinations.push_back(combo);
        return;
    }

    for (unsigned j = i; j < digits.size(); ++j)
    {
        std::string chars = digitmap[digits[j]];
        for (unsigned d = 0; d < chars.size(); ++d)
        {
            combo.push_back(chars[d]);
            dfsPhoneNumber(combinations, combo, digits, digitmap, j + 1, d + 1);
            combo.pop_back();
        }
    }
}


std::vector<std::vector<std::string>> Backtracking::solveNQueens(int n)
{
    // important trick about diagonals:
    // negative diagonals maintain that r - c is equivalent across the whole diagonal
    // in a similar way, positive diagonals maintain that r + c is equivalent.
    std::set<int> cols, negDiag, posDiag;
    std::vector<std::vector<std::string>> boards;
    std::vector<std::string> board(n, std::string(n, '.')); // initialize empty board (no queens yet)
    dfsNQueens(boards, board, 0, n, cols, negDiag, posDiag);
    return boards;
}

void Backtracking::dfsNQueens(std::vector<std::vector<std::string>>& boards, std::vector<std::string>& board, 
                              int r, int n, std::set<int>& cols, std::set<int>& posDiag, std::set<int>& negDiag)
{
    if (r == n) // if we made it to the last row, we know were done
    {
        boards.push_back(board);
        return;
    }

    for (int c = 0; c < n; ++c)
    {
        if (cols.find(c) != cols.end() ||
            posDiag.find(r + c) != posDiag.end() ||
            negDiag.find(r - c) != negDiag.end())
            continue;

        // try placing a queen here
        board[r][c] = 'Q';

        // update sets (applying lemma about diagonals mentioned above)
        cols.insert(c);
        posDiag.insert(r + c);
        negDiag.insert(r - c);
        dfsNQueens(boards, board, r + 1, n, cols, posDiag, negDiag);

        // backtracking step, reset position to empty and erase stored values from sets
        board[r][c] = '.';
        cols.erase(c);
        posDiag.erase(r + c);
        negDiag.erase(r - c);
    }
}