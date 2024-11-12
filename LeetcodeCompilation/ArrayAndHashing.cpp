#include "ArrayAndHashing.h"

#include <algorithm>
#include <unordered_set>
#include <unordered_map>


/** Contains Duplicate (Microsoft - Easy)
* Given an integer array nums, return true if any value appears 
* at least twice in the array, and return false if every element 
* is distinct.
* 
* Complexity:
* Time:  O(n log n)
* Space: O(1)
*/
bool ArrayAndHashing::containsDuplicate(std::vector<int>& nums)
{
    std::sort(nums.begin(), nums.end());

    for (unsigned i = 1; i < nums.size(); ++i)
        if (nums[i] == nums[i - 1])
            return true;

    return false;
}


/** Contains Duplicate (Microsoft - Easy)
* Given an integer array nums, return true if any value appears
* at least twice in the array, and return false if every element
* is distinct.
*
* This solution runs faster than the above version at the cost of memory.
* 
* Complexity:
* Time:  O(n)
* Space: O(n)
*/
bool ArrayAndHashing::containsDuplicateFast(const std::vector<int>& nums)
{
    std::unordered_set<int> values;

    for (unsigned i = 0; i < nums.size(); ++i)
    {
        if (values.find(nums[i]) != values.end())
            return true;
        else
            values.insert(nums[i]);
    }
    return false;
}


/** Is Anagram (Uber - Easy)
* Given two strings s and t, return true if t is an anagram of s, 
* and false otherwise.
*
* An Anagram is a word or phrase formed by rearranging the letters 
* of a different word or phrase, typically using all the original 
* letters exactly once.
* 
* Complexity:
* Time:  O(n)
* Space: O(n)
*/
bool ArrayAndHashing::isAnagram(const std::string& s, const std::string& t)
{
    if (s.size() != t.size())
        return false;

    std::unordered_map<char, int> charmaps;
    std::unordered_map<char, int> charmapt;

    for (unsigned i = 0; i < s.size(); ++i)
        charmaps[s[i]]++;

    for (unsigned i = 0; i < t.size(); ++i)
        charmapt[t[i]]++;

    for (auto& pair : charmaps)
        if (charmaps[pair.first] != charmapt[pair.first])
            return false;

    return true;
}


/** Two Sum (Google - Easy)
* Given an array of integers nums and an integer target, return indices 
* of the two numbers such that they add up to target.
* 
* You may assume that each input would have exactly one solution, and you 
* may not use the same element twice.
*
* Complexity:
* Time:  O(n log n)
* Space: O(n)
*/
std::pair<int, int> ArrayAndHashing::twoSum(const std::vector<int>& nums, int target)
{
    std::vector<std::pair<int, int>> numsWithIndices;

    for (unsigned i = 0; i < nums.size(); ++i)
        numsWithIndices.push_back({ nums[i], i });

    // Sort the array based on the values
    sort(numsWithIndices.begin(), numsWithIndices.end());

    int left = 0, right = static_cast<int>(nums.size()) - 1;

    // Use two pointers to find the two sum
    while (left < right)
    {
        int sum = numsWithIndices[left].first + numsWithIndices[right].first;

        if (sum == target)
            return { numsWithIndices[left].second, numsWithIndices[right].second };
        else if (sum < target)
            ++left;
        else
            --right;
    }

    return {};
}


/** Two Sum Fast (Google - Easy)
* Given an array of integers nums and an integer target, return indices
* of the two numbers such that they add up to target.
*
* You may assume that each input would have exactly one solution, and you
* may not use the same element twice.
*
* This solution runs faster than the above version at the cost of memory.
* 
* Complexity:
* Time:  O(n)
* Space: O(n)
*/
std::pair<int, int> ArrayAndHashing::twoSumFast(const std::vector<int>& nums, int target)
{
    std::unordered_map<int, int> indexmap;

    for (unsigned i = 0; i < nums.size(); ++i)
    {
        if (indexmap.find(target - nums[i]) != indexmap.end())
            return { indexmap[target - nums[i]], i };
        else
            indexmap[nums[i]] = i;
    }
    return {};
}

