#include "Greedy.h"

#include <algorithm>
#include <unordered_map>


/**
* 
* Complexity:
* Time: O(n)
* Space: O(1)
*/
int Greedy::maximumSubarray(const std::vector<int>& nums)
{
    int maxSum = nums[0];
    int curSum = 0;

    for (int n : nums)
    {
        curSum = std::max(curSum, 0); // choice of either taking the value or starting over
        curSum += n;
        maxSum = std::max(maxSum, curSum);
    }
    return maxSum;
}


/**
*
* Complexity:
* Time: O(n)
* Space: O(1)
*/
bool Greedy::jumpGame(const std::vector<int>& nums)
{
    unsigned maxReach = 0;

    for (unsigned i = 0; i < nums.size(); ++i)
    {
        if (i > maxReach)
            return false;
        maxReach = std::max(maxReach, i + nums[i]);
    }
    return maxReach >= nums.size() - 1;
}


/**
*
* Complexity:
* Time: O(n)
* Space: O(1)
*/
int Greedy::jumpGameMinJumps(const std::vector<int>& nums)
{
    unsigned maxReach = nums[0];
    unsigned currentEnd = nums[0];
    unsigned transitions = 0;

    if (nums.size() == 1)
        return 0;

    // if we can reach the end before going into loop
    if (maxReach >= nums.size() - 1)
        return 1;

    for (unsigned i = 1; i < nums.size(); ++i)
    {
        if (i > maxReach)
            return 0;
        maxReach = std::max(maxReach, i + nums[i]);

        if (currentEnd == i)
        {
            transitions++;
            currentEnd = maxReach;
        }

        if (currentEnd >= nums.size() - 1)
        {
            transitions++;
            break;
        }
    }

    return transitions;
}


/**
*
* Complexity:
* Time: O(n)
* Space: O(1)
*/
int Greedy::canCompleteCircuit(const std::vector<int>& gas, const std::vector<int>& cost)
{
    int gassum = 0, costsum = 0;
    for (unsigned i = 0; i < gas.size(); ++i)
        gassum += gas[i];

    for (unsigned i = 0; i < cost.size(); ++i)
        costsum += cost[i];

    if (gassum < costsum)
        return -1;

    int start = 0, tank = 0;
    for (unsigned i = 0; i < gas.size(); ++i)
    {
        tank += gas[i] - cost[i];
        if (tank < 0)
        {
            start = i + 1;
            tank = 0;
        }
    }

    return start;
}

bool Greedy::handOfStraights(std::vector<int>& hand, int groupSize)
{
    if (hand.size() % groupSize != 0) return false; // If hand size is not divisible by groupSize, return false

    std::sort(hand.begin(), hand.end()); // Step 1: Sort the hand
    std::unordered_map<int, int> countMap; // Step 2: Count the frequency of each card
    for (int card : hand)
        countMap[card]++;

    for (int card : hand)
    {
        if (countMap[card] > 0) // If the card can start a group
        {
            for (int i = 0; i < groupSize; i++)
            { // Try to form a group starting with this card
                if (countMap[card + i] > 0)
                    countMap[card + i]--; // Use this card in the group
                else
                    return false; // If any card needed for the group is missing, return false
            }
        }
    }

    return true; // If we've successfully formed all groups, return true
}

bool Greedy::mergeTriplets(const std::vector<std::vector<int>>& triplets, const std::vector<int>& target)
{
    std::vector<bool> found(3, false);
    // find the target triplet for each of the 3 indices by scanning the other triplets for the value you want
    for (unsigned i = 0; i < triplets.size(); ++i)
    {
        if (triplets[i][0] > target[0] || triplets[i][1] > target[1] || triplets[i][2] > target[2])
            continue;

        if (triplets[i][0] == target[0])
            found[0] = true;
        if (triplets[i][1] == target[1])
            found[1] = true;
        if (triplets[i][2] == target[2])
            found[2] = true;
    }

    return found[0] && found[1] && found[2];
}

std::vector<int> Greedy::partitionLabels(const std::string& s)
{
    // keep track of last index of each char
    std::unordered_map<char, int> lastmap;
    for (unsigned i = 0; i < s.size(); ++i)
        lastmap[s[i]] = i;

    std::vector<int> partitionsizes;
    int end = 0;
    int size = 0;
    for (int i = 0; i < static_cast<int>(s.size()); ++i)
    {
        size++;
        end = std::max(end, lastmap[s[i]]);
        if (i == end)
        {
            partitionsizes.push_back(size);
            size = 0;
        }
    }

    return partitionsizes;
}

bool Greedy::checkValidParenthesis(const std::string& s)
{
    int leftMin = 0, leftMax = 0;

    for (unsigned i = 0; i < s.size(); ++i)
    {
        if (s[i] == '(')
        {
            leftMin++;
            leftMax++;
        }
        else if (s[i] == ')')
        {
            leftMin--;
            leftMax--;
        }
        else
        {
            leftMin--;
            leftMax++;
        }
        if (leftMax < 0) return false;
        if (leftMin < 0) // s = ( * ) impossible string
        {
            leftMin = 0;
        }
    }

    return leftMin == 0;
}
