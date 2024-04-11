#include "MathAndGeometryTester.h"


bool MathAndGeometryTester::testAllProblems()
{
    
    addTestCase(testRotateMatrix({ { 1, 2, 3 }, 
                                   { 4, 5, 6 }, 
                                   { 7, 8, 9 } }, { { 7, 4, 1 },
                                                    { 8, 5, 2 },
                                                    { 9, 6, 3 } }));
    addTestCase(testRotateMatrix({ { 5,   1,  9, 11 },
                                   { 2,   4,  8, 10 },
                                   { 13,  3,  6,  7 },
                                   { 15, 14, 12, 16 } }, { { 15, 13,  2,  5 },
                                                           { 14,  3,  4,  1 },
                                                           { 12,  6,  8,  9 },
                                                           { 16,  7, 10, 11 } }));

    addTestCase(testSpiralOrderMatrix({ { 1, 2, 3 },
                                        { 4, 5, 6 },
                                        { 7, 8, 9 } }, { 1, 2, 3, 6, 9, 8, 7, 4, 5 }));
    addTestCase(testSpiralOrderMatrix({ { 1,  2,  3,  4 },
                                        { 5,  6,  7,  8 },
                                        { 9, 10, 11, 12 } }, { 1, 2, 3, 4, 8, 12, 11, 10, 9, 5, 6, 7 }));

    addTestCase(testSetMatrixZeroes({ { 1, 1, 1 },
                                      { 1, 0, 1 },
                                      { 1, 1, 1 } }, { { 1, 0, 1 },
                                                       { 0, 0, 0 },
                                                       { 1, 0, 1 } }));
    addTestCase(testSetMatrixZeroes({ { 0, 1, 2, 0 },
                                      { 3, 4, 5, 2 },
                                      { 1, 3, 1, 5 } }, { { 0, 0, 0, 0 },
                                                          { 0, 4, 5, 0 },
                                                          { 0, 3, 1, 0 } }));

    addTestCase(testIsHappyNumber(19, true));
    addTestCase(testIsHappyNumber(2, false));

    addTestCase(testPlusOne({ 1, 2, 3 }, { 1, 2, 4 }));
    addTestCase(testPlusOne({ 4, 3, 2, 1 }, { 4, 3, 2, 2 }));
    addTestCase(testPlusOne({ 9 }, { 1, 0 }));

    addTestCase(testMyPow(2.00000, 10, 1024.00000));
    addTestCase(testMyPow(2.10000, 3, 9.26100));
    addTestCase(testMyPow(2.00000, -2, 0.25000));

    addTestCase(testStringMultiply("2", "3", "6"));
    addTestCase(testStringMultiply("123", "456", "56088"));

    addTestCase(testDetectSquares());

    return runAllTests();
}

bool MathAndGeometryTester::testRotateMatrix(std::vector<std::vector<int>> matrix, std::vector<std::vector<int>> expected)
{
    if (getVerbose())
    {
        ss << "\nRotate Matrix Test Run on Input Matrix:\n\n";
        for (std::vector<int> row : matrix)
        {
            for (int val : row)
                ss << val << ' ';
            ss << '\n';
        }
    }
    mag.rotateMatrix(matrix);
    if (getVerbose())
    {
        ss << "\nResult:\n\n";
        for (std::vector<int> row : matrix)
        {
            for (int val : row)
                ss << val << ' ';
            ss << '\n';
        }
        ss << "\nExpected:\n\n";
        for (std::vector<int> row : expected)
        {
            for (int val : row)
                ss << val << ' ';
            ss << '\n';
        }
        ss << '\n';
    }
    if (matrix.size() != expected.size())
        return false;
    for (int i = 0; i < expected.size(); ++i)
    {
        if (matrix[i].size() != expected[i].size())
            return false;
        for (int j = 0; j < expected[i].size(); ++j)
            if (matrix[i][j] != expected[i][j])
                return false;
    }
    return true;
}