/** Group Anagrams (Amazon - Medium)
* Given an array of strings strs, group the anagrams together. 
* You can return the answer in any order.
*
* An Anagram is a word or phrase formed by rearranging the letters 
* of a different word or phrase, typically using all the original 
* letters exactly once.
* 
* Complexity:
* Time:  O(n * k log k)
* Space: O(n * k)
*/
std::vector<std::vector<std::string>> ArrayAndHashing::groupAnagrams(const std::vector<std::string>& strs)
{
    std::unordered_map<std::string, std::vector<std::string>> anagrammap;
    for (const std::string& str : strs)
    {
        std::string key = str;
        std::sort(key.begin(), key.end()); // sorting strings makes anagrams equivalent.
        anagrammap[key].push_back(str); // push original string into the hashmap as a value for the sorted key
    }

    std::vector<std::vector<std::string>> anagrams;
    for (auto& pair : anagrammap)
        anagrams.push_back(pair.second);

    return anagrams;
}


/** Top K Frequent Elements (Amazon - Medium)
* Given an integer array nums and an integer k, return the k most frequent elements. 
*
* Complexity:
* Time: O(n)
* Space: O(n)
*/
std::vector<int> ArrayAndHashing::topKFrequent(const std::vector<int>& nums, int k)
{
    // count occurences of each value
    std::unordered_map<int, int> countmap;
    int n = static_cast<int>(nums.size());
    for (unsigned i = 0; i < nums.size(); ++i)
        countmap[nums[i]]++;

    // now we make buckets to store the number of occurences of each value
    std::vector<std::vector<int>> countbuckets(n + 1);
    for (const auto& pair : countmap)
        countbuckets[pair.second].push_back(pair.first);

    // Construct the final answer by iterating through buckets from highest to lowest frequency
    std::vector<int> answer;
    for (int freq = n; freq >= 0 && static_cast<int>(answer.size()) < k; --freq) 
    {
        for (const int& num : countbuckets[freq]) 
        {
            answer.push_back(num);
            if (static_cast<int>(answer.size()) == k) 
                // Stop once we've added k elements to the answer
                break;
        }
    }

    return answer;
}

/** Top K Frequent Elements (Amazon - Medium)
* Given an integer array nums and an integer k, return the k most frequent elements.
*
* This is simply another nearly-optimal solution, but k log n might dominate.
* 
* Complexity:
* Time: O(n + k log n)
* Space: O(n)
*/
std::vector<int> ArrayAndHashing::topKFrequentAlt(const std::vector<int>& nums, int k)
{
    // count occurences of each value
    std::unordered_map<int, int> countmap;
    for (unsigned i = 0; i < nums.size(); ++i)
        countmap[nums[i]]++;

    // prepare a vector to be heapified
    std::vector<std::pair<int, int>> heapVec;
    for (const auto& pair : countmap)
        heapVec.push_back(pair);

    // comparator for max heap
    auto cmp = [](std::pair<int, int> left, std::pair<int, int> right) {
        return left.second < right.second; // descending order
        };

    // O(n) heapify from STL
    std::make_heap(heapVec.begin(), heapVec.end(), cmp);

    // finally, construct the final answer by popping k elements O(k log n)
    std::vector<int> answer;
    for (int i = 0; i < k; ++i)
    {
        std::pop_heap(heapVec.begin(), heapVec.end(), cmp);
        answer.push_back(heapVec.back().first);
        heapVec.pop_back();
    }

    return answer;
}


/** Product of Array Except Self (Amazon - Medium)
* Given an integer array nums, return an array answer such that answer[i] 
* is equal to the product of all the elements of nums except nums[i].
* The product of any prefix or suffix of nums is guaranteed to fit in a 
* 32-bit integer.
* 
* Complexity:
* Time: O(n)
* Space: O(1) except for final result array, which is O(n)
*/
std::vector<int> ArrayAndHashing::productExceptSelf(const std::vector<int>& nums)
{
    int n = static_cast<int>(nums.size());

    std::vector<int> answer(n, 1);

    int prefix = 1;
    for (int i = 0; i < n; ++i)
    {
        answer[i] = prefix;
        prefix *= nums[i];
    }

    int suffix = 1;
    for (int i = n - 1; i >= 0; --i)
    {
        answer[i] *= suffix;
        suffix *= nums[i];
    }

    return answer;
}


