#include "IntervalsTester.h"


bool IntervalsTester::testAllProblems()
{
    addTestCase(testInsert({ { 1, 3 }, { 6, 9 } }, { 2, 5 }, { { 1, 5 }, { 6, 9 } }));
    addTestCase(testInsert({ { 1, 2 }, { 3, 5 }, { 6, 7 }, { 8, 10 }, { 12, 16 } }, { 4, 8 }, { { 1, 2 }, { 3, 10 }, { 12, 16 } }));

    addTestCase(testMerge({ { 1, 3 }, { 2, 6 }, { 8, 10 }, { 15, 18 } }, { { 1, 6 }, { 8, 10 }, { 15, 18 } }));
    addTestCase(testMerge({ { 1, 4 }, { 4, 5 } }, { { 1, 5 } }));

    addTestCase(testMinEraseOverlapIntervals({ { 1, 2 }, { 2, 3 }, { 3, 4 }, { 1 , 3} }, 1));
    addTestCase(testMinEraseOverlapIntervals({ { 1, 2 }, { 1, 2 }, { 1, 2 } }, 2));
    addTestCase(testMinEraseOverlapIntervals({ { 1, 2 }, { 2, 3 } }, 0));

    addTestCase(testMinIntervalToIncludeQuery({ { 1, 4 }, { 2, 4 }, { 3, 6 }, { 4, 4 } }, { 2, 3, 4, 5 }, { 3, 3, 1, 4 }));
    addTestCase(testMinIntervalToIncludeQuery({ { 2, 3 }, { 2, 5 }, { 1, 8 }, { 20, 25 } }, { 2, 19, 5, 22 }, { 2, -1, 4, 6 }));

    return runAllTests();
}

bool IntervalsTester::testInsert(std::vector<std::pair<int, int>> intervals, std::pair<int, int> newInterval, std::vector<std::pair<int, int>> expected)
{
    std::vector<std::pair<int, int>> actual = iv.insert(intervals, newInterval);
    if (getVerbose())
    {
        ss << "\nInsert Intervals Test Run on Input Pair Vector:\n[ ";
        for (std::pair<int, int> point : intervals)
            ss << "{ " << point.first << ", " << point.second << " } ";
        ss << "]\nNew Interval: { " << newInterval.first << ", " << newInterval.second << " }\nResult:   [ ";
        for (std::pair<int, int> point : actual)
            ss << "{ " << point.first << ", " << point.second << " } ";
        ss << "]\nExpected: [ ";
        for (std::pair<int, int> point : expected)
            ss << "{ " << point.first << ", " << point.second << " } ";
        ss << "]\n";
    }
    if (actual.size() != expected.size())
        return false;
    for (int i = 0; i < expected.size(); ++i)
        if (actual[i].first != expected[i].first || actual[i].second != expected[i].second)
            return false;
    return true;
}

bool IntervalsTester::testMerge(std::vector<std::pair<int, int>> intervals, std::vector<std::pair<int, int>> expected)
{
    std::vector<std::pair<int, int>> actual = iv.merge(intervals);
    if (getVerbose())
    {
        ss << "\nMerge Intervals Test Run on Input Pair Vector:\n[ ";
        for (std::pair<int, int> point : intervals)
            ss << "{ " << point.first << ", " << point.second << " } ";
        ss << "]\nResult:   [ ";
        for (std::pair<int, int> point : actual)
            ss << "{ " << point.first << ", " << point.second << " } ";
        ss << "]\nExpected: [ ";
        for (std::pair<int, int> point : expected)
            ss << "{ " << point.first << ", " << point.second << " } ";
        ss << "\n";
    }
    if (actual.size() != expected.size())
        return false;
    for (int i = 0; i < expected.size(); ++i)
        if (actual[i].first != expected[i].first || actual[i].second != expected[i].second)
            return false;
    return true;
}

bool IntervalsTester::testMinEraseOverlapIntervals(std::vector<std::pair<int, int>> intervals, int expected)
{
    int actual = iv.minEraseOverlapIntervals(intervals);
    if (getVerbose())
    {
        ss << "\nMinimum Erase Overlap Intervals Test Run on Input Pair Vector:\n [ ";
        for (std::pair<int, int> point : intervals)
            ss << "{ " << point.first << ", " << point.second << " } ";
        ss << "]\nResult: " << actual << " | Expected: " << expected << "\n";

    }
    return actual == expected;
}

bool IntervalsTester::testMinIntervalToIncludeQuery(std::vector<std::pair<int, int>> intervals, std::vector<int> queries, std::vector<int> expected)
{
    std::vector<int> actual = iv.minIntervalToIncludeQuery(intervals, queries);
    if (getVerbose())
    {
        ss << "\nMerge Intervals Test Run on Input Pair Vector:\n[ ";
        for (std::pair<int, int> point : intervals)
            ss << "{ " << point.first << ", " << point.second << " } ";
        ss << "]\nResult:   [ ";
        for (int val : actual)
            ss << val << " ";
        ss << "]\nExpected: [ ";
        for (int val : expected)
            ss << val << " ";
        ss << "]\n";
    }
    if (actual.size() != expected.size())
        return false;
    for (int i = 0; i < expected.size(); ++i)
        if (actual[i] != expected[i])
            return false;
    return true;
}