bool MathAndGeometryTester::testSpiralOrderMatrix(std::vector<std::vector<int>> matrix, std::vector<int> expected)
{
    if (getVerbose())
    {
        ss << "\nSpiral Order Matrix Test Run on Input Matrix:\n\n";
        for (std::vector<int> row : matrix)
        {
            for (int val : row)
                ss << val << ' ';
            ss << '\n';
        }
    }
    std::vector<int> actual = mag.spiralOrderMatrix(matrix);
    if (getVerbose())
    {
        ss << "\nResult:   [ ";
        for (int val : actual)
            ss << val << " ";
        ss << "]\nExpected: [ ";
        for (int val : expected)
            ss << val << " ";
        ss << "]\n";
    }
    if (actual.size() != expected.size())
        return false;
    for (int i = 0; i < expected.size(); ++i)
        if (actual[i] != expected[i])
            return false;
    return true;
}

bool MathAndGeometryTester::testSetMatrixZeroes(std::vector<std::vector<int>> matrix, std::vector<std::vector<int>> expected)
{
    if (getVerbose())
    {
        ss << "\nSet Matrix Zeroes Test Run on Input Matrix:\n\n";
        for (std::vector<int> row : matrix)
        {
            for (int val : row)
                ss << val << ' ';
            ss << '\n';
        }
    }
    mag.setMatrixZeroes(matrix);
    if (getVerbose())
    {
        ss << "\nResult:\n\n";
        for (std::vector<int> row : matrix)
        {
            for (int val : row)
                ss << val << ' ';
            ss << '\n';
        }
        ss << "\nExpected:\n\n";
        for (std::vector<int> row : expected)
        {
            for (int val : row)
                ss << val << ' ';
            ss << '\n';
        }
        ss << '\n';
    }
    if (matrix.size() != expected.size())
        return false;
    for (int i = 0; i < expected.size(); ++i)
    {
        if (matrix[i].size() != expected[i].size())
            return false;
        for (int j = 0; j < expected[i].size(); ++j)
            if (matrix[i][j] != expected[i][j])
                return false;
    }
    return true;
}

bool MathAndGeometryTester::testIsHappyNumber(int n, bool expected)
{
    bool actual = mag.isHappyNumber(n);
    if (getVerbose())
        ss << "Is Happy Number Test Run on Input Value: " << n << "\nResult: " << actual << " | Expected: " << expected << "\n";

    return actual == expected;
}

bool MathAndGeometryTester::testPlusOne(std::vector<int> digits, std::vector<int> expected)
{
    std::vector<int> actual = mag.plusOne(digits);
    if (getVerbose())
    {
        ss << "Plus One Test Run on Input Vector: [ ";
        for (int digit : digits)
            ss << digit << " ";
        ss << "]\nResult:   [ ";
        for (int digit : actual)
            ss << digit << " ";
        ss << "]\nExpected: [ ";
        for (int digit : expected)
            ss << digit << " ";
        ss << "]\n";
    }
    if (actual.size() != expected.size())
        return false;
    for (int i = 0; i < expected.size(); ++i)
        if (actual[i] != expected[i])
            return false;
    return true;
}

bool MathAndGeometryTester::testMyPow(double x, int n, double expected)
{
    double actual = mag.myPow(x, n);
    if (getVerbose())
        ss << "\nMy Pow Function Test Run on Input Value: " << x << " to the " << n 
           << "th power\nResult: " << actual << " | Expected : " << expected << "\n";
    return std::fabs(actual - expected) < 1e-9;
}

bool MathAndGeometryTester::testStringMultiply(std::string num1, std::string num2, std::string expected)
{
    std::string actual = mag.stringMultiply(num1, num2);
    if (getVerbose())
        ss << "\nString Multiply Test Run on Input Strings: " << num1 << " and " << num2 
           << "\nResult: " << actual << " | Expected: " << expected << "\n";
    return actual.compare(expected) == 0;
}

bool MathAndGeometryTester::testDetectSquares()
{
    MathAndGeometry::DetectSquares ds;
    ds.add({ 3, 10 });
    ds.add({ 11, 2 });
    ds.add({ 3, 2 });
    if (1 != ds.count({ 11, 10 })) return false;
    if (0 != ds.count({ 14, 8 })) return false;
    ds.add({ 11, 2 });
    if (2 != ds.count({ 11, 10 })) return false;
    return true;
}
