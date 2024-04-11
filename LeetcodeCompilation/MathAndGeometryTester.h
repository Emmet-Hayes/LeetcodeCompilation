#pragma once

#include "MathAndGeometry.h"
#include "Tester.h"


class MathAndGeometryTester : public Tester
{
public:
    MathAndGeometryTester() : Tester { "Math and Geometry" } {}
    bool testAllProblems() override;
    std::unique_ptr<Tester> clone() const override { return std::make_unique<MathAndGeometryTester>(*this); }

private:
    bool testRotateMatrix(std::vector<std::vector<int>> matrix, std::vector<std::vector<int>> expected);
    bool testSpiralOrderMatrix(std::vector<std::vector<int>> matrix, std::vector<int> expected);
    bool testSetMatrixZeroes(std::vector<std::vector<int>> matrix, std::vector<std::vector<int>> expected);
    bool testIsHappyNumber(int n, bool expected);
    bool testPlusOne(std::vector<int> digits, std::vector<int> expected);
    bool testMyPow(double x, int n, double expected);
    bool testStringMultiply(std::string num1, std::string num2, std::string expected);
    bool testDetectSquares();

    // Rotate Image
    // Game of Life
    // Palindrome Number
    // Factorial Trailing Zeroes
    // My Sqrt
    // Max Points on a Line
    // Search a 2D Matrix 2

    MathAndGeometry mag;
};