#include "GraphTester.h"


bool GraphTester::testAllProblems()
{
    addTestCase(testNumberOfIslands({ { '1', '1', '1', '1', '0' },
                                      { '1', '1', '0', '1', '0' },
                                      { '1', '1', '0', '0', '0' },
                                      { '0', '0', '0', '0', '0' } }, 1));
    addTestCase(testNumberOfIslands({ { '1', '1', '0', '0', '0' },
                                      { '1', '1', '0', '0', '0' },
                                      { '0', '0', '1', '0', '0' },
                                      { '0', '0', '0', '1', '1' } }, 3));

    addTestCase(testNumberOfIslandsDFS({ { '1', '1', '1', '1', '0' },
                                         { '1', '1', '0', '1', '0' },
                                         { '1', '1', '0', '0', '0' },
                                         { '0', '0', '0', '0', '0' } }, 1));
    addTestCase(testNumberOfIslandsDFS({ { '1', '1', '0', '0', '0' },
                                         { '1', '1', '0', '0', '0' },
                                         { '0', '0', '1', '0', '0' },
                                         { '0', '0', '0', '1', '1' } }, 3));

    addTestCase(testNumberOfIslandsBFS({ { '1', '1', '1', '1', '0' },
                                         { '1', '1', '0', '1', '0' },
                                         { '1', '1', '0', '0', '0' },
                                         { '0', '0', '0', '0', '0' } }, 1));
    addTestCase(testNumberOfIslandsBFS({ { '1', '1', '0', '0', '0' },
                                         { '1', '1', '0', '0', '0' },
                                         { '0', '0', '1', '0', '0' },
                                         { '0', '0', '0', '1', '1' } }, 3));

    GraphNode* node1 = new GraphNode(1);
    GraphNode* node2 = new GraphNode(2);
    GraphNode* node3 = new GraphNode(3);
    GraphNode* node4 = new GraphNode(4);
    node1->neighbors.push_back(node2);
    node1->neighbors.push_back(node4);
    node2->neighbors.push_back(node1);
    node2->neighbors.push_back(node3);
    node3->neighbors.push_back(node2);
    node3->neighbors.push_back(node4);
    node4->neighbors.push_back(node1);
    node4->neighbors.push_back(node3);
    addTestCase(testCloneGraph(node1, node1));

    addTestCase(testMaxAreaOfIsland({ { 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0 }, 
                                      { 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0 },
                                      { 0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0 },
                                      { 0, 1, 0, 0, 1, 1, 0, 1, 0, 1, 0, 0, 0 },
                                      { 0, 1, 0, 0, 1, 1, 0, 1, 1, 1, 0, 0, 0 },
                                      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0 },
                                      { 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0 },
                                      { 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0 }
                                    }, 6));
    addTestCase(testMaxAreaOfIsland({ { 0, 0, 0, 0, 0, 0, 0, 0 } }, 0));

    addTestCase(testPacificAtlanticWaterFlow({ { 1, 2, 2, 3, 5 }, 
                                               { 3, 2, 3, 4, 4 },
                                               { 2, 4, 5, 3, 1 },
                                               { 6, 7, 1, 4, 5 },
                                               { 5, 1, 1, 2, 4 }
        }, { { 0, 4 }, { 1, 3 }, { 1, 4 }, { 2, 2 }, { 3, 0 }, { 3, 1 }, { 4, 0 } }));
    addTestCase(testPacificAtlanticWaterFlow({ { 1 } }, { { 0, 0 } }));
    addTestCase(testSurroundedRegions({ { 'X', 'X', 'X', 'X' },
                                        { 'X', 'O', 'O', 'X' },
                                        { 'X', 'X', 'O', 'X' },
                                        { 'X', 'O', 'X', 'X' } }, 
                                      { { 'X', 'X', 'X', 'X' },
                                        { 'X', 'X', 'X', 'X' },
                                        { 'X', 'X', 'X', 'X' },
                                        { 'X', 'O', 'X', 'X' } }));
    addTestCase(testSurroundedRegions({ { 'X' } }, { { 'X' } }));

    addTestCase(testRottingOranges({ { 2, 1, 1 },
                                     { 1, 1, 0 },
                                     { 0, 1, 1 } }, 4));
    addTestCase(testRottingOranges({ { 2, 1, 1 },
                                     { 0, 1, 1 },
                                     { 1, 0, 1 } }, -1));
    addTestCase(testRottingOranges({ { 0, 2 } }, 0));

    addTestCase(testCanFinishCourses(2, { { 1, 0 } }, true));
    addTestCase(testCanFinishCourses(2, { { 1, 0 }, { 0, 1 } }, false));

    addTestCase(testFindCourseOrder(2, { { 1, 0 } }, { 0, 1 }));
    addTestCase(testFindCourseOrder(4, { { 1, 0 }, { 2, 0 }, { 3, 1 }, { 3, 2 } }, { 0, 1, 2, 3 }));
    addTestCase(testFindCourseOrder(1, { { } }, { 0 }));

    addTestCase(testFindRedundantEdge({ { 1, 2 }, { 1, 3 }, { 2, 3 } }, { 2, 3 }));
    addTestCase(testFindRedundantEdge({ { 1, 2 }, { 2, 3 }, { 3, 4 }, { 1, 4 }, { 1, 5 } }, { 1, 4 }));
    
    addTestCase(testWordLadderLength("hit", "cog", { "hot", "dot", "dog", "lot", "log", "cog" }, 5));
    addTestCase(testWordLadderLength("hit", "cog", { "hot", "dot", "dog", "lot", "log" }, 0));

    addTestCase(testMinCostToConnectAllPoints({ { 0, 0 }, { 2, 2 }, { 3, 10 }, { 5, 2 }, { 7, 0 } }, 20));
    addTestCase(testMinCostToConnectAllPoints({ { 3, 12 }, { -2, 5 }, { -4, 1 } }, 18));

    addTestCase(testMinNetworkDelayTime({ { 2, 1, 1 }, { 2, 3, 1 }, { 3, 4, 1 } }, 4, 2, 2));
    addTestCase(testMinNetworkDelayTime({ { 1, 2, 1 } }, 2, 1, 1));
    addTestCase(testMinNetworkDelayTime({ { 1, 2, 1 } }, 2, 2, -1));

    addTestCase(testFindCheapestFlightsWithinKStops({ { 0, 1, 100 }, { 1, 2, 100 }, { 2, 0, 100 }, { 1, 3, 600 }, { 2, 3, 200 } }, 0, 3, 1, 4, 700));
    addTestCase(testFindCheapestFlightsWithinKStops({ { 0, 1, 100 }, { 1, 2, 100 }, { 0, 2, 500 } }, 0, 2, 1, 3, 200));

    addTestCase(testSwimInRisingWater({ { 0, 2 }, { 1, 3 } }, 3));
    addTestCase(testSwimInRisingWater({ { 0,   1,  2,  3,  4 },
                                        { 24, 23, 22, 21,  5 },
                                        { 12, 13, 14, 15, 16 },
                                        { 11, 17, 18, 19, 20 },
                                        { 10,  9,  8,  7,  6 } }, 16));

    addTestCase(testFindItinerary({ { "MUC", "LHR" }, { "JFK", "MUC" }, { "SFO", "SJC"}, { "LHR", "SFO" } }, 
                                  { "JFK", "MUC", "LHR", "SFO", "SJC" }));
    addTestCase(testFindItinerary({ { "JFK", "SFO" }, { "JFK", "ATL"}, { "SFO", "ATL" }, { "ATL", "JFK" }, { "ATL", "SFO" }},
                                  { "JFK", "ATL", "JFK", "SFO", "ATL", "SFO" }));

    return runAllTests();
}

