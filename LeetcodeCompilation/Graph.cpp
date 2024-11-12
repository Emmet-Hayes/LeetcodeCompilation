#include "Graph.h"

#include <algorithm>
#include <climits>
#include <stack>
#include <queue>


/**
*
* Complexity:
* Time: O(m*n)
* Space: O(1)
*/
int Graph::numberOfIslands(std::vector<std::vector<char>>& grid)
{
    if (grid.empty()) return 0;

    int numIslands = 0;
    for (unsigned r = 0; r < grid.size(); ++r)
    {
        for (unsigned c = 0; c < grid[0].size(); ++c)
        {
            if (grid[r][c] == '1')
            {
                ++numIslands;
                dfsRecursiveIslands(grid, r, c);
            }
        }
    }

    return numIslands;
}

void Graph::dfsRecursiveIslands(std::vector<std::vector<char>>& grid, int i, int j)
{
    // if current cell is already explored or out of bounds, end search
    if (i < 0 || i >= static_cast<int>(grid.size())    || 
        j < 0 || j >= static_cast<int>(grid[0].size()) || 
        grid[i][j] != '1')
        return;

    grid[i][j] = '#'; // labelled as explored
    dfsRecursiveIslands(grid, i + 1, j);
    dfsRecursiveIslands(grid, i - 1, j);
    dfsRecursiveIslands(grid, i, j + 1);
    dfsRecursiveIslands(grid, i, j - 1);
}


/**
*
* Complexity:
* Time: O(m*n)
* Space: O(1)
*/
int Graph::numberOfIslandsDFS(std::vector<std::vector<char>>& grid)
{
    if (grid.empty()) return 0;

    int numIslands = 0;
    for (unsigned r = 0; r < grid.size(); ++r)
    {
        for (unsigned c = 0; c < grid[0].size(); ++c)
        {
            if (grid[r][c] == '1')
            {
                ++numIslands;
                dfsIterativeIslands(grid, r, c);
            }
        }
    }

    return numIslands;
}

void Graph::dfsIterativeIslands(std::vector<std::vector<char>>& grid, int i, int j)
{
    std::stack<std::pair<int, int>> s;
    s.push({ i, j });

    while (!s.empty())
    {
        std::pair<int, int> v = s.top();
        s.pop();

        // if cell not discovered and not out of bounds
        if (v.first  >= 0 && v.first  < static_cast<int>(grid.size())    &&
            v.second >= 0 && v.second < static_cast<int>(grid[0].size()) &&
            grid[v.first][v.second] == '1')
        {
            grid[v.first][v.second] = '#';     // label as discovered
            s.push({ v.first + 1, v.second }); // outgoing edges
            s.push({ v.first - 1, v.second });
            s.push({ v.first, v.second + 1 });
            s.push({ v.first, v.second - 1 });
        }
    }
}


/**
*
* Complexity:
* Time: O(m*n)
* Space: O(1)
*/
int Graph::numberOfIslandsBFS(std::vector<std::vector<char>>& grid)
{
    if (grid.empty()) return 0;

    int numIslands = 0;
    for (unsigned r = 0; r < grid.size(); ++r)
    {
        for (unsigned c = 0; c < grid[0].size(); ++c)
        {
            if (grid[r][c] == '1')
            {
                ++numIslands;
                bfsIslands(grid, r, c);
            }
        }
    }

    return numIslands;
}

void Graph::bfsIslands(std::vector<std::vector<char>>& grid, int i, int j)
{
    std::queue<std::pair<int, int>> q;
    q.push({ i, j });

    grid[i][j] = '0';

    while (!q.empty())
    {
        std::pair<int, int> v = q.front();
        q.pop();
        std::vector<std::pair<int, int>> directions = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} }; // spread cardinally
        for (auto& dir : directions)
        {
            int dx = v.first + dir.first, dy = v.second + dir.second;
            if (dx >= 0 && dx < static_cast<int>(grid.size())    && 
                dy >= 0 && dy < static_cast<int>(grid[0].size()) && 
                grid[dx][dy] == '1')
            {
                q.push({ dx, dy });
                grid[dx][dy] = '0';
            }
        }
    }
}


