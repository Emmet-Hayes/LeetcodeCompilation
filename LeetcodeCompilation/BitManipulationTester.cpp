#include "BitManipulationTester.h"


bool BitManipulationTester::testAllProblems()
{
    addTestCase(testSingleNumber({ 2, 2, 1 }, 1));
    addTestCase(testSingleNumber({ 4, 1, 2, 1, 2 }, 4));
    addTestCase(testSingleNumber({ 1 }, 1));

    addTestCase(testHammingWeight(11, 3));
    addTestCase(testHammingWeight(128, 1));
    addTestCase(testHammingWeight(2147483645, 30));

    addTestCase(testCountBits(2, { 0, 1, 1 }));
    addTestCase(testCountBits(5, { 0, 1, 1, 2, 1, 2 }));

    addTestCase(testReverseBits(43261596, 964176192));
    addTestCase(testReverseBits(4294967293, 3221225471));

    addTestCase(testMissingNumberHash({ 3, 0, 1 }, 2));
    addTestCase(testMissingNumberHash({ 0, 1 }, 2));
    addTestCase(testMissingNumberHash({ 9, 6, 4, 2, 3, 5, 7, 0, 1 }, 8));

    addTestCase(testMissingNumberBitwise({ 3, 0, 1 }, 2));
    addTestCase(testMissingNumberBitwise({ 0, 1 }, 2));
    addTestCase(testMissingNumberBitwise({ 9, 6, 4, 2, 3, 5, 7, 0, 1 }, 8));

    addTestCase(testGetSumBitwise(1, 2, 3));
    addTestCase(testGetSumBitwise(2, 3, 5));

    addTestCase(testReverseInteger(123, 321));
    addTestCase(testReverseInteger(-123, -321));
    addTestCase(testReverseInteger(120, 21));
    
    return runAllTests();
}

bool BitManipulationTester::testSingleNumber(std::vector<int> nums, int expected)
{
    int actual = bm.singleNumber(nums);
    if (getVerbose())
    {
        ss << "\nSingle Number Test Run On Input Vector:\n[ ";
        for (int val : nums)
            ss << val << " ";
        ss << "]\nResult: " << actual << " | Expected: " << expected << "\n";
    }
    return actual == expected;
}

bool BitManipulationTester::testHammingWeight(uint32_t n, int expected)
{
    int actual = bm.hammingWeight(n);
    if (getVerbose())
        ss << "\nHamming Weight Test Run On Input Value: " << n << "\nResult: " << actual << " | Expected: " << expected << "\n";

    return actual == expected;
}

bool BitManipulationTester::testCountBits(int n, std::vector<int> expected)
{
    std::vector<int> actual = bm.countBits(n);

    if (actual.size() != expected.size())
        return false;
    for (int i = 0; i < expected.size(); ++i)
        if (actual[i] != expected[i])
            return false;
    return true;
}

bool BitManipulationTester::testReverseBits(uint32_t n, uint32_t expected)
{
    uint32_t actual = bm.reverseBits(n);
    if (getVerbose())
        ss << "\nReverse Bits Test Run On Input Value: " << n << "\nResult: " << actual << " | Expected: " << expected << "\n";
    return actual == expected;
}

bool BitManipulationTester::testMissingNumberHash(std::vector<int> nums, int expected)
{
    int actual = bm.missingNumberHash(nums);
    if (getVerbose())
    {
        ss << "\nMissing Number Hash Test Run On Input Vector:\n[ ";
        for (int val : nums)
            ss << val << " ";
        ss << "]\nResult: " << actual << " | Expected: " << expected << "\n";
    }
    return actual == expected;
}

bool BitManipulationTester::testMissingNumberBitwise(std::vector<int> nums, int expected)
{
    int actual = bm.missingNumberBitwise(nums);
    if (getVerbose())
    {
        ss << "\nMissing Number Bitwise Test Run On Input Vector:\n[ ";
        for (int val : nums)
            ss << val << " ";
        ss << "]\nResult: " << actual << " | Expected: " << expected << "\n";
    }
    return actual == expected;
}

bool BitManipulationTester::testGetSumBitwise(int a, int b, int expected)
{
    int actual = bm.getSumBitwise(a, b);
    if (getVerbose())
        ss << "\nGet Sum Bitwise Test Run On Input Values: " << a << " and " << b << "\nResult: " << actual << " | Expected: " << expected << "\n";
    return actual == expected;
}

bool BitManipulationTester::testReverseInteger(int x, int expected)
{
    int actual = bm.reverseInteger(x);
    if (getVerbose())
        ss << "\nReverse Integer Test Run On Input Value: " << x << "\nResult: " << actual << " | Expected: " << expected << "\n";
    return actual == expected;
}