bool GraphTester::testNumberOfIslands(std::vector<std::vector<char>> grid, int expected)
{
    if (getVerbose())
    {
        ss << "\nNumber of Islands Test Run On Input Grid:\n\n";
        for (unsigned i = 0; i < grid.size(); ++i)
        {
            for (char val : grid[i])
                ss << val << " ";
            ss << "\n";
        }
    }
    int actual = g.numberOfIslands(grid);
    if (getVerbose())
        ss << "\nResult: " << actual << " | Expected: " << expected << "\n";
    return actual == expected;
}

bool GraphTester::testNumberOfIslandsDFS(std::vector<std::vector<char>> grid, int expected)
{
    if (getVerbose())
    {
        ss << "\nNumber of Islands (DFS) Test Run On Input Grid:\n\n";
        for (unsigned i = 0; i < grid.size(); ++i)
        {
            for (char val : grid[i])
                ss << val << " ";
            ss << "\n";
        }
    }
    int actual = g.numberOfIslandsDFS(grid);
    if (getVerbose())
        ss << "\nResult: " << actual << " | Expected: " << expected << "\n";
    return actual == expected;
}

bool GraphTester::testNumberOfIslandsBFS(std::vector<std::vector<char>> grid, int expected)
{
    if (getVerbose())
    {
        ss << "\nNumber of Islands Test Run On Input Grid:\n\n";
        for (unsigned i = 0; i < grid.size(); ++i)
        {
            for (char val : grid[i])
                ss << val << " ";
            ss << "\n";
        }
    }
    int actual = g.numberOfIslandsBFS(grid);
    if (getVerbose())
        ss << "\nResult: " << actual << " | Expected: " << expected << "\n";
    return actual == expected;
}

