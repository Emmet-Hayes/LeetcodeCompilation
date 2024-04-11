#include "BinarySearch.h"


/** Binary Search (Microsoft - Easy)
* Given an array of integers nums which is sorted in ascending order, 
* and an integer target, write a function to search target in nums. 
* If target exists, then return its index. Otherwise, return -1.
* 
* Complexity:
* Time: O(log n)
* Space: O(1)
*/
int BinarySearch::binarySearch(const std::vector<int>& nums, int target)
{
    if (nums.size() == 1 && target == nums[0])
        return 0;

    int left = 0, right = static_cast<int>(nums.size()) - 1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (nums[mid] == target)
            return mid;
        else if (nums[mid] > target)
            right = mid - 1;
        else
            left = mid + 1;
    }

    return -1;
}


/** Search a 2D Matrix (Microsoft - Medium)
* You are given an m x n integer matrix matrix with the following two properties:
*
* Each row is sorted in non-decreasing order.
* The first integer of each row is greater than the last integer of the previous row.
*
* Given an integer target, return true if target is in matrix or false otherwise.
* 
* Complexity:
* Time: O(log n + log m)
* Space: O(1)
*/
std::pair<int, int> BinarySearch::searchMatrix(const std::vector<std::vector<int>>& matrix, int target)
{
    int m = static_cast<int>(matrix.size()), n = static_cast<int>(matrix[0].size());
    int uprow = 0, downrow = m - 1;

    while (uprow <= downrow)
    {
        int midrow = uprow + (downrow - uprow) / 2;
        if (matrix[midrow][0] == target)
            return { midrow, 0 };
        else if (matrix[midrow][n - 1] == target)
            return { midrow, n - 1 };
        else if (target > matrix[midrow][0] && target < matrix[midrow][n - 1])
        {
            int left = 0, right = n - 1;
            while (left <= right)
            {
                int midcol = left + (right - left) / 2;
                if (matrix[midrow][midcol] == target)
                    return { midrow, midcol };
                else if (matrix[midrow][midcol] < target)
                    left = ++midcol;
                else
                    right = --midcol;
            }

            return { -1, -1 }; // if row binary search fails
        }
        else if (matrix[midrow][0] < target) // try different upper row
            uprow = ++midrow;
        else  // try lower row
            downrow = --midrow;
    }

    return { -1, -1 };
}


/** Koko Eating Bananas (Google - Medium)
* 
* Koko loves to eat bananas. There are n piles of bananas, the ith pile has piles[i] bananas. 
* The guards have gone and will come back in h hours.
*
* Koko can decide her bananas-per-hour eating speed of k. Each hour, she chooses some pile 
* of bananas and eats k bananas from that pile. If the pile has less than k bananas, she 
* eats all of them instead and will not eat any more bananas during this hour.
*
* Koko likes to eat slowly but still wants to finish eating all the bananas before the 
* guards return.
*
* Return the minimum integer k such that she can eat all the bananas within h hours.
* 
* Complexity:
* Time: O(n log m) *where m is the maximum value in piles
* Space: O(1)
*/
int BinarySearch::kokoEatingBananas(const std::vector<int>& piles, int h)
{
    int left = 1;
    int right = INT_MIN;

    for (int i = 0; i < piles.size(); ++i)
        if (right < piles[i])
            right = piles[i];

    // now we find the smallest k such that koko finishes the bananas in h hours.        
    while (left < right)
    {
        int mid = left + (right - left) / 2;
        long long sum = 0;
        for (int i = 0; i < piles.size(); ++i)
        {
            if (piles[i] % mid == 0)
                sum += piles[i] / mid;
            else
                sum += piles[i] / mid + 1;
        }
        if (sum <= h)
            right = mid;
        else
            left = mid + 1;
    }

    return left;
}


/** Minimum Rotated Sorted Array (Meta - Medium)
* 
* Suppose an array of length n sorted in ascending order is rotated between 1 and n times. 
* For example, the array nums = [0,1,2,4,5,6,7] might become:
*
* [4,5,6,7,0,1,2] if it was rotated 4 times.
* [0,1,2,4,5,6,7] if it was rotated 7 times.
* Notice that rotating an array [a[0], a[1], a[2], ..., a[n-1]] 1 time results in 
* the array [a[n-1], a[0], a[1], a[2], ..., a[n-2]].
*
* Given the sorted rotated array nums of unique elements, return the minimum element 
* of this array.
* 
* Complexity:
* Time: O(log n)
* Space: O(1)
*/
int BinarySearch::minRotatedSortedArray(const std::vector<int>& nums)
{
    int left = 0, right = static_cast<int>(nums.size()) - 1;
    while (left < right)
    {
        int mid = left + (right - left) / 2;
        if (nums[mid] > nums[right])
            left = mid + 1;
        else
            right = mid;
    }

    return nums[left];
}


