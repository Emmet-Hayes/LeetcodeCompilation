#pragma once

#include "Graph.h"
#include "Tester.h"


class GraphTester : public Tester
{
public:
    GraphTester() : Tester { "Graph" } {}
    bool testAllProblems() override;
    std::unique_ptr<Tester> clone() const override { return std::make_unique<GraphTester>(*this); }

private:
    bool testNumberOfIslands(std::vector<std::vector<char>> grid, int expected);
    bool testNumberOfIslandsDFS(std::vector<std::vector<char>> grid, int expected);
    bool testNumberOfIslandsBFS(std::vector<std::vector<char>> grid, int expected);
    bool testCloneGraph(GraphNode* node, GraphNode* expected);
    bool testMaxAreaOfIsland(std::vector<std::vector<int>> grid, int expected);
    bool testPacificAtlanticWaterFlow(std::vector<std::vector<int>> heights, std::vector<std::pair<int, int>> expected);
    bool testSurroundedRegions(std::vector<std::vector<char>> board, std::vector<std::vector<char>> expected);
    bool testRottingOranges(std::vector<std::vector<int>> grid, int expected);
    bool testCanFinishCourses(int numCourses, std::vector<std::vector<int>> prerequisites, bool expected);
    bool testFindCourseOrder(int numCourses, std::vector<std::vector<int>> prerequisites, std::vector<int> expected);
    bool testFindRedundantEdge(std::vector<std::vector<int>> edges, std::vector<int> expected);
    bool testWordLadderLength(std::string beginWord, std::string endWord, std::vector<std::string> wordList, int expected);
    bool testMinCostToConnectAllPoints(std::vector<std::pair<int, int>> points, int expected);
    bool testMinNetworkDelayTime(std::vector<std::vector<int>> times, int n, int k, int expected);
    bool testFindCheapestFlightsWithinKStops(std::vector<std::vector<int>> flights, int src, int dest, int k, int n, int expected);
    bool testSwimInRisingWater(std::vector<std::vector<int>> grid, int expected);
    bool testFindItinerary(std::vector<std::vector<std::string>> tickets, std::vector<std::string> expected);

    // Evaluate Division
    // Snakes and Ladders
    // Minimum Genetic Mutation
    // Keys and Rooms
    // Reorder Routes to Make All Paths Lead to City Zero
    // Nearest Exit from Entrance in Maze

    Graph g;
};