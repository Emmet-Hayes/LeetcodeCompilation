#include "SlidingWindow.h"

#include <climits>
#include <unordered_map>
#include <deque>


/** Best Time to Buy and Sell Stock (Google - Easy)
* You are given an array prices where prices[i] is the price of a given stock 
* on the ith day.
*
* You want to maximize your profit by choosing a single day to buy one stock and 
* choosing a different day in the future to sell that stock.
*
* Return the maximum profit you can achieve from this transaction. If you cannot 
* achieve any profit, return 0.
* 
* Complexity:
* Time: O(n)
* Space: O(1)
*/
int SlidingWindow::bestTimeToBuyAndSellStock(const std::vector<int>& prices)
{
    int maxProfit = 0;
    int minCost = INT_MAX;

    for (int i = 0; i < prices.size(); ++i)
    {
        if (minCost > prices[i])
            minCost = prices[i]; // new cheapest cost seen
        else if (maxProfit < prices[i] - minCost)
            maxProfit = prices[i] - minCost;
    }

    return maxProfit;
}


/** Longest Substring without Repeating Characters (Meta - Medium)
* 
* Given a string s, find the length of the longest substring
* without repeating characters.
* 
* Complexity:
* Time: O(n)
* Space: O(k) *where k is the number of unique characters in s
*/
int SlidingWindow::lengthOfLongestSubstring(const std::string& s)
{
    std::unordered_map<char, int> charmap;
    int start = 0, maxlength = 0;

    for (int i = 0; i < s.size(); ++i)
    {
        if (charmap.find(s[i]) != charmap.end() && charmap[s[i]] >= start)
            start = charmap[s[i]] + 1;

        charmap[s[i]] = i; // last index of the character
        maxlength = std::max(maxlength, i - start + 1);
    }

    return maxlength;
}


/** Longest Repeating Character Replacement (Google - Medium)
* 
* You are given a string s and an integer k. You can choose any character of the string 
* and change it to any other uppercase English character. You can perform this operation 
* at most k times.
*
* Return the length of the longest substring containing the same letter you can get after 
* performing the above operations.
* 
* Complexity:
* Time: O(n)
* Space: O(k) *where k is the number of unique characters in s
*/
int SlidingWindow::longestRepeatingCharacterReplacement(const std::string& s, int k)
{
    std::unordered_map<char, int> charmap;
    int left = 0;
    int count = 0;
    int mostFreq = 0;

    for (int right = 0; right < s.size(); ++right)
    {
        charmap[s[right]]++;

        // keep track of most frequent occuring character
        mostFreq = std::max(charmap[s[right]], mostFreq);

        // slide the left pointer whenever we require more than k replacements
        while ((right - left + 1) - mostFreq > k)
            charmap[s[left++]]--;

        count = std::max(count, right - left + 1);
    }

    return count;
}


/** Permutation in String (Microsoft - Medium)
* Given two strings s1 and s2, return true if s2 contains a permutation of s1, 
* or false otherwise.
* 
* In other words, return true if one of s1's permutations is the substring of s2.
* 
* Complexity:
* Time: O(n + m) *where n and m are the lengths of s1 and s2
* Space: O(k) *where k is the number of unique characters in s1 and s2
*/
bool SlidingWindow::permutationInString(const std::string& s1, const std::string& s2)
{
    std::unordered_map<char, int> hmap1;
    std::unordered_map<char, int> hmap2;

    if (s1.size() > s2.size()) return false;

    for (int i = 0; i < s1.size(); i++)
    {
        hmap1[s1[i]]++;
        hmap2[s2[i]]++;
    }

    for (int i = static_cast<int>(s1.size()); i < s2.size(); i++)
    {
        if (hmap1 == hmap2)
            return true;
        else
        {
            hmap2[s2[i - s1.size()]]--;
            if (hmap2[s2[i - s1.size()]] == 0)
                hmap2.erase(s2[i - s1.size()]);
            hmap2[s2[i]]++;
        }
    }

    return hmap1 == hmap2;
}


/** Minimum Window Substring (Airbnb - Hard)
* Given two strings s and t of lengths m and n respectively, 
* return the minimum window substring of s such that every character in t 
* (including duplicates) is included in the window. If there is no such substring, 
* return the empty string "".
* 
* Complexity: 
* Time: O(n + m) *where n and m are the lengths of s and t
* Space: O(k) *where k is the number of unique characters in s and t
*/
std::string SlidingWindow::minimumWindowSubstring(const std::string& s, const std::string& t)
{
    int m = static_cast<int>(s.size()), n = static_cast<int>(t.size());
    std::unordered_map<char, int> tmap;

    for (int i = 0; i < t.size(); ++i)
        tmap[t[i]]++;

    std::unordered_map<char, int> windowcounts;

    int left = 0, right = 0, formed = 0, minLeft = 0,
        required = static_cast<int>(tmap.size()), minLength = INT_MAX;

    for (right = 0; right < s.size(); ++right)
    {
        char c = s[right];
        windowcounts[c]++;

        if (tmap.count(c) && windowcounts[c] == tmap[c])
            formed++;

        // contract the window until point where it ceases to form substring
        while (left <= right && formed == required)
        {
            c = s[left];

            // update the minimum window if smaller than minlength
            if (right - left + 1 < minLength)
            {
                minLength = right - left + 1;
                minLeft = left;
            }

            // character at left pointer is no longer in the window
            windowcounts[c]--;
            if (tmap.count(c) && windowcounts[c] < tmap[c])
                formed--;

            left++; // contract the window
        }
    }

    return minLength == INT_MAX ? "" : s.substr(minLeft, minLength);
}


/** Max Sliding Window (Google - Hard)
* You are given an array of integers nums, there is a sliding window of size k 
* which is moving from the very left of the array to the very right. You can 
* only see the k numbers in the window. Each time the sliding window moves right 
* by one position.
*
* Return the max sliding window.
* 
* Time: O(n)
* Space: O(n)
*/
std::vector<int> SlidingWindow::maxSlidingWindow(const std::vector<int>& nums, int k)
{
    // monotonically decreasing queue of indices (front is max)
    std::deque<int> deq;
    std::vector<int> answer;
    int n = static_cast<int>(nums.size());

    for (int i = 0; i < n; ++i)
    {
        // Remove indices of elements that are not in the current window from the front
        if (!deq.empty() && deq.front() < i - k + 1)
            deq.pop_front();

        // pop all smaller values from the back
        while (!deq.empty() && nums[deq.back()] < nums[i])
            deq.pop_back();

        // add current element to the back
        deq.push_back(i);

        // if the window has reached the size, add the current max to the answer
        if (i >= k - 1)
            answer.push_back(nums[deq.front()]);
    }
    return answer;
}
