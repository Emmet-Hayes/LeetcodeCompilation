#pragma once

#include "Solution.h"

#include <vector>


class Greedy : public Solution
{
public:
    Greedy() : Solution("Greedy", "Common challenge problems involving greedy algorithms.") {}
    std::unique_ptr<Solution> clone() const override { return std::make_unique<Greedy>(*this); }
    
    int maximumSubarray(const std::vector<int>& nums);
    bool jumpGame(const std::vector<int>& nums);
    int jumpGameMinJumps(const std::vector<int>& nums);
    int canCompleteCircuit(const std::vector<int>& gas, const std::vector<int>& cost);
    bool handOfStraights(std::vector<int>& hand, int groupSize);
    bool mergeTriplets(const std::vector<std::vector<int>>& triplets, const std::vector<int>& target);
    std::vector<int> partitionLabels(const std::string& s);
    bool checkValidParenthesis(const std::string& s);

    // Maximum Sum Circular Subarray
};