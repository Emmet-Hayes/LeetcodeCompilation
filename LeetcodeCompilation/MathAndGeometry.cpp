#include "MathAndGeometry.h"

#include <algorithm>


void MathAndGeometry::rotateMatrix(std::vector<std::vector<int>>& matrix)
{
    for (int i = 0; i < matrix.size(); ++i)
        for (int j = i; j < matrix[i].size(); ++j)
            std::swap(matrix[i][j], matrix[j][i]);

    for (int i = 0; i < matrix.size(); ++i)
        std::reverse(matrix[i].begin(), matrix[i].end());
}

std::vector<int> MathAndGeometry::spiralOrderMatrix(const std::vector<std::vector<int>>& matrix)
{
    int m = static_cast<int>(matrix.size()), n = static_cast<int>(matrix[0].size());
    std::vector<int> spiral;

    if (matrix.empty()) return spiral;

    int rowstart = 0;
    int colstart = 0;
    int rowend = static_cast<int>(matrix.size()) - 1;
    int colend = static_cast<int>(matrix[0].size()) - 1;

    // keep closing in on the inner rows
    while (rowstart <= rowend && colstart <= colend)
    {
        // first row across
        for (int j = colstart; j <= colend; ++j)
            spiral.push_back(matrix[rowstart][j]);
        rowstart++;

        // last col down
        for (int i = rowstart; i <= rowend; ++i)
            spiral.push_back(matrix[i][colend]);
        colend--;

        // last row left
        if (rowstart <= rowend)
            for (int j = colend; j >= colstart; --j)
                spiral.push_back(matrix[rowend][j]);
        rowend--;

        // first col up
        if (colstart <= colend)
            for (int i = rowend; i >= rowstart; --i)
                spiral.push_back(matrix[i][colstart]);
        colstart++;
    }

    return spiral;
}

void MathAndGeometry::setMatrixZeroes(std::vector<std::vector<int>>& matrix)
{
    bool firstRowZero = false, firstColZero = false;

    // check first row for zeros
    for (int j = 0; j < matrix[0].size(); ++j)
    {
        if (matrix[0][j] == 0)
        {
            firstRowZero = true;
            break;
        }
    }

    // check first column for zeros
    for (int i = 0; i < matrix.size(); ++i)
    {
        if (matrix[i][0] == 0)
        {
            firstColZero = true;
            break;
        }
    }

    // look for zeros in other rows and columns
    for (int i = 1; i < matrix.size(); ++i)
    {
        for (int j = 1; j < matrix[i].size(); ++j)
        {
            if (matrix[i][j] == 0)
            {
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    }

    // complete setting zeros to marked rows and columns
    for (int i = 1; i < matrix.size(); ++i)
        for (int j = 1; j < matrix[i].size(); ++j)
            if (matrix[i][0] == 0 || matrix[0][j] == 0)
                matrix[i][j] = 0;

    // Zero the first row and column if necessary
    if (firstRowZero)
        for (int j = 0; j < matrix[0].size(); ++j)
            matrix[0][j] = 0;
    if (firstColZero)
        for (int i = 0; i < matrix.size(); ++i)
            matrix[i][0] = 0;
}

bool MathAndGeometry::isHappyNumber(int n)
{
    int i = 0;
    while (n != 1 && i < 100)
    {
        n = sumOfDigitSquares(n);
        i++;
    }

    if (i >= 100)
        return false;
    return true;
}

int MathAndGeometry::sumOfDigitSquares(int n)
{
    int sumOfSquares = 0;
    while (n > 0)
    {
        int digit = n % 10;
        n /= 10;
        sumOfSquares += digit * digit;
    }

    return sumOfSquares;
}

std::vector<int> MathAndGeometry::plusOne(std::vector<int>& digits)
{
    int n = static_cast<int>(digits.size());

    for (int i = n - 1; i >= 0; --i)
    {
        if (digits[i] < 9)
        {
            digits[i]++;
            return digits;
        }
        digits[i] = 0;
    }

    // if all digits are 9, we add a one at the start
    digits.insert(digits.begin(), 1);

    return digits;
}

double MathAndGeometry::myPow(double x, int n)
{
    long long num = std::labs(n);
    double answer = myPowRecursive(x, num);

    // negative exponents are just 1 / x;
    if (n >= 0)
        return answer;
    else
        return 1 / answer;
}

std::string MathAndGeometry::stringMultiply(std::string& num1, std::string& num2)
{
    if (num1.compare("0") == 0 || num2.compare("0") == 0)
        return "0"; // 0 x anything is always 0

    std::vector<int> digits(num1.size() + num2.size(), 0);

    // reverse both numbers to simplify things
    std::reverse(num1.begin(), num1.end());
    std::reverse(num2.begin(), num2.end());

    // simulating elementary school multiplication
    for (int i = 0; i < num1.size(); ++i)
    {
        for (int j = 0; j < num2.size(); ++j)
        {
            int digit = (num1[i] - '0') * (num2[j] - '0');
            digits[i + j] += digit % 10;
            digits[i + j + 1] += digit / 10;
        }
    }

    // deal with carries that are left over from last operation
    for (int i = 0; i < digits.size() - 1; ++i)
    {
        if (digits[i] > 9)
        {
            int value = digits[i];
            digits[i + 1] = digits[i + 1] + value / 10;
            digits[i] = value % 10;
        }
    }

    // reverse the digits
    std::reverse(digits.begin(), digits.end());

    // convert digits to string
    std::string answer;
    for (int i = 0; i < digits.size(); ++i)
        answer += digits[i] + '0'; // convert back into char representation of digit

    //remove extra 0's from the front
    int beg = 0;
    while (answer[beg] == '0')
        beg++;
    answer = answer.substr(beg);

    return answer;
}

double MathAndGeometry::myPowRecursive(double x, long long n)
{
    if (x == 0) return 0;
    if (n == 0) return 1;

    // divide and conquer
    double answer = myPowRecursive(x, n / 2);
    answer *= answer;

    // if n is odd we need to add another multiplication to x
    if (n % 2 == 1)
        return answer * x;
    return answer;
}

void MathAndGeometry::DetectSquares::add(const std::pair<int, int>& point)
{
    std::pair<int, int> pt { point.first, point.second };
    pointsMap[pt]++;
}

int MathAndGeometry::DetectSquares::count(const std::pair<int, int>& point)
{
    int count = 0;
    int px = point.first;
    int py = point.second;
    for (const auto& pt : pointsMap)
    {
        int x = pt.first.first;
        int y = pt.first.second;
        // Skip if on the same row or column
        if (x == px || y == py) continue;
        // Check if the sides can form a square
        if (abs(px - x) == abs(py - y))
            // Check for the existence of the other three corners
            if (pointsMap.find({ px, y }) != pointsMap.end() &&
                pointsMap.find({ x, py }) != pointsMap.end() &&
                pointsMap.find({ x, y }) != pointsMap.end())
                count += pointsMap[{px, y}] * pointsMap[{x, py}] * pointsMap[{x, y}];
    }
    return count;
}
