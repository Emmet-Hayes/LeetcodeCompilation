#pragma once

#include "Solution.h"

#include <unordered_map>
#include <vector>


class MathAndGeometry : public Solution
{
public:
    MathAndGeometry() : Solution("MathAndGeometry", "Common challenge problems involving math and geometry fundamentals.") {}
    std::unique_ptr<Solution> clone() const override { return std::make_unique<MathAndGeometry>(*this); }
    
    void rotateMatrix(std::vector<std::vector<int>>& matrix);
    std::vector<int> spiralOrderMatrix(const std::vector<std::vector<int>>& matrix);
    void setMatrixZeroes(std::vector<std::vector<int>>& matrix);
    bool isHappyNumber(int n);
    std::vector<int> plusOne(std::vector<int>& digits);
    double myPow(double x, int n);
    std::string stringMultiply(std::string& num1, std::string& num2);

    // Rotate Image
    // Game of Life
    // Palindrome Number
    // Factorial Trailing Zeroes
    // My Sqrt
    // Max Points on a Line
    // Search a 2D Matrix 2

    // Custom hash function for std::pair<int, int>
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

    class DetectSquares
    {
    public:
        DetectSquares() {}

        void add(const std::pair<int, int>& point);
        int count(const std::pair<int, int>& point);
    private:
        std::unordered_map<std::pair<int, int>, int, MathAndGeometry::pair_hash> pointsMap;
    };

private:
    int sumOfDigitSquares(int n);
    double myPowRecursive(double x, long long n);
};