/**
*
* Complexity:
* Time: O(v + e)
* Space: O(v + e)
*/
GraphNode* Graph::cloneGraph(GraphNode* node)
{
    std::unordered_map<GraphNode*, GraphNode*> cloneMap;
    return cloneGraphRecursive(node, cloneMap);
}


GraphNode* Graph::cloneGraphRecursive(GraphNode* node, std::unordered_map<GraphNode*, GraphNode*>& cloneMap)
{
    if (!node) return nullptr;

    // don't try to clone a node that is already created, return it as a recursive neighbor.
    if (cloneMap.find(node) != cloneMap.end())
        return cloneMap[node];

    // for unseen nodes, clone the nodes value to a new node and add to our hashmap
    GraphNode* clone = new GraphNode(node->val);
    cloneMap[node] = clone;

    // clone the neighbors of this node recursively
    for (GraphNode* neighbor : node->neighbors)
        clone->neighbors.push_back(cloneGraphRecursive(neighbor, cloneMap));

    return clone;
}


/**
*
* Complexity:
* Time: O(m*n)
* Space: O(1)
*/
int Graph::maxAreaOfIsland(std::vector<std::vector<int>>& grid)
{
    int maxAreaIsland = 0;
    for (unsigned i = 0; i < grid.size(); ++i)
    {
        for (unsigned j = 0; j < grid[0].size(); ++j)
        {
            int currentArea = 0;
            dfsAreaIslands(grid, i, j, currentArea);
            maxAreaIsland = std::max(maxAreaIsland, currentArea);
        }
    }

    return maxAreaIsland;
}

void Graph::dfsAreaIslands(std::vector<std::vector<int>>& grid, int i, int j, int& area)
{
    // if cell is out of bounds or already visited end search
    if (i < 0 || i >= static_cast<int>(grid.size()) || 
        j < 0 || j >= static_cast<int>(grid[0].size()) || grid[i][j] != 1)
        return;

    grid[i][j] = 2; // mark as visited
    area++;

    // explore other directions
    dfsAreaIslands(grid, i + 1, j, area);
    dfsAreaIslands(grid, i - 1, j, area);
    dfsAreaIslands(grid, i, j + 1, area);
    dfsAreaIslands(grid, i, j - 1, area);
}


/**
*
* Complexity:
* Time: O(mn log (mn))
* Space: O(mn)
*/
std::vector<std::pair<int, int>> Graph::pacificAtlanticWaterFlow(const std::vector<std::vector<int>>& heights)
{
    std::set<std::pair<int, int>> pac, atl;

    // checking target columns (left column is pacific, right column is atlantic)
    for (unsigned i = 0; i < heights[0].size(); ++i)
    {
        dfsWaterFlow(heights, 0, i, pac, heights[0][i]);
        dfsWaterFlow(heights, static_cast<int>(heights.size()) - 1, i, atl, heights[heights.size() - 1][i]);
    }

    // checking target rows (top row is pacific, bottom row is atlantic)
    for (unsigned i = 0; i < heights.size(); ++i)
    {
        dfsWaterFlow(heights, i, 0, pac, heights[i][0]);
        dfsWaterFlow(heights, i, static_cast<int>(heights[0].size()) - 1, atl, heights[i][heights[0].size() - 1]);
    }

    // grab cells that are present in both sets
    std::vector<std::pair<int, int>> answer;
    for (unsigned i = 0; i < heights.size(); ++i)
        for (unsigned j = 0; j < heights[i].size(); ++j)
            if (pac.find({ i, j }) != pac.end() && atl.find({ i, j }) != atl.end())
                answer.push_back({ i, j });

    return answer;
}

