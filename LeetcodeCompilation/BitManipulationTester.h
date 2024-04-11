#pragma once

#include "BitManipulation.h"
#include "Tester.h"


class BitManipulationTester : public Tester
{
public:
    BitManipulationTester() : Tester { "Bit Manipulation" } {}
    bool testAllProblems() override;
    std::unique_ptr<Tester> clone() const override { return std::make_unique<BitManipulationTester>(*this); }

private:
    bool testSingleNumber(std::vector<int> nums, int expected);
    bool testHammingWeight(uint32_t n, int expected);
    bool testCountBits(int n, std::vector<int> expected);
    bool testReverseBits(uint32_t n, uint32_t expected);
    bool testMissingNumberHash(std::vector<int> nums, int expected);
    bool testMissingNumberBitwise(std::vector<int> nums, int expected);
    bool testGetSumBitwise(int a, int b, int expected);
    bool testReverseInteger(int x, int expected);

    // Add Binary
    // Number of 1 Bits
    // Single Number 2
    // BitWise AND of Numbers Range
    // Minimum flips to make a OR b equal to c

    BitManipulation bm;
};