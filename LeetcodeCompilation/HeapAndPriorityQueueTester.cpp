#include "HeapAndPriorityQueueTester.h"


bool HeapAndPriorityQueueTester::testAllProblems()
{
    addTestCase(testLastStoneWeight({ 2, 7, 4, 1, 8, 1 }, 1));
    addTestCase(testLastStoneWeight({ 1 }, 1));

    addTestCase(testKClosestPointsToOrigin({ { 1, 3 }, { -2, 2 } }, 1, { { -2, 2 } }));
    addTestCase(testKClosestPointsToOrigin({ { 3, 3 }, { 5, -1 }, { -2, 4 } }, 2, { { 3, 3 }, { -2, 4 } }));

    addTestCase(testFindKthLargestSelect({ 3, 2, 1, 6, 5, 4 }, 2, 5));
    addTestCase(testFindKthLargestSelect({ 3, 2, 3, 1, 2, 4, 5, 5, 6 }, 4, 4));

    addTestCase(testFindKthLargestHeap({ 3, 2, 1, 6, 5, 4 }, 2, 5));
    addTestCase(testFindKthLargestHeap({ 3, 2, 3, 1, 2, 4, 5, 5, 6 }, 4, 4));

    addTestCase(testTaskScheduler({ 'A', 'A', 'A', 'B', 'B', 'B' }, 2, 8));
    addTestCase(testTaskScheduler({ 'A', 'C', 'A', 'B', 'D', 'B' }, 1, 6));
    addTestCase(testTaskScheduler({ 'A', 'A', 'A', 'B', 'B', 'B' }, 3, 10));

    addTestCase(testKthLargestStream({ 4, 5, 8, 2 }, 3));

    addTestCase(testTwitterDesign());

    addTestCase(testMedianFinder());

    return runAllTests();
}

bool HeapAndPriorityQueueTester::testLastStoneWeight(std::vector<int> stones, int expected)
{
    int actual = hpq.lastStoneWeight(stones);
    if (getVerbose())
    {
        ss << "\nLast Stone Weight Test Run On Input Vector:\n[ ";
        for (int val : stones)
            ss << val << " ";
        ss << "]\nResult: " << actual << " | Expected: " << expected << "\n";
    }
    return actual == expected;
}

bool HeapAndPriorityQueueTester::testKClosestPointsToOrigin(std::vector<std::pair<int, int>> points, int k, std::vector<std::pair<int, int>> expected)
{
    std::vector<std::pair<int, int>> actual = hpq.kClosestPointsToOrigin(points, k);
    if (getVerbose())
    {
        ss << "\nK Closest Points to Origin Test Run on Input Pair Vector:\n[ ";
        for (std::pair<int, int> point : points)
            ss << "{ " << point.first << ", " << point.second << " } ";
        ss << "]\nk: " << k << "\nResult: [ ";
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

bool HeapAndPriorityQueueTester::testFindKthLargestSelect(std::vector<int> nums, int k, int expected)
{
    int actual = hpq.findKthLargestSelect(nums, k);
    if (getVerbose())
    {
        ss << "\nFind Kth Largest (Select) Test Run On Input Vector:\n[ ";
        for (int val : nums)
            ss << val << " ";
        ss << "]\nk: " << k << "\nResult: " << actual << " | Expected: " << expected << "\n";
    }
    return actual == expected;
}

bool HeapAndPriorityQueueTester::testFindKthLargestHeap(std::vector<int> nums, int k, int expected)
{
    int actual = hpq.findKthLargestHeap(nums, k);
    if (getVerbose())
    {
        ss << "\nFind Kth Largest (Select) Test Run On Input Vector:\n[ ";
        for (int val : nums)
            ss << val << " ";
        ss << "]\nk: " << k << "\nResult: " << actual << " | Expected: " << expected << "\n";
    }
    return actual == expected;
}

bool HeapAndPriorityQueueTester::testTaskScheduler(std::vector<char> tasks, int n, int expected)
{
    int actual = hpq.taskScheduler(tasks, n);
    if (getVerbose())
    {
        ss << "\nFind Kth Largest (Select) Test Run On Input Vector:\n[ ";
        for (int val : tasks)
            ss << val << " ";
        ss << "]\nn: " << n << "\nResult: " << actual << " | Expected: " << expected << "\n";
    }
    return actual == expected;
}

bool HeapAndPriorityQueueTester::testKthLargestStream(std::vector<int> nums, int k)
{
    HeapAndPriorityQueue::KthLargest klg (k, nums);
    if (4 != klg.add(3)) return false;
    if (5 != klg.add(5)) return false;
    if (5 != klg.add(10)) return false;
    if (8 != klg.add(9)) return false;
    if (8 != klg.add(4)) return false;
    return true;
}

bool HeapAndPriorityQueueTester::testTwitterDesign()
{
    HeapAndPriorityQueue::Twitter tw;
    tw.postTweet(1, 5);
    std::vector<int> feed = tw.getNewsFeed(1);
    if (feed.size() != 1) return false;
    if (feed[0] != 5) return false;
    tw.follow(1, 2);
    tw.postTweet(2, 6);
    feed = tw.getNewsFeed(1);
    if (feed.size() != 2) return false;
    if (feed[0] != 6 && feed[1] != 5) return false;
    tw.unfollow(1, 2);
    feed = tw.getNewsFeed(1);
    if (feed.size() != 1) return false;
    if (feed[0] != 5) return false;
    return true;
}


bool HeapAndPriorityQueueTester::testMedianFinder()
{
    HeapAndPriorityQueue::MedianFinder mf;
    mf.addNum(1);
    mf.addNum(2);
    double med = mf.findMedian();
    if (fabs(med - 1.5) > 1e-9) return false;
    mf.addNum(3);
    med = mf.findMedian();
    if (fabs(med - 2.0) > 1e-9) return false;
    return true;
}
