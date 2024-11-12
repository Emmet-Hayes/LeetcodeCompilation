#include "BitManipulation.h"

#include <bitset>
#include <unordered_map>


/**
* 
* Complexity:
* Time: O(n)
* Space: O(1)
*/
int BitManipulation::singleNumber(const std::vector<int>& nums)
{
    int result = 0;
    for (unsigned i = 0; i < nums.size(); ++i)
        result ^= nums[i];
    return result;
}

/**
*
* Complexity:
* Time: O(n)
* Space: O(1)
*/
int BitManipulation::hammingWeight(uint32_t n)
{
    int count = 0;
    while (n != 0)
    {
        count++;
        n &= (n - 1); // remove the rightmost 1-bit
    }
    return count;
}

std::vector<int> BitManipulation::countBits(int n)
{
    std::vector<int> bits(n + 1, 0);

    for (unsigned i = 0; i < bits.size(); ++i)
    {
        int t = i;
        while (t > 0)
        {
            bits[i] += t % 2;
            t /= 2;
        }
    }
    return bits;
}

/**
* Complexity:
* Time: O(1)
* Space: O(1)
*/
uint32_t BitManipulation::reverseBits(uint32_t n)
{
    std::bitset<32> bits(n);

    // swap bits at beginning and end
    for (int i = 0; i < 16; ++i) 
    {
        bool temp = bits[i];
        bits[i] = bits[31 - i];
        bits[31 - i] = temp;
    }

    return bits.to_ulong();
}

/**
* Complexity:
* Time: O(n)
* Space: O(n)
*/
int BitManipulation::missingNumberHash(const std::vector<int>& nums)
{
    std::unordered_map<int, int> numbermap;
    int max = 0;
    for (unsigned i = 0; i < nums.size(); ++i)
        if (max < nums[i])
            max = nums[i];

    for (int i = 0; i < max; ++i)
        numbermap[i] = 0;

    for (unsigned i = 0; i < nums.size(); ++i)
        numbermap[nums[i]]++;

    for (int i = 0; i < max; ++i)
        if (numbermap[i] < 1)
            return i;

    return static_cast<int>(nums.size());
}


/**
* Complexity:
* Time: O(n)
* Space: O(1)
*/
int BitManipulation::missingNumberBitwise(const std::vector<int>& nums)
{
    int xorSum = 0;
    int n = static_cast<int>(nums.size());

    // XOR all the array elements
    for (int i = 0; i < n; ++i)
        xorSum ^= nums[i];

    // XOR the result with all the indices and n
    for (int i = 0; i <= n; ++i)
        xorSum ^= i;

    // The remaining number is the missing number
    return xorSum;
}

int BitManipulation::getSumBitwise(int a, int b)
{
    // Iterate till there is no carry  
    while (b != 0)
    {
        // Carry now contains common set bits of a and b
        unsigned carry = a & b;

        // Sum of bits of a and b where at least one of the bits is not set
        a = a ^ b;

        // Carry is shifted by one so that adding it to a gives the required sum
        b = carry << 1;
    }
    // When carry is 0, a contains the sum
    return a;
}

int BitManipulation::reverseInteger(int x)
{
    std::string xstr = std::to_string(x);

    bool isNegative = false;
    if (xstr[0] == '-')
    {
        isNegative = true;
        xstr.erase(xstr.begin());
    }

    unsigned swapindex = 0;

    while (swapindex < xstr.size() / 2)
    {
        std::swap(xstr[swapindex], xstr[xstr.size() - 1 - swapindex]);
        swapindex++;
    }

    if (xstr.size() == 10)
    {
        std::string limit = isNegative ? "2147483648" : "2147483647";

        for (unsigned i = 0; i < xstr.size(); ++i)
        {
            if (xstr[i] > limit[i]) return 0;
            if (xstr[i] < limit[i]) break;
        }
    }

    if (isNegative)
        xstr.insert(xstr.begin(), '-');

    return std::stoi(xstr);
}