void Graph::dfsWaterFlow(const std::vector<std::vector<int>>& heights, int i, int j, std::set<std::pair<int, int>>& visited, int height)
{
    if (i < 0 || i >= static_cast<int>(heights.size()) || 
        j < 0 || j >= static_cast<int>(heights[0].size()) || 
        visited.find({ i, j }) != visited.end() || heights[i][j] < height)
        return;

    visited.insert({ i, j });
    height = heights[i][j];
    dfsWaterFlow(heights, i + 1, j, visited, height);
    dfsWaterFlow(heights, i - 1, j, visited, height);
    dfsWaterFlow(heights, i, j + 1, visited, height);
    dfsWaterFlow(heights, i, j - 1, visited, height);
}


/**
*
* Complexity:
* Time: O(m*n)
* Space: O(1)
*/
void Graph::surroundedRegions(std::vector<std::vector<char>>& board)
{
    // check borders of matrix rows for O's to start dfs from
    for (unsigned i = 0; i < board.size(); ++i)
    {
        if (board[i][0] == 'O')     dfsRegions(board, i, 0);
        if (board[i][board.size() - 1] == 'O') dfsRegions(board, i, board.size() - 1);
    }

    // now for columns
    for (unsigned j = 0; j < board[0].size(); ++j)
    {
        if (board[0][j] == 'O')     dfsRegions(board, 0, j);
        if (board[board[0].size() - 1][j] == 'O') dfsRegions(board, board[0].size() - 1, j);
    }

    // flip V's to O's and O's to X's (since they would have been visited if they weren't surrounded)
    for (unsigned i = 0; i < board.size(); ++i)
    {
        for (unsigned j = 0; j < board[0].size(); ++j)
        {
            if (board[i][j] == 'O') board[i][j] = 'X';
            if (board[i][j] == 'V') board[i][j] = 'O';
        }
    }
}

void Graph::dfsRegions(std::vector<std::vector<char>>& board, int i, int j)
{
    // for each cell that we visit, check neighbors
    // if a cell is on the edge of the matrix, then its the case that it can't be surrounded.
    if (i < 0 || i >= static_cast<int>(board.size())    || 
        j < 0 || j >= static_cast<int>(board[0].size()) || 
        board[i][j] != 'O')
        return;

    // mark as visited
    board[i][j] = 'V';

    // check all neighbors for O's to traverse next
    dfsRegions(board, i, j + 1);
    dfsRegions(board, i, j - 1);
    dfsRegions(board, i + 1, j);
    dfsRegions(board, i - 1, j);
}


/**
*
* Complexity:
* Time: O(m*n)
* Space: O(m*n)
*/
int Graph::rottingOranges(std::vector<std::vector<int>>& grid)
{
    // find starting points to start bfs from (all start at the same time)
    std::vector<std::pair<int, int>> startingpoints;
    for (unsigned i = 0; i < grid.size(); ++i)
        for (unsigned j = 0; j < grid[0].size(); ++j)
            if (grid[i][j] == 2) // a rotten orange
                startingpoints.push_back({ i, j });

    int time = multibfsOranges(grid, startingpoints);

    // check for any fresh oranges left over from rotting step
    for (unsigned i = 0; i < grid.size(); ++i)
        for (unsigned j = 0; j < grid[0].size(); ++j)
            if (grid[i][j] == 1)
                return -1;

    return time;
}

int Graph::multibfsOranges(std::vector<std::vector<int>>& grid, std::vector<std::pair<int, int>> startingpoints)
{
    std::queue<std::pair<int, int>> q;

    for (std::pair<int, int> start : startingpoints)
        q.push({ start.first, start.second });

    int time = 0;
    std::vector<std::pair<int, int>> directions = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
    while (!q.empty())
    {
        int numRottenOranges = static_cast<int>(q.size());
        for (int i = 0; i < numRottenOranges; ++i)
        {
            std::pair<int, int> v = q.front();
            q.pop();

            // Process each direction
            for (auto& dir : directions)
            {
                int dx = v.first + dir.first, dy = v.second + dir.second;
                if (dx >= 0 && dx < static_cast<int>(grid.size())    && 
                    dy >= 0 && dy < static_cast<int>(grid[0].size()) && 
                    grid[dx][dy] == 1)
                {
                    grid[dx][dy] = 2; // Rot the orange
                    q.push({ dx, dy });
                }
            }
        }
        if (!q.empty()) time++; // Only increment time if we have new rotten oranges
    }

    return time;
}


