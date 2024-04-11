#include "Intervals.h"

#include <algorithm>
#include <queue>
#include <unordered_map>


/**
* 
* 
* Complexity:
* Time: O(n)
* Space: O(n)
*/
std::vector<std::pair<int, int>> Intervals::insert(std::vector<std::pair<int, int>>& intervals, std::pair<int, int>& newInterval)
{
    std::vector<std::pair<int, int>> result;
    int i = 0, n = static_cast<int>(intervals.size());

    // add all intervals ending before newInterval start
    while (i < n && intervals[i].second < newInterval.first)
        result.push_back(intervals[i++]);

    // merge overlapping intervals into one
    while (i < n && intervals[i].first <= newInterval.second)
    {
        newInterval.first = std::min(newInterval.first, intervals[i].first);
        newInterval.second = std::max(newInterval.second, intervals[i].second);
        ++i;
    }
    result.push_back(newInterval);

    // add all intervals past newInterval end
    while (i < n)
        result.push_back(intervals[i++]);

    return result;
}


/**
*
*
* Complexity:
* Time: O(n log n)
* Space: O(n)
*/
std::vector<std::pair<int, int>> Intervals::merge(std::vector<std::pair<int, int>>& intervals)
{
    std::sort(intervals.begin(), intervals.end());
    int n = static_cast<int>(intervals.size());
    std::vector<std::pair<int, int>> answer;

    answer.push_back(intervals[0]);

    for (int i = 1; i < n; ++i)
    {
        if (intervals[i].first <= answer.back().second)
            answer.back().second = std::max(answer.back().second, intervals[i].second);
        else
            answer.push_back(intervals[i]);
    }

    return answer;
}


/**
*
*
* Complexity:
* Time: O(n log n)
* Space: O(1)
*/
int Intervals::minEraseOverlapIntervals(std::vector<std::pair<int, int>>& intervals)
{
    std::sort(intervals.begin(), intervals.end());

    int result = 0;
    int prevEnd = intervals[0].second;

    for (int i = 1; i < intervals.size(); ++i)
    {
        // not overlapping if the start is greater than or equal to previous end
        if (intervals[i].first >= prevEnd)
            prevEnd = intervals[i].second;
        // remove one of the intervals
        else
        {
            result += 1;
            prevEnd = std::min(prevEnd, intervals[i].second);
        }
    }

    return result;
}

/**
*
*
* Complexity:
* Time: O(n log n + q log q)
* Space: O(n + q)
*/
std::vector<int> Intervals::minIntervalToIncludeQuery(std::vector<std::pair<int, int>>& intervals, std::vector<int>& queries)
{
    std::priority_queue<std::vector<int>> pq;
    std::unordered_map<int, int> querymap;
    std::vector<int> queriescopy = queries, answer;

    std::sort(intervals.begin(), intervals.end());
    std::sort(queriescopy.begin(), queriescopy.end());

    int i = 0, n = static_cast<int>(intervals.size());

    for (int q : queriescopy)
    {
        while (i < n && intervals[i].first <= q)
        {
            int l = intervals[i].first, r = intervals[i++].second;
            pq.push({ l - r - 1, r });
        }

        while (pq.size() && pq.top()[1] < q)
            pq.pop();

        querymap[q] = pq.size() ? -pq.top()[0] : -1;
    }

    for (int q : queries)
        answer.push_back(querymap[q]);

    return answer;
}
