#pragma once

#include "Solution.h"

#include <vector>


class Intervals : public Solution
{
public:
    Intervals() : Solution("Intervals", "Common challenge problems involving intervals.") {}
    std::unique_ptr<Solution> clone() const override { return std::make_unique<Intervals>(*this); }

    std::vector<std::pair<int, int>> insert(std::vector<std::pair<int, int>>& intervals, std::pair<int, int>& newInterval);
    std::vector<std::pair<int, int>> merge(std::vector<std::pair<int, int>>& intervals);
    int minEraseOverlapIntervals(std::vector<std::pair<int, int>>& intervals);
    std::vector<int> minIntervalToIncludeQuery(std::vector<std::pair<int, int>>& intervals, std::vector<int>& queries);

    // Summary Ranges
    // Min Number of Arrows to Burst Balloons
    // Non-Overlapping Intervals
};