/** Is Valid Sudoku (Amazon - Medium)
* Determine if a 9 x 9 Sudoku board is valid. 
* Only the filled cells need to be validated according to the following rules:
* 
* Each row must contain the digits 1-9 without repetition.
* Each column must contain the digits 1-9 without repetition.
* Each of the nine 3 x 3 sub-boxes of the grid must contain 
* the digits 1-9 without repetition.
* 
* Complexity:
* Time: O(1) - 243 operations total
* Space: O(1)
*/
bool ArrayAndHashing::isValidSudoku(const std::vector<std::vector<char>>& board)
{
    // scan horizontally
    for (unsigned i = 0; i < board.size(); ++i)
    {
        std::unordered_map<char, int> horizontalmap;
        for (unsigned j = 0; j < board[i].size(); ++j)
        {
            char val = board[i][j];
            if (val != '.')
            {
                horizontalmap[val]++;
                if (horizontalmap[val] > 1)
                    return false;
            }
        }
    }

    // scan vertically
    for (unsigned i = 0; i < board.size(); ++i)
    {
        std::unordered_map<char, int> verticalmap;
        for (unsigned j = 0; j < board[i].size(); ++j)
        {
            char val = board[j][i];
            if (val != '.')
            {
                verticalmap[val]++;
                if (verticalmap[val] > 1)
                    return false;
            }
        }
    }

    // scan boxes
    for (int boxrow = 0; boxrow < 9; boxrow += 3)
    {
        for (int boxcol = 0; boxcol < 9; boxcol += 3)
        {
            std::unordered_map<char, int> boxmap;
            for (int i = 0; i < 3; ++i)
            {
                for (int j = 0; j < 3; ++j)
                {
                    char val = board[boxrow + i][boxcol + j];
                    if (val != '.')
                    {
                        boxmap[val]++;
                        if (boxmap[val] > 1)
                            return false;
                    }
                }
            }
        }
    }

    return true;
}


/** Longest Consecutive Sequence (Google - Medium)
* Given an unsorted array of integers nums, 
* return the length of the longest consecutive elements sequence.
* 
* Complexity:
* Time: O(n)
* Space: O(n)
*/
int ArrayAndHashing::longestConsecutiveSequence(const std::vector<int>& nums)
{
    std::unordered_set<int> numset(nums.begin(), nums.end());

    int longestconsecutivecount = 0;
    for (unsigned i = 0; i < nums.size(); ++i)
    {
        // only count if num is the start of a sequence
        if (!numset.count(nums[i] - 1))
        {
            int curr = nums[i];
            int currcount = 1;
            while (numset.count(curr + 1))
            {
                curr++;
                currcount++;
            }

            if (longestconsecutivecount < currcount)
                longestconsecutivecount = currcount;
        }
    }

    return longestconsecutivecount;
}

/**
* 
* Complexity:
* Time: O(m + n)
* Space: O(m + n)
*/
void ArrayAndHashing::mergeSortedArray(std::vector<int>& nums1, int m, const std::vector<int>& nums2, int n)
{
    std::vector<int> mergednums;

    int nums1index = 0;
    int nums2index = 0;

    while (nums1index < m && nums2index < n)
    {
        if (nums1[nums1index] < nums2[nums2index])
        {
            mergednums.push_back(nums1[nums1index]);
            nums1index++;
        }
        else
        {
            mergednums.push_back(nums2[nums2index]);
            nums2index++;
        }
    }

    while (nums1index < m)
    {
        mergednums.push_back(nums1[nums1index]);
        nums1index++;
    }

    while (nums2index < n)
    {
        mergednums.push_back(nums2[nums2index]);
        nums2index++;
    }

    for (unsigned i = 0; i < mergednums.size(); ++i)
        nums1[i] = mergednums[i];
}

int ArrayAndHashing::removeElement(std::vector<int>& nums, int val)
{
    int index = 0;
    for (unsigned i = 0; i < nums.size(); i++)
    {
        if (nums[i] != val)
        {
            nums[index] = nums[i];
            index++;
        }
    }
    return index;
}

int ArrayAndHashing::removeDuplicatesSortedArray(std::vector<int>& nums)
{
    if (nums.size() == 0)
        return nums.size();

    int writeindex = 1;
    for (unsigned readindex = 1; readindex < nums.size(); ++readindex)
    {
        if (nums[readindex] != nums[readindex - 1])
        {
            nums[writeindex] = nums[readindex];
            writeindex++;
        }
    }

    return writeindex;
}

int ArrayAndHashing::removeDuplicatesSortedArrayMostTwice(std::vector<int>& nums)
{
    if (nums.size() < 3) return nums.size();

    int k = 2; // start at 3rd element (slow pointer)
    for (unsigned i = 2; i < nums.size(); ++i) // i is fast pointer
        if (nums[i] != nums[k - 2])
            nums[k++] = nums[i];

    return k;
}

int ArrayAndHashing::majorityElement(const std::vector<int>& nums)
{
    // Boyer-Moore Majority Vote Algorithm
    int count = 0;
    int major = 0;

    for (unsigned i = 0; i < nums.size(); ++i)
    {
        if (count == 0)
            major = nums[i];
        count += (nums[i] == major) ? 1 : -1;
    }

    return major;
}

