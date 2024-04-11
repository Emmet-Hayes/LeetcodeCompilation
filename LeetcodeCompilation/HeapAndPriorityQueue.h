#pragma once

#include "Solution.h"

#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>


class HeapAndPriorityQueue : public Solution
{
public:
    HeapAndPriorityQueue() : Solution("HeapAndPriorityQueue", "Common challenge problems involving heaps and priority queues.") {}
    std::unique_ptr<Solution> clone() const override { return std::make_unique<HeapAndPriorityQueue>(*this); }
    
    int lastStoneWeight(const std::vector<int>& stones);
    std::vector<std::pair<int, int>> kClosestPointsToOrigin(const std::vector<std::pair<int, int>>& points, int k);
    int findKthLargestSelect(std::vector<int>& nums, int k);
    int findKthLargestHeap(std::vector<int>& nums, int k);
    int taskScheduler(const std::vector<char>& tasks, int n);

    // IPO
    // K Pairs with Smallest Sums
    // Smallest Number in Infinite Set
    // Maximum Subsequence Score
    // Total Cost to Hire K Workers

    class KthLargest
    {
    public:
        KthLargest(int k, const std::vector<int>& nums);
        int add(int val);

    private:
        std::priority_queue<int, std::vector<int>, std::greater<int>> minheap;
        const int _k;
    };

    class Select
    {
    public:
        int select(int* a, int n_0, int n, int k);
    private:
        int partition(int* a, int n, int k, int x);
        int findMedian(int* a, int n);
    };
    

    class Twitter
    {
    public:
        Twitter() {}
        void postTweet(int userId, int tweetId);
        std::vector<int> getNewsFeed(int userId);
        void follow(int followerId, int followeeId);
        void unfollow(int followerId, int followeeId);

    private:
        int time = 0;
        std::unordered_map<int, std::vector<std::pair<int, int>>> tweetMap;
        std::unordered_map<int, std::unordered_set<int>> followerMap;
    };


    class MedianFinder
    {
    public:
        MedianFinder() {}
        void addNum(int num);
        double findMedian();

    private:
        int count = 0;
        std::priority_queue<int> maxHeap; // store max near median
        std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap; // store min near median
    };
};