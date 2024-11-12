#pragma once

#include "Solution.h"
#include "GraphNode.h"

#include <set>
#include <unordered_map>
#include <unordered_set>
#include <vector>


class Graph : public Solution
{
public:
    Graph() : Solution("Graph", "Common challenge problems involving graphs and graph algorithms.") {}
    std::unique_ptr<Solution> clone() const override { return std::make_unique<Graph>(*this); }
    
    int numberOfIslands(std::vector<std::vector<char>>& grid);
    int numberOfIslandsDFS(std::vector<std::vector<char>>& grid);
    int numberOfIslandsBFS(std::vector<std::vector<char>>& grid);
    GraphNode* cloneGraph(GraphNode* node);
    int maxAreaOfIsland(std::vector<std::vector<int>>& grid);
    std::vector<std::pair<int, int>> pacificAtlanticWaterFlow(const std::vector<std::vector<int>>& heights);
    void surroundedRegions(std::vector<std::vector<char>>& board);
    int rottingOranges(std::vector<std::vector<int>>& grid);
    bool canFinishCourses(int numCourses, const std::vector<std::vector<int>>& prerequisites);
    std::vector<int> findCourseOrder(int numCourses, const std::vector<std::vector<int>>& prerequisites);
    std::vector<int> findRedundantEdge(const std::vector<std::vector<int>>& edges);
    int wordLadderLength(const std::string& beginWord, const std::string& endWord, const std::vector<std::string>& wordList);
    int minCostToConnectAllPoints(const std::vector<std::pair<int, int>>& points);
    int minNetworkDelayTime(const std::vector<std::vector<int>>& times, int n, int k);
    int findCheapestFlightsWithinKStops(const std::vector<std::vector<int>>& flights, int src, int dest, int k, int n);
    int swimInRisingWater(const std::vector<std::vector<int>>& grid);
    std::vector<std::string> findItinerary(const std::vector<std::vector<std::string>>& tickets);

    // Evaluate Division
    // Snakes and Ladders
    // Minimum Genetic Mutation
    // Keys and Rooms
    // Reorder Routes to Make All Paths Lead to City Zero
    // Nearest Exit from Entrance in Maze


private:
    void dfsRecursiveIslands(std::vector<std::vector<char>>& grid, int i, int j);
    void dfsIterativeIslands(std::vector<std::vector<char>>& grid, int i, int j);
    void bfsIslands(std::vector<std::vector<char>>& grid, int i, int j);
    GraphNode* cloneGraphRecursive(GraphNode* node, std::unordered_map<GraphNode*, GraphNode*>& cloneMap);
    void dfsAreaIslands(std::vector<std::vector<int>>& grid, int i, int j, int& area);
    void dfsWaterFlow(const std::vector<std::vector<int>>& heights, int i, int j, std::set<std::pair<int, int>>& visited, int height);
    void dfsRegions(std::vector<std::vector<char>>& board, int i, int j);
    int multibfsOranges(std::vector<std::vector<int>>& grid, std::vector<std::pair<int, int>> startingpoints);
    bool dfsFinishCourses(std::unordered_map<int, std::vector<int>>& prereqMap, std::unordered_set<int>& visited, int course);
    bool dfsCourseOrder(std::unordered_map<int, std::vector<int>>& prereqMap, std::unordered_set<int>& visited,
             std::unordered_set<int>& cycle, std::vector<int>& path, int course, int numCourses);
    bool unionn(int n1, int n2, std::vector<int>& parents, std::vector<int>& ranks);
    int find(int n, std::vector<int>& parents);
    void dfsItinerary(const std::string& src, std::unordered_map<std::string, std::multiset<std::string>>& adjMap, std::vector<std::string>& itinerary);

    struct pair_hash
    {
        template <class T1, class T2>
        size_t operator() (const std::pair<T1, T2>& pair) const
        {
            auto hash1 = std::hash<T1>{}(pair.first);
            auto hash2 = std::hash<T2>{}(pair.second);
            // Combine the two hash values. Might try a different method to combine them later.
            return hash1 ^ hash2;
        }
    };
};