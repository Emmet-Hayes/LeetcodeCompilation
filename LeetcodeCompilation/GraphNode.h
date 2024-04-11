#pragma once

#include <vector>


struct GraphNode
{
    GraphNode(int _val = 0, std::vector<GraphNode*> _neighbors = std::vector<GraphNode*>())
    :   val       { _val }
    ,   neighbors { _neighbors }
    {}

    int val;
    std::vector<GraphNode*> neighbors;
};