/**
*
* Complexity:
* Time: O(v + e)
* Space: O(v + e)
*/
bool Graph::canFinishCourses(int numCourses, const std::vector<std::vector<int>>& prerequisites)
{
    std::unordered_map<int, std::vector<int>> prereqMap;
    for (unsigned i = 0; i < prerequisites.size(); ++i)
        prereqMap[prerequisites[i][0]].push_back(prerequisites[i][1]);

    std::unordered_set<int> visited;
    for (int i = 0; i < numCourses; ++i)
        if (!dfsFinishCourses(prereqMap, visited, i))
            return false;

    return true;
}

bool Graph::dfsFinishCourses(std::unordered_map<int, std::vector<int>>& prereqMap, std::unordered_set<int>& visited, int course)
{
    // already visited this course!
    if (visited.find(course) != visited.end())
        return false;

    // course has no prerequisites
    if (prereqMap[course].empty())
        return true;

    // add course to visited set
    visited.insert(course);

    // traverse the edges (prerequisites)
    for (int prereq : prereqMap[course])
        if (!dfsFinishCourses(prereqMap, visited, prereq))
            return false;

    // finished visiting this course
    visited.erase(course);

    // save time if this node gets visited again by making this prereq vector empty, triggering the true condition above
    prereqMap[course].clear();
    return true;
}


/**
*
* Complexity:
* Time: O(v + e)
* Space: O(v + e)
*/
std::vector<int> Graph::findCourseOrder(int numCourses, const std::vector<std::vector<int>>& prerequisites)
{
    if (numCourses == 1 && prerequisites.size() == 1 && prerequisites[0].empty())
        return { 0 };
    std::unordered_map<int, std::vector<int>> prereqMap;
    for (unsigned i = 0; i < prerequisites.size(); ++i)
        prereqMap[prerequisites[i][0]].push_back(prerequisites[i][1]);

    std::unordered_set<int> visited;
    std::unordered_set<int> cycle;
    std::vector<int> path;

    for (int i = 0; i < numCourses; ++i)
        if (!dfsCourseOrder(prereqMap, visited, cycle, path, i, numCourses))
            return {};

    return path;
}

bool Graph::dfsCourseOrder(std::unordered_map<int, std::vector<int>>& prereqMap, 
                           std::unordered_set<int>& visited, std::unordered_set<int>& cycle, 
                           std::vector<int>& path, int course, int numCourses)
{
    // detected a cycle
    if (cycle.find(course) != cycle.end())
        return false;

    // already completed this course!
    if (visited.find(course) != visited.end())
        return true;

    // iterate through each prerequisite recursively
    cycle.insert(course);
    for (int prereq : prereqMap[course])
        if (!dfsCourseOrder(prereqMap, visited, cycle, path, prereq, numCourses))
            return false;

    // remove course from cycle detection, mark it as visited and add it to the path.
    cycle.erase(course);
    visited.insert(course);
    path.push_back(course);

    return true;
}


/**
*
* Complexity:
* Time: O(e)
* Space: O(e)
*/
std::vector<int> Graph::findRedundantEdge(const std::vector<std::vector<int>>& edges)
{
    // Union-Find Algorithm solution
    int n = static_cast<int>(edges.size());
    std::vector<int> parents(n + 1);
    for (unsigned i = 0; i < parents.size(); ++i)
        parents[i] = i;

    std::vector<int> ranks(n + 1, 1);

    // keep unioning nodes using the edges given until we hit a redundant connection
    for (int i = 0; i < n; ++i)
        if (!unionn(edges[i][0], edges[i][1], parents, ranks))
            return edges[i];

    return {};
}

