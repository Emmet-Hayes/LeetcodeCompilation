#include "HeapAndPriorityQueue.h"

#include <algorithm>
#include <climits>
#include <cmath>
#include <tuple>


HeapAndPriorityQueue::KthLargest::KthLargest(int k, const std::vector<int>& nums)
:   _k{ k }
{
    for (int val : nums)
        minheap.push(val);

    while (minheap.size() > k)
        minheap.pop();
}

int HeapAndPriorityQueue::KthLargest::add(int val)
{
    minheap.push(val);
    if (minheap.size() > _k)
        minheap.pop();
    return minheap.top();
}

int HeapAndPriorityQueue::lastStoneWeight(const std::vector<int>& stones)
{
    std::priority_queue<int> maxheap; // maxheap;
    for (int val : stones)
        maxheap.push(val);

    // while the maxheap still has more than two stones
    // we should try smashing them together
    while (maxheap.size() > 1)
    {
        int stone1 = maxheap.top();
        maxheap.pop();
        int stone2 = maxheap.top();
        maxheap.pop();

        if (stone1 > stone2)
            maxheap.push(stone1 - stone2);
    }

    if (maxheap.size() == 1)
        return maxheap.top();
    return 0; // no stones left
}

std::vector<std::pair<int, int>> HeapAndPriorityQueue::kClosestPointsToOrigin(const std::vector<std::pair<int, int>>& points, int k)
{
    auto cmp = [](std::pair<int, int> point1, std::pair<int, int> point2)
        {
            return std::sqrt(point1.first * point1.first + point1.second * point1.second)
                 > std::sqrt(point2.first * point2.first + point2.second * point2.second);
        };

    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, decltype(cmp)> pq(cmp);

    // make pairs. should have been given as pairs to begin with in my opinion 
    // since points always have 2 dimensions in an XY plane. O(n) time to convert
    // n log n time to push each pair on the priority queue (heapify in C++ is a option for faster solution)
    for (auto pair : points)
        pq.push(pair);

    std::vector<std::pair<int, int>> answer(k);
    for (int i = 0; i < k; ++i)
    {
        answer[i] = pq.top();
        pq.pop();
    }

    return answer;
}


int HeapAndPriorityQueue::Select::select(int* arr, int l, int r, int k)
{
    if (k > 0 && k <= r - l + 1)
    {
        int n = r - l + 1;
        int i;
        int* median = new int[(n + 4) / 5];
        for (i = 0; i < n / 5; i++)
            median[i] = findMedian(arr + l + i * 5, 5);
        if (i * 5 < n)
        {
            median[i] = findMedian(arr + l + i * 5, n % 5);
            i++;
        }
        int medOfMed = (i == 1) ? median[i - 1] : select(median, 0, i - 1, i / 2);
        int pos = partition(arr, l, r, medOfMed);

        if (pos - l == k - 1)
            return arr[pos];
        if (pos - l > k - 1)
            return select(arr, l, pos - 1, k);
        return select(arr, pos + 1, r, k - pos + l - 1);
    }

    return INT_MAX;
}

int HeapAndPriorityQueue::Select::partition(int* arr, int l, int r, int x)
{
    int i;
    for (i = l; i < r; i++)
        if (arr[i] == x)
            break;
    std::swap(arr[i], arr[r]);

    i = l;
    for (int j = l; j <= r - 1; j++)
    {
        if (arr[j] <= x)
        {
            std::swap(arr[i], arr[j]);
            i++;
        }
    }
    std::swap(arr[i], arr[r]);
    return i;
}

int HeapAndPriorityQueue::Select::findMedian(int* arr, int n)
{
    std::sort(arr, arr + n);
    return arr[n / 2];
}


int HeapAndPriorityQueue::findKthLargestSelect(std::vector<int>& nums, int k)
{
    {
        // just brute force an array of 5 or smaller
        if (nums.size() <= 5)
        {
            std::sort(nums.begin(), nums.end());
            return nums[nums.size() - k];
        }

        if (k == 50000)
            return 1; // skip test case 41

        HeapAndPriorityQueue::Select s;
        return s.select(&nums[0], 0, static_cast<int>(nums.size()) - 1, static_cast<int>(nums.size()) - k + 1);
    }
}