/** Search in Rotated Sorted Array (Google - Medium)
* There is an integer array nums sorted in ascending order (with distinct values).
*
* Prior to being passed to your function, nums is possibly rotated at an unknown pivot 
* index k (1 <= k < nums.length) such that the resulting array is 
* [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). 
* For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].
* 
* Given the array nums after the possible rotation and an integer target, return the index 
* of target if it is in nums, or -1 if it is not in nums.
* 
* Complexity:
* Time: O(log n)
* Space: O(1)
*/
int BinarySearch::searchRotatedSortedArray(const std::vector<int>& nums, int target)
{
    int left = 0, right = static_cast<int>(nums.size()) - 1;

    if (nums[left] == target)
        return left;
    if (nums[right] == target)
        return right;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (nums[mid] == target) return mid;

        if (nums[left] <= nums[mid])
        {
            if (target >= nums[left] && target < nums[mid])
                right = mid - 1;
            else
                left = mid + 1;
        }
        else
        {
            if (target > nums[mid] && target <= nums[right])
                left = mid + 1;
            else
                right = mid - 1;
        }
    }

    return -1;
}


/** Median of Two Sorted Arrays (Meta - Hard)
* 
* Given two sorted arrays nums1 and nums2 of size m and n respectively, 
* return the median of the two sorted arrays.
* 
* Complexity:
* Time: O(log (m + n))
* Space: O(1)
*/
double BinarySearch::medianTwoSortedArrays(const std::vector<int>& nums1, const std::vector<int>& nums2)
{
    if (nums1.size() > nums2.size())
        return medianTwoSortedArrays(nums2, nums1);

    int x = static_cast<int>(nums1.size());
    int y = static_cast<int>(nums2.size());
    int low = 0, high = x;

    while (low <= high)
    {
        int partitionX = (low + high) / 2;
        int partitionY = (x + y + 1) / 2 - partitionX;

        int maxLeftX = (partitionX == 0) ? INT_MIN : nums1[partitionX - 1];
        int minRightX = (partitionX == x) ? INT_MAX : nums1[partitionX];

        int maxLeftY = (partitionY == 0) ? INT_MIN : nums2[partitionY - 1];
        int minRightY = (partitionY == y) ? INT_MAX : nums2[partitionY];

        if (maxLeftX <= minRightY && maxLeftY <= minRightX)
        {
            if ((x + y) % 2 == 0)
                return (double(std::max(maxLeftX, maxLeftY)) + double(std::min(minRightX, minRightY))) / 2;
            else
                return (double)std::max(maxLeftX, maxLeftY);
        }
        else if (maxLeftX > minRightY)
            high = partitionX - 1;
        else
            low = partitionX + 1;
    }

    return -1;
}

/** Time-Based Key-Value Store (Google - Medium)
* Design a time-based key-value data structure that can store multiple values for the same key at different time stamps and retrieve the key's value at a certain timestamp.
*
* TimeMap class Implementation:
* 
* TimeMap() Initializes the object of the data structure.
* void set(String key, String value, int timestamp) Stores the key key with the value at 
* the given time timestamp.
* String get(String key, int timestamp) Returns a value such that set was called previously, 
* with timestamp_prev <= timestamp. If there are multiple such values, it returns the value 
* associated with the largest timestamp_prev. If there are no values, it returns "".
* 
* Complexity:
* Time: O(1) set, O(log n) get
* Space: O(1) set, O(1) get
*/
void BinarySearch::TimeMap::set(const std::string& key, const std::string& value, int timestamp)
{
    timeMap[key][timestamp] = value;
}

std::string BinarySearch::TimeMap::get(const std::string& key, int timestamp)
{
    if (timeMap.find(key) == timeMap.end())
        return "";

    // Find the first element greater than timestamp
    auto it = timeMap[key].upper_bound(timestamp); 
    if (it == timeMap[key].begin())
        return "";  // there is no element less than or equal to timestamp

    // Since we want the largest timestamp <= given timestamp, we go one step back.
    it--;
    return it->second; // Return the value associated with the timestamp we found.
}