bool Graph::unionn(int n1, int n2, std::vector<int>& parents, std::vector<int>& ranks)
{
    int p1 = find(n1, parents);
    int p2 = find(n2, parents);

    if (p1 == p2)
        return false;

    if (ranks[p1] > ranks[p2])
    {
        parents[p2] = p1;
        ranks[p1] += ranks[p2];
    }
    else
    {
        parents[p1] = p2;
        ranks[p2] += ranks[p1];
    }
    return true;
}

int Graph::find(int n, std::vector<int>& parents)
{
    int p = parents[n];

    while (p != parents[p])
    {
        parents[p] = parents[parents[p]];
        p = parents[p];
    }

    return p;
}

/**
*
* Complexity:
* Time: O(?)
* Space: O(n)
*/
int Graph::wordLadderLength(const std::string& beginWord, const std::string& endWord, const std::vector<std::string>& wordList)
{
    // save complexity by creating adjacency list of words.
    std::unordered_set<std::string> dict(wordList.begin(), wordList.end());
    if (!dict.count(endWord)) return 0; // end word not in list

    std::queue<std::string> q;
    q.push(beginWord);
    int numMutations = 0;

    while (!q.empty())
    {
        int levelSize = static_cast<int>(q.size());
        for (int i = 0; i < levelSize; ++i)
        {
            std::string v = q.front();
            q.pop();

            if (v.compare(endWord) == 0)
                return numMutations + 1;

            dict.erase(v);

            // edges are to words that are only one letter away from current word
            for (unsigned j = 0; j < v.length(); ++j)
            {
                std::string nextWord = v;
                for (char ch = 'a'; ch <= 'z'; ++ch)
                {
                    nextWord[j] = ch;
                    if (dict.count(nextWord)) // make sure its actually in there
                    {
                        q.push(nextWord);
                        dict.erase(nextWord);
                    }
                }
            }
        }
        numMutations++;
    }

    return 0;
}

int Graph::minCostToConnectAllPoints(const std::vector<std::pair<int, int>>& points)
{
    // creating edges between every node
    // key = start node: value = pair<end node, cost>
    std::unordered_map<int, std::vector<std::pair<int, int>>> adjMap;
    for (unsigned i = 0; i < points.size(); ++i)
    {
        int x1 = points[i].first;
        int y1 = points[i].second;
        for (unsigned j = i + 1; j < points.size(); ++j)
        {
            int x2 = points[j].first;
            int y2 = points[j].second;
            int distance = abs(x1 - x2) + abs(y1 - y2); // manhattan distance
            adjMap[i].push_back({ distance, j }); // undirected edges
            adjMap[j].push_back({ distance, i });
        }
    }

    auto cmp = [](const std::pair<int, int> a, const std::pair<int, int> b) {
        return a.first > b.first;
    };
    std::unordered_set<int> visited;
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, decltype(cmp)> minHeap(cmp);
    minHeap.push({ 0, 0 }); // always starts from first index node at cost 0.

    // Prim's algorithm (determine lowest cost edges to keep)
    int answer = 0;
    while (visited.size() < points.size())
    {
        int cost = minHeap.top().first;
        int i = minHeap.top().second;
        minHeap.pop();

        if (visited.find(i) != visited.end())
            continue;

        answer += cost;
        visited.insert(i);
        for (std::pair<int, int> neighbor : adjMap[i])
            if (visited.find(neighbor.second) == visited.end())
                minHeap.push(neighbor);
    }

    return answer;
}

int Graph::minNetworkDelayTime(const std::vector<std::vector<int>>& times, int n, int k)
{
    // creating edges between every node
    // key = start node: value = pair<cost, end node>
    std::unordered_map<int, std::vector<std::pair<int, int>>> adjMap;
    for (const auto& time : times)
        if (time.size() >= 3) // Ensure there are at least 3 elements
            adjMap[time[0]].push_back({ time[2], time[1] }); // Use the actual edges provided


    auto cmp = [](const std::pair<int, int> a, const std::pair<int, int> b) {
        return a.first > b.first;
        };
    std::unordered_set<int> visited;
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, decltype(cmp)> minHeap(cmp);
    minHeap.push({ 0, k });

    // Djikstra's algorithm
    int lastTime = 0;
    while (!minHeap.empty())
    {
        int weight = minHeap.top().first;
        int node = minHeap.top().second;
        minHeap.pop();

        if (visited.find(node) != visited.end())
            continue;

        visited.insert(node);
        lastTime = std::max(lastTime, weight);

        for (std::pair<int, int> neighbor : adjMap[node])
            if (visited.find(neighbor.second) == visited.end())
                minHeap.push({ weight + neighbor.first, neighbor.second }); // adding new weight to neighbor
    }

    if (n == static_cast<int>(visited.size()))
        return lastTime;
    else
        return -1;
}