void ArrayAndHashing::rotateArray(std::vector<int>& nums, int k)
{
    k %= nums.size(); // normalizing k
    reverseArray(nums.begin(), nums.end());
    reverseArray(nums.begin(), nums.begin() + k);
    reverseArray(nums.begin() + k, nums.end());
}

void ArrayAndHashing::reverseArray(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
    while ((begin != end) && (begin != --end))
        std::swap(*begin++, *end);
}

int ArrayAndHashing::hIndex(std::vector<int>& citations)
{
    int maxh = citations.size();
    sort(citations.begin(), citations.end());

    for (int i = 0; i < maxh; ++i)
    {
        int h = maxh - i;
        if (citations[i] >= h)
            return h;
    }

    return 0;
}

int ArrayAndHashing::candy(std::vector<int>& ratings)
{
    int n = ratings.size();
    std::vector<int> candies(n, 1);

    // left to right pass
    for (int i = 1; i < n; ++i)
        if (ratings[i] > ratings[i - 1])
            candies[i] = candies[i - 1] + 1;

    // right to left pass, make sure high rated kids get more than neighbors
    for (int i = n - 2; i >= 0; --i)
        if (ratings[i] > ratings[i + 1])
            candies[i] = std::max(candies[i], candies[i + 1] + 1);

    // add up all the candies counted
    int totalCandies = 0;
    for (int candy : candies)
        totalCandies += candy;

    return totalCandies;
}

int ArrayAndHashing::romanToInteger(std::string s)
{
    int translation = 0;
    for (unsigned i = 0; i < s.size(); ++i)
    {
        switch (s[i])
        {
        case 'M': translation += 1000; break;
        case 'D': translation += 500; break;
        case 'C': translation += 100; break;
        case 'L': translation += 50; break;
        case 'X': translation += 10; break;
        case 'V': translation += 5; break;
        case 'I': translation += 1; break;
        }
    }

    // now we do a pass for the prefix cases
    for (unsigned i = 1; i < s.size(); ++i)
    {
        if (s[i] == 'V' || s[i] == 'X')
            if (s[i - 1] == 'I')
                translation -= 2;
        if (s[i] == 'L' || s[i] == 'C')
            if (s[i - 1] == 'X')
                translation -= 20;
        if (s[i] == 'D' || s[i] == 'M')
            if (s[i - 1] == 'C')
                translation -= 200;
    }
    return translation;
}

std::string ArrayAndHashing::integerToRoman(int num)
{
    std::string roman;
    while (num > 0)
    {
        if (num >= 1000)
        {
            roman += 'M';
            num -= 1000;
        }
        else if (num >= 900)
        {
            roman += "CM";
            num -= 900;
        }
        else if (num >= 500)
        {
            roman += 'D';
            num -= 500;
        }
        else if (num >= 400)
        {
            roman += "CD";
            num -= 400;
        }
        else if (num >= 100)
        {
            roman += "C";
            num -= 100;
        }
        else if (num >= 90)
        {
            roman += "XC";
            num -= 90;
        }
        else if (num >= 50)
        {
            roman += 'L';
            num -= 50;
        }
        else if (num >= 40)
        {
            roman += "XL";
            num -= 40;
        }
        else if (num >= 10)
        {
            roman += 'X';
            num -= 10;
        }
        else if (num >= 9)
        {
            roman += "IX";
            num -= 9;
        }
        else if (num >= 5)
        {
            roman += 'V';
            num -= 5;
        }
        else if (num >= 4)
        {
            roman += "IV";
            num -= 4;
        }
        else if (num >= 1)
        {
            roman += 'I';
            num -= 1;
        }
    }
    return roman;
}

bool ArrayAndHashing::RandomizedSet::insert(int val)
{
    if (numMap.find(val) != numMap.end())
        return false;
    numMap[val] = nums.size();
    nums.push_back(val);
    return true;
}

bool ArrayAndHashing::RandomizedSet::remove(int val)
{
    if (numMap.find(val) == numMap.end())
        return false;

    // Move the last element to the place of the element to delete
    int lastElement = nums.back();
    int idx = numMap[val];
    nums[idx] = lastElement;
    numMap[lastElement] = idx;

    // Remove the last element
    nums.pop_back();
    numMap.erase(val);
    return true;
}

int ArrayAndHashing::RandomizedSet::getRandom()
{
    int randomIndex = rand() % nums.size();
    return nums[randomIndex];
}
