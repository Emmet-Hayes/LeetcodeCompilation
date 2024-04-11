#pragma once

#include "Solution.h"

#include <vector>


class BitManipulation : public Solution
{
public:
    BitManipulation() : Solution("BitManipulation", "Common challenge problems involving bit manipulation.") {}
    std::unique_ptr<Solution> clone() const override { return std::make_unique<BitManipulation>(*this); }
    
    int singleNumber(const std::vector<int>& nums);
    int hammingWeight(uint32_t n);
    std::vector<int> countBits(int n);
    uint32_t reverseBits(uint32_t n);
    int missingNumberHash(const std::vector<int>& nums);
    int missingNumberBitwise(const std::vector<int>& nums);
    int getSumBitwise(int a, int b);
    int reverseInteger(int x);

    // Add Binary
    // Number of 1 Bits
    // Single Number 2
    // BitWise AND of Numbers Range
    // Minimum flips to make a OR b equal to c
};