bool GraphTester::testCloneGraph(GraphNode* node, GraphNode* expected)
{
    GraphNode* actual = g.cloneGraph(node);
    if (actual->neighbors.size() != expected->neighbors.size())
        return false;
    return actual->val == expected->val;
}

bool GraphTester::testMaxAreaOfIsland(std::vector<std::vector<int>> grid, int expected)
{
    if (getVerbose())
    {
        ss << "\nMax Area of Islands Test Run On Input Grid:\n\n";
        for (unsigned i = 0; i < grid.size(); ++i)
        {
            for (int val : grid[i])
                ss << val << " ";
            ss << "\n";
        }
    }
    int actual = g.maxAreaOfIsland(grid);
    if (getVerbose())
        ss << "\nResult: " << actual << " | Expected: " << expected << "\n";
    return actual == expected;
}

bool GraphTester::testPacificAtlanticWaterFlow(std::vector<std::vector<int>> heights, std::vector<std::pair<int, int>> expected)
{
    std::vector<std::pair<int, int>> actual = g.pacificAtlanticWaterFlow(heights);
    if (getVerbose())
    {
        ss << "\nPacific Atlantic Water Flow Test Run On Input Grid:\n\n";
        for (unsigned i = 0; i < heights.size(); ++i)
        {
            for (int val : heights[i])
                ss << val << " ";
            ss << "\n";
        }
        ss << "\nResult:   [ ";
        for (std::pair<int, int> cell : actual)
            ss << "{ " << cell.first << ", " << cell.second << " } ";
        ss << "]\nExpected: [ ";
        for (std::pair<int, int> cell : expected)
            ss << "{ " << cell.first << ", " << cell.second << " } ";
        ss << "]\n";
    }
    if (actual.size() != expected.size())
        return false;
    for (unsigned i = 0; i < expected.size(); ++i)
        if (actual[i].first != expected[i].first || actual[i].second != expected[i].second)
            return false;
    return true;
}

