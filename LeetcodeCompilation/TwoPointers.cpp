#include "TwoPointers.h"

#include <algorithm>


/** Valid Palindrome (Spotify - Easy)
* A phrase is a palindrome if, after converting all uppercase letters 
* into lowercase letters and removing all non-alphanumeric characters, 
* it reads the same forward and backward. Alphanumeric characters 
* include letters and numbers.
*
* Given a string s, return true if it is a palindrome, or false otherwise.
* 
* Complexity:
* Time: O(n)
* Space: O(1)
*/
bool TwoPointers::isPalindrome(std::string& s)
{
    // remove non-alphanumeric characters from string
    s.erase(std::remove_if(s.begin(), s.end(), [](auto const& c) -> bool { return !std::isalnum(c); }), s.end());

    // remove uppercase
    for (int i = 0; i < s.size(); ++i)
        s[i] = tolower(s[i]);

    // check for palindrome
    for (int i = 0; i < s.size() / 2; ++i)
        if (s[i] != s[s.size() - 1 - i])
            return false;

    return true;
}


/** Two Sum II (Array is Given Sorted) (Amazon - Medium)
* Given a 0-indexed array of integers numbers that is already sorted 
* in non-decreasing order, find two numbers such that they add up to a 
* specific target number. Let these two numbers be numbers[index1] and 
* numbers[index2] where 1 <= index1 < index2 <= numbers.length.
* 
* Complexity:
* Time: O(n)
* Space: O(1)
*/
std::pair<int, int> TwoPointers::twoSumSorted(const std::vector<int>& numbers, int target)
{
    int left = 0, right = static_cast<int>(numbers.size()) - 1;
    while (left < right)
    {
        if (numbers[left] + numbers[right] == target)
            return { left, right };
        else if (numbers[left] + numbers[right] > target)
            right--;
        else
            left++;
    }

    return { -1, -1 }; // should never get here
}


/** Three Sum (Meta - Medium)
* Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] 
* such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.
* 
* Complexity:
* Time: O(n^2)
* Space: O(n)
*/
std::vector<std::tuple<int, int, int>> TwoPointers::threeSum(std::vector<int>& nums, int target)
{
    std::sort(nums.begin(), nums.end());
    std::vector<std::tuple<int, int, int>> result;
    int n = static_cast<int>(nums.size());

    for (int i = 0; i < n; ++i)
    {
        if (i > 0 && nums[i] == nums[i - 1]) continue; // skip duplicate elements

        // at each i we try for two more elements for the 3 sum.
        int left = i + 1, right = n - 1;
        while (left < right)
        {
            int total = nums[i] + nums[left] + nums[right];

            if (total == target)
            {
                result.push_back({ nums[i], nums[left], nums[right] });

                // skip duplicates as we search for another potential solution
                while (left < right && nums[left] == nums[left + 1]) left++;
                while (left < right && nums[right] == nums[right - 1]) right--;

                left++;
                right--;
            }
            else if (total < target)
                left++;
            else
                right--;
        }
    }
    return result;
}


/** Container With Most Water (Meta/Google - Medium)
* You are given an integer array height of length n. 
* There are n vertical lines drawn such that the two endpoints of the
* ith line are (i, 0) and (i, height[i]).
*
* Find two lines that together with the x-axis form a container, such 
* that the container contains the most water.
*
* Return the maximum amount of water a container can store.
* 
* Complexity:
* Time: O(n)
* Space: O(1)
*/
int TwoPointers::containerWithMostWater(const std::vector<int>& height)
{
    int low = 0;
    int high = static_cast<int>(height.size()) - 1;
    int maxarea = 0;

    while (low < high)
    {
        int area = std::min(height[low], height[high]) * (high - low);
        if (maxarea < area)
            maxarea = area;

        if (height[low] < height[high])
            low++;
        else
            high--;
    }

    return maxarea;
}


/** Trapping Rain Water (Google - Hard)
* Given n non-negative integers representing an elevation map where 
* the width of each bar is 1, compute how much water it can trap after raining.
*
* Complexity:
* Time: O(n)
* Space: O(1)
*/
int TwoPointers::trappingRainWater(const std::vector<int>& height)
{
    int n = static_cast<int>(height.size());
    int left = 0, right = n - 1;
    int leftMax = 0, rightMax = 0;
    int trappedWater = 0;

    while (left < right)
    {
        if (height[left] < height[right])
        {
            if (height[left] >= leftMax)
                leftMax = height[left];
            else
                // water is trapped between the current height and leftMax.
                trappedWater += leftMax - height[left];
            left++;
        }
        else
        {
            if (height[right] >= rightMax)
                rightMax = height[right];
            else
                // water is trapped between the current height and rightMax
                trappedWater += rightMax - height[right];
            right--;
        }
    }

    return trappedWater;
}