int Graph::findCheapestFlightsWithinKStops(const std::vector<std::vector<int>>& flights, int src, int dest, int k, int n)
{
    // Bellman-Ford solution
    std::vector<int> prices(n, INT_MAX);
    prices[src] = 0;

    // relaxing edges
    for (int i = 0; i < k + 1; ++i)
    {
        std::vector<int> tempPrices = prices;
        for (unsigned j = 0; j < flights.size(); ++j)
        {
            if (prices[flights[j][0]] == INT_MAX)
                continue;
            if (prices[flights[j][0]] + flights[j][2] < tempPrices[flights[j][1]])
                tempPrices[flights[j][1]] = prices[flights[j][0]] + flights[j][2];
        }
        prices = tempPrices;
    }

    // Destination cannot be reached within k stops
    if (prices[dest] == INT_MAX)
        return -1;
    else
        return prices[dest];
}

int Graph::swimInRisingWater(const std::vector<std::vector<int>>& grid)
{
    int n = static_cast<int>(grid.size());
    // Dijkstra's algorithm
    std::unordered_set<std::pair<int, int>, pair_hash> visited;
    std::priority_queue<std::pair<int, std::pair<int, int>>,
        std::vector<std::pair<int, std::pair<int, int>>>,
        std::greater<std::pair<int, std::pair<int, int>>>> minHeap;
    std::vector<std::pair<int, int>> directions = { { 0, 1 }, { 0, -1 }, { 1, 0 }, { -1, 0 } };

    visited.insert({ 0, 0 });
    minHeap.push({ grid[0][0], { 0, 0 } });
    while (!minHeap.empty())
    {
        int time = minHeap.top().first;
        int r = minHeap.top().second.first;
        int c = minHeap.top().second.second;
        minHeap.pop();

        if (r == n - 1 && c == n - 1) // final square!
            return time;

        for (std::pair<int, int> direction : directions)
        {
            int neighborRow = r + direction.first;
            int neighborColumn = c + direction.second;
            if (neighborRow < 0 || neighborRow >= n ||
                neighborColumn < 0 || neighborColumn >= n ||
                visited.find({ neighborRow, neighborColumn }) != visited.end())
                continue;
            visited.insert({ neighborRow, neighborColumn });
            minHeap.push({ std::max(time, grid[neighborRow][neighborColumn]), { neighborRow, neighborColumn } });
        }
    }

    return -1;
}

std::vector<std::string> Graph::findItinerary(const std::vector<std::vector<std::string>>& tickets)
{
    std::unordered_map<std::string, std::multiset<std::string>> adjMap;
    for (auto& ticket : tickets)
        adjMap[ticket[0]].insert(ticket[1]);

    std::vector<std::string> itinerary;
    dfsItinerary("JFK", adjMap, itinerary);
    std::reverse(itinerary.begin(), itinerary.end()); // The itinerary was constructed in reverse order
    return itinerary;
}

void Graph::dfsItinerary(const std::string& src, std::unordered_map<std::string, std::multiset<std::string>>& adjMap, std::vector<std::string>& itinerary)
{
    while (!adjMap[src].empty())
    {
        std::string next = *adjMap[src].begin();
        adjMap[src].erase(adjMap[src].begin()); // Erase the element by iterator, not value
        dfsItinerary(next, adjMap, itinerary);
    }
    itinerary.push_back(src); // Add after visiting all children to construct the itinerary in reverse
}