bool GraphTester::testSurroundedRegions(std::vector<std::vector<char>> board, std::vector<std::vector<char>> expected)
{
    if (getVerbose())
    {
        ss << "\nSurrounded Regions Test Run On Input Grid:\n\n";
        for (unsigned i = 0; i < board.size(); ++i)
        {
            for (char val : board[i])
                ss << val << " ";
            ss << "\n";
        }
    }
    g.surroundedRegions(board);
    if (getVerbose())
    {
        ss << "\nResult:\n\n";
        for (unsigned i = 0; i < board.size(); ++i)
        {
            for (char val : board[i])
                ss << val << " ";
            ss << "\n";
        }
        ss << "\nExpected:\n\n";
        for (unsigned i = 0; i < expected.size(); ++i)
        {
            for (char val : expected[i])
                ss << val << " ";
            ss << "\n";
        }
    }
    if (board.size() != expected.size())
        return false;
    for (unsigned i = 0; i < expected.size(); ++i)
    {
        if (board[i].size() != expected[i].size())
            return false;
        for (unsigned j = 0; j < expected[i].size(); ++j)
            if (board[i][j] != expected[i][j])
                return false;
    }
    return true;
}

bool GraphTester::testRottingOranges(std::vector<std::vector<int>> grid, int expected)
{
    if (getVerbose())
    {
        ss << "\nRotting Oranges Test Run On Input Grid:\n\n";
        for (unsigned i = 0; i < grid.size(); ++i)
        {
            for (int val : grid[i])
                ss << val << " ";
            ss << "\n";
        }
    }
    int actual = g.rottingOranges(grid);
    if (getVerbose())
        ss << "\nResult: " << actual << " | Expected: " << expected << "\n";
    return actual == expected;
}

bool GraphTester::testCanFinishCourses(int numCourses, std::vector<std::vector<int>> prerequisites, bool expected)
{
    bool actual = g.canFinishCourses(numCourses, prerequisites);
    if (getVerbose())
    {
        ss << "\nCan Finish Courses Test Run On Input Prerequisites:\n";
        for (std::vector<int> prereq : prerequisites)
            ss << "Course " << prereq[0] << " requires course " << prereq[1] << "\n";
        ss << "\nResult: " << actual << " | Expected: " << expected << "\n";
    }
    return actual == expected;
}

bool GraphTester::testFindCourseOrder(int numCourses, std::vector<std::vector<int>> prerequisites, std::vector<int> expected)
{
    std::vector<int> actual = g.findCourseOrder(numCourses, prerequisites);
    if (getVerbose())
    {
        ss << "\nFind Course Order Test Run On Input Prerequisites:\n\n";
        if (prerequisites.size() >= 1 && !prerequisites[0].empty())
            for (std::vector<int> prereq : prerequisites)
                ss << "Course " << prereq[0] << " requires course " << prereq[1] << "\n";
        ss << "\nResult: [ ";
        for (int val : actual)
            ss << val << " ";
        ss << "] | Expected: [ ";
        for (int val : expected)
            ss << val << " ";
        ss << "]\n";
    }
    if (actual.size() != expected.size())
        return false;
    for (unsigned i = 0; i < expected.size(); ++i)
        if (actual[i] != expected[i])
            return false;
    return true;
}

bool GraphTester::testFindRedundantEdge(std::vector<std::vector<int>> edges, std::vector<int> expected)
{
    std::vector<int> actual = g.findRedundantEdge(edges);
    if (getVerbose())
    {
        ss << "\nFind Redundant Edge Test Run On Input Edges:\n\n";
        for (std::vector<int> edge : edges)
            ss << edge[0] << " connects to " << edge[1] << "\n";
        ss << "\nResult: [ ";
        for (int val : actual)
            ss << val << " ";
        ss << "] | Expected: [ ";
        for (int val : expected)
            ss << val << " ";
        ss << "]\n";
    }
    if (actual.size() != expected.size())
        return false;
    for (unsigned i = 0; i < expected.size(); ++i)
        if (actual[i] != expected[i])
            return false;
    return true;
}

bool GraphTester::testWordLadderLength(std::string beginWord, std::string endWord, std::vector<std::string> wordList, int expected)
{
    int actual = g.wordLadderLength(beginWord, endWord, wordList);
    if (getVerbose())
    {
        ss << "\nWord Ladder Length Test Run On Beginning Word: " << beginWord << " and End Word: " << endWord
                  << "\nWord Ladder: [ ";
        for (std::string word : wordList)
            ss << word << " ";
        ss << "]\nResult: " << actual << " | Expected: " << expected << "\n";
    }
    return actual == expected;
}

bool GraphTester::testMinCostToConnectAllPoints(std::vector<std::pair<int, int>> points, int expected)
{
    int actual = g.minCostToConnectAllPoints(points);
    if (getVerbose())
    {
        ss << "\nMinimum Cost to Connect All Points Test Run On Input Point Vector: [ ";
        for (std::pair<int, int> point : points)
            ss << "{ " << point.first << ", " << point.second << " } ";
        ss << "]\nResult: " << actual << " | Expected: " << expected << "\n";
    }
    return actual == expected;
}

bool GraphTester::testMinNetworkDelayTime(std::vector<std::vector<int>> times, int n, int k, int expected)
{
    int actual = g.minNetworkDelayTime(times, n, k);
    if (getVerbose())
    {
        ss << "\nMinimum Network Delay Time Test Run On Input Times Vector: [ ";
        for (std::vector<int> time : times)
            ss << "{ " << time[0] << ", " << time[1] << ", " << time[2] << "} ";
        ss << "]\nn: " << n << ", k: " << k << "\nResult: " << actual << " | Expected : " << expected << "\n";
    }
    return actual == expected;
}

bool GraphTester::testFindCheapestFlightsWithinKStops(std::vector<std::vector<int>> flights, int src, int dest, int k, int n, int expected)
{
    int actual = g.findCheapestFlightsWithinKStops(flights, src, dest, k, n);
    if (getVerbose())
    {
        ss << "\nMinimum Network Delay Time Test Run On Input Flights Vector: [ ";
        for (std::vector<int> flight : flights)
            ss << "{ " << flight[0] << ", " << flight[1] << ", " << flight[2] << "} ";
        ss << "]\nSource: " << src << ", Destination: " << dest << ", n: " << n << ", k: " << k << "\nResult: " << actual << " | Expected : " << expected << "\n";
    }
    return actual == expected;
}

bool GraphTester::testSwimInRisingWater(std::vector<std::vector<int>> grid, int expected)
{
    if (getVerbose())
    {
        ss << "\nSwim in Rising Water Test Run On Input Grid:\n\n";
        for (unsigned i = 0; i < grid.size(); ++i)
        {
            for (int val : grid[i])
                ss << val << " ";
            ss << "\n";
        }
    }
    int actual = g.swimInRisingWater(grid);
    if (getVerbose())
        ss << "\nResult: " << actual << " | Expected: " << expected << "\n";
    return actual == expected;
}

bool GraphTester::testFindItinerary(std::vector<std::vector<std::string>> tickets, std::vector<std::string> expected)
{
    std::vector<std::string> actual = g.findItinerary(tickets);
    if (getVerbose())
    {
        ss << "\nFind Itinerary Test Run on Input Ticket Vector:\n\n";
        for (unsigned i = 0; i < tickets.size(); ++i)
        {
            for (unsigned j = 0; j < tickets[i].size(); ++j)
                ss << tickets[i][j] << " ";
            ss << "\n";
        }
        ss << "\nResult:   ";
        for (std::string stop : actual)
            ss << stop << " ";
        ss << "\nExpected: ";
        for (std::string stop : expected)
            ss << stop << " ";
        ss << "\n";
    }
    if (actual.size() != expected.size())
        return false;
    for (unsigned i = 0; i < expected.size(); ++i)
    {
        if (actual[i].size() != expected[i].size())
            return false;
        for (unsigned j = 0; j < expected[i].size(); ++j)
            if (actual[i][j] != expected[i][j])
                return false;
    }
    return true;
}