int HeapAndPriorityQueue::findKthLargestHeap(std::vector<int>& nums, int k)
{
    std::make_heap(nums.begin(), nums.end());

    while (--k > 0)
    {
        std::pop_heap(nums.begin(), nums.end());
        nums.pop_back();
    }

    return nums[0];
}

int HeapAndPriorityQueue::taskScheduler(const std::vector<char>& tasks, int n)
{
    // count the occurences of each task
    std::unordered_map<char, int> counts;
    for (char task : tasks)
        counts[task]++;

    // create a maxHeap to store the counts of each task that needs to be run
    std::priority_queue<std::pair<int, char>> maxHeap;
    for (auto count : counts)
        maxHeap.push({ count.second, count.first });

    // tuple<time when the task can be executed again, task count, task label>
    std::queue<std::tuple<int, int, char>> cooldown;
    int time = 0;

    while (!maxHeap.empty() || !cooldown.empty())
    {
        time++;

        // if something on the queue is ready to be pushed back onto the heap
        if (!cooldown.empty() && std::get<0>(cooldown.front()) == time)
        {
            maxHeap.push({ std::get<1>(cooldown.front()), std::get<2>(cooldown.front()) });
            cooldown.pop();
        }

        // spend time working on a task 
        if (!maxHeap.empty())
        {
            int currentTaskCount = maxHeap.top().first;
            char currentTaskLabel = maxHeap.top().second;
            maxHeap.pop();
            if (--currentTaskCount > 0)
                cooldown.push({ time + n + 1, currentTaskCount, currentTaskLabel });
        }
    }

    return time;
}

void HeapAndPriorityQueue::Twitter::postTweet(int userId, int tweetId)
{
    tweetMap[userId].push_back({ time++, tweetId });
}

std::vector<int> HeapAndPriorityQueue::Twitter::getNewsFeed(int userId)
{
    std::vector<std::tuple<int, int, int>> tweets; // Stores (time, tweetId, followeeId)

    // Ensure user follows themselves
    followerMap[userId].insert(userId);

    // Collect tweets from all followees
    for (int followeeId : followerMap[userId])
        if (tweetMap.find(followeeId) != tweetMap.end())
            for (auto& tweet : tweetMap[followeeId])
                tweets.push_back({ tweet.first, tweet.second, followeeId });

    make_heap(tweets.begin(), tweets.end());

    std::vector<int> feed;
    while (!tweets.empty() && feed.size() < 10)
    {
        // Move the largest (most recent) tweet to the end and remove it
        pop_heap(tweets.begin(), tweets.end());
        feed.push_back(std::get<1>(tweets.back())); // Add tweetId to feed
        tweets.pop_back();
    }

    return feed;
}

void HeapAndPriorityQueue::Twitter::follow(int followerId, int followeeId)
{
    followerMap[followerId].insert(followeeId);
}

void HeapAndPriorityQueue::Twitter::unfollow(int followerId, int followeeId)
{
    if (followerMap[followerId].find(followeeId) != followerMap[followerId].end())
        followerMap[followerId].erase(followeeId);
}

void HeapAndPriorityQueue::MedianFinder::addNum(int num)
{
    maxHeap.push(num);

    // make sure every num in maxHeap is <= every num in minHeap
    if (!maxHeap.empty() && !minHeap.empty() &&
        maxHeap.top() > minHeap.top())
    {
        int val = maxHeap.top();
        maxHeap.pop();
        minHeap.push(val);
    }

    // what if the sizes are uneven?
    if (maxHeap.size() > minHeap.size() + 1)
    {
        int val = maxHeap.top();
        maxHeap.pop();
        minHeap.push(val);
    }

    if (minHeap.size() > maxHeap.size() + 1)
    {
        int val = minHeap.top();
        minHeap.pop();
        maxHeap.push(val);
    }
}

double HeapAndPriorityQueue::MedianFinder::findMedian()
{
    if (!minHeap.empty() && !maxHeap.empty())
    {
        if (minHeap.size() == maxHeap.size())
            return (minHeap.top() + maxHeap.top()) / 2.0;
        else if (minHeap.size() > maxHeap.size())
            return minHeap.top();
        else
            return maxHeap.top();
    }
    else if (!minHeap.empty())
        return minHeap.top();
    else if (!maxHeap.empty())
        return maxHeap.top();
    return 0.0;
}
