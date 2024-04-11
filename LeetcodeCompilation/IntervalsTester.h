#pragma once

#include "Intervals.h"
#include "Tester.h"


class IntervalsTester : public Tester
{
public:
    IntervalsTester() : Tester { "Bit Manipulation" } {}
    bool testAllProblems() override;
    std::unique_ptr<Tester> clone() const override { return std::make_unique<IntervalsTester>(*this); }

private:
    bool testInsert(std::vector<std::pair<int, int>> intervals, std::pair<int, int> newInterval, std::vector<std::pair<int, int>> expected);
    bool testMerge(std::vector<std::pair<int, int>> intervals, std::vector<std::pair<int, int>> expected);
    bool testMinEraseOverlapIntervals(std::vector<std::pair<int, int>> intervals, int expected);
    bool testMinIntervalToIncludeQuery(std::vector<std::pair<int, int>> intervals, std::vector<int> queries, std::vector<int> expected);

    // Summary Ranges
    // Min Number of Arrows to Burst Balloons
    // Non-Overlapping Intervals

    Intervals iv;
};