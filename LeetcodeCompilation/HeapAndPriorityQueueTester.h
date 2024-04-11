#pragma once

#include "HeapAndPriorityQueue.h"
#include "Tester.h"


class HeapAndPriorityQueueTester : public Tester
{
public:
    HeapAndPriorityQueueTester() : Tester { "Heap and Priority Queue" } {}
    bool testAllProblems() override;
    std::unique_ptr<Tester> clone() const override { return std::make_unique<HeapAndPriorityQueueTester>(*this); }

private:
    bool testLastStoneWeight(std::vector<int> stones, int expected);
    bool testKClosestPointsToOrigin(std::vector<std::pair<int, int>> points, int k, std::vector<std::pair<int, int>> expected);
    bool testFindKthLargestSelect(std::vector<int> nums, int k, int expected);
    bool testFindKthLargestHeap(std::vector<int> nums, int k, int expected);
    bool testTaskScheduler(std::vector<char> tasks, int n, int expected);
    bool testKthLargestStream(std::vector<int> nums, int k);
    bool testTwitterDesign();
    bool testMedianFinder();

    // IPO
    // K Pairs with Smallest Sums
    // Smallest Number in Infinite Set
    // Maximum Subsequence Score
    // Total Cost to Hire K Workers

    HeapAndPriorityQueue hpq;
};