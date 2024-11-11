#include "DynamicProgramming.h"

#include <algorithm>
#include <climits>
#include <unordered_set>


/**
* 
* Complexity:
* Time: O(n)
* Space: O(1)
*/
int DynamicProgramming::climbingStairs(int n)
{
    // base cases
    if (n <= 2) return n;

    // recursive case for n >= 3
    int stairn = 0;
    int stair1 = 1;
    int stair2 = 1;
    for (int i = 3; i <= n + 1; ++i)
    {
        stairn = stair1 + stair2; // 1 + 1 = 2, 1 + 2 = 3, 2 + 3 = 5, etc
        stair1 = stair2; // move 'pointers' to stairs up..
        stair2 = stairn;
    }

    return stairn;
}


/**
*
* Complexity:
* Time: O(n)
* Space: O(1)
*/
int DynamicProgramming::minCostClimbingStairs(std::vector<int>& cost)
{
    int n = static_cast<int>(cost.size());
    for (int i = 2; i < n; ++i)
        cost[i] += std::min(cost[i - 1], cost[i - 2]);

    return std::min(cost[n - 1], cost[n - 2]);
}


/**
*
* Complexity:
* Time: O(n)
* Space: O(1)
*/
int DynamicProgramming::houseRobber(const std::vector<int>& nums)
{
    int n = static_cast<int>(nums.size());
    if (n == 1)
        return nums[0];
    if (n == 2)
        return std::max(nums[0], nums[1]);

    int prevprev = nums[0];
    int prev = std::max(nums[0], nums[1]);
    int curr = 0;
    for (int i = 2; i < n; ++i)
    {
        curr = std::max(prev, nums[i] + prevprev);
        prevprev = prev;
        prev = curr;
    }

    return curr;
}


/**
*
* Complexity:
* Time: O(n)
* Space: O(1)
*/
int DynamicProgramming::houseRobberCircular(const std::vector<int>& nums)
{
    int n = static_cast<int>(nums.size());
    if (n == 1)
        return nums[0];
    if (n == 2)
        return std::max(nums[0], nums[1]);

    // check up to the end for houses on the edge of the circle
    return std::max(houseRobberHelper(nums, 0, n - 1), houseRobberHelper(nums, 1, n));
}

int DynamicProgramming::houseRobberHelper(const std::vector<int>& nums, int start, int end)
{
    int prevprev = 0,
        prev = 0,
        curr = 0;

    for (int i = start; i < end; ++i)
    {
        curr = std::max(prevprev + nums[i], prev);
        prevprev = prev;
        prev = curr;
    }

    return prev;
}


/**
*
* Complexity:
* Time: O(n)
* Space: O(1)
*/
std::string DynamicProgramming::longestPalindrome(const std::string& s)
{
    if (s.empty()) return "";

    // two pointer solution, find the start and len of longest palindrome
    int start = 0, maxLen = 1;
    int n = static_cast<int>(s.size());
    for (int i = 0; i < n - 1; ++i)
    {
        int oddLen = expandPalindrome(s, i, i);
        int evenLen = expandPalindrome(s, i, i + 1);
        int maxCurrLen = std::max(oddLen, evenLen);
        if (maxLen < maxCurrLen)
        {
            maxLen = maxCurrLen;
            start = i - (maxLen - 1) / 2;
        }
    }

    return s.substr(start, maxLen);
}

int DynamicProgramming::expandPalindrome(const std::string& s, int left, int right)
{
    while (left >= 0 && right < s.size() && s[left] == s[right])
    {
        --left;
        ++right;
    }
    return right - left - 1;
}


/**
*
* Complexity:
* Time: O(n)
* Space: O(1)
*/
int DynamicProgramming::countPalindromicSubstrings(const std::string& s)
{
    if (s.empty()) return 0;

    int palCount = 0;
    for (int i = 0; i < s.size() - 1; ++i)
    {
        palCount += expandPalindromeCount(s, i, i);
        palCount += expandPalindromeCount(s, i, i + 1);
    }
    return palCount + 1;
}

int DynamicProgramming::expandPalindromeCount(const std::string& s, int left, int right)
{
    int count = 0;
    while (left >= 0 && right < s.size() && s[left] == s[right])
    {
        --left;
        ++right;
        count++;
    }

    return count;
}



/**
*
* Complexity:
* Time: O(n)
* Space: O(1)
*/
int DynamicProgramming::numWaysToDecode(const std::string& s)
{
    if (s.empty() || s[0] == '0') return 0;
    int n = static_cast<int>(s.size());
    int nextnext = 1;
    int next = 1;
    int curr = 0;

    for (int i = n - 1; i >= 0; --i)
    {
        if (s[i] == '0')
            curr = 0; // dp[i] = 0
        else
            curr = next; // dp[i] = dp[i + 1]

        if (i + 1 < s.size() && (s[i] == '1' ||
            (s[i] == '2' && s[i + 1] >= '0' && s[i + 1] <= '6')))
            curr += nextnext; // dp[i] += dp[i + 2]

        nextnext = next;
        next = curr;
    }

    return curr;
}


/**
*
* Complexity:
* Time: O(n)
* Space: O(n)
*/
int DynamicProgramming::coinChange(const std::vector<int>& coins, int amount)
{
    if (amount == 0) return 0;
    std::vector<int> dp(amount + 1, amount + 1);
    dp[0] = 0;

    // only try a coin if it gets us closer to the solution
    for (int i = 1; i <= amount; ++i)
        for (int j = 0; j < coins.size(); ++j)
            if (i - coins[j] >= 0)
                dp[i] = std::min(dp[i], 1 + dp[i - coins[j]]);

    if (dp[amount] != amount + 1)
        return dp[amount];

    return -1;
}


/**
*
* Complexity:
* Time: O(n)
* Space: O(1)
*/
int DynamicProgramming::maximumProductSubarray(const std::vector<int>& nums)
{
    int maxProduct = INT_MIN;
    for (int val : nums)
        if (maxProduct < val)
            maxProduct = val;

    int n = static_cast<int>(nums.size());
    int dpMin = 1, dpMax = 1;
    int currDpMin = INT_MIN; // temp var used in loop for updating dpMin
    for (int i = 0; i < n; ++i)
    {
        // zeros are gonna kill us
        if (nums[i] == 0)
        {
            dpMin = 1;
            dpMax = 1;
            continue;
        }
        currDpMin = dpMax * nums[i];
        dpMax = std::max({ nums[i] * dpMax, nums[i] * dpMin, nums[i] });
        dpMin = std::min({ currDpMin,       nums[i] * dpMin, nums[i] });
        maxProduct = std::max(maxProduct, dpMax);
    }

    return maxProduct;
}


/**
*
* Complexity:
* Time: O(n)
* Space: O(n)
*/
bool DynamicProgramming::wordBreak(const std::string& s, const std::vector<std::string>& wordDict)
{
    std::unordered_set<std::string> wordSet(wordDict.begin(), wordDict.end());
    std::vector<bool> foundDict(s.size() + 1, false);

    foundDict[0] = true;

    for (int i = 1; i < s.size() + 1; ++i)
    {
        for (int j = 0; j < i; ++j)
        {
            if (foundDict[j] && wordSet.find(s.substr(j, i - j)) != wordSet.end())
            {
                foundDict[i] = true;
                break;
            }
        }
    }

    return foundDict[s.size()];
}


/**
*
* Complexity:
* Time: O(n log n)
* Space: O(n)
*/
int DynamicProgramming::longestIncreasingSubsequence(const std::vector<int>& nums)
{
    std::vector<int> tails;

    for (int num : nums)
    {
        int left = 0, right = static_cast<int>(tails.size());

        while (left < right)
        {
            int mid = left + (right - left) / 2;
            if (tails[mid] < num)
                left = mid + 1;
            else
                right = mid;
        }

        if (left == tails.size())
            tails.push_back(num);
        else
            tails[left] = num;
    }

    return static_cast<int>(tails.size());
}


/**
*
* Complexity:
* Time: O(n)
* Space: O(n)
*/
bool DynamicProgramming::canPartition(const std::vector<int>& nums)
{
    int totalSum = 0;
    for (int num : nums) totalSum += num;
    if (totalSum % 2 != 0) return false; // If totalSum is odd, no partition will add up to half the target
    int target = totalSum / 2;
    std::vector<bool> dp(target + 1, false);
    dp[0] = true; // Base case: sum of 0 is always possible

    // Update DP table for each number
    for (int num : nums)
        for (int j = target; j >= num; --j)
            if (dp[j - num])
                dp[j] = true;

    return dp[target];
}

/**
*
* Complexity:
* Time: O(m)
* Space: O(1)
*/
int DynamicProgramming::uniquePaths(int m, int n)
{
    // C(n, k) = n! / (k!(n - k)!)
    double answer = 1;
    int N = m + n - 2;
    int k = m - 1;

    for (int i = 1; i <= k; ++i)
    {
        answer *= (N - k + i);
        answer /= i;
    }

    if (answer > INT_MAX)
        return INT_MAX;
    return static_cast<int>(answer);
}

/**
*
* Complexity:
* Time: O(n*m)
* Space: O(n*m)
*/
int DynamicProgramming::longestCommonSubsequence(const std::string& text1, const std::string& text2)
{
    int m = static_cast<int>(text1.size()), n = static_cast<int>(text2.size());

    // each cell of the 2d dp matrix contains the count of common chars between strings
    std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, 0));

    for (int i = 1; i < m + 1; ++i)
    {
        for (int j = 1; j < n + 1; ++j)
        {
            // on matches, add the score from the top-left diagonal
            if (text1[i - 1] == text2[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    return dp[m][n];
}

/**
*
* Complexity:
* Time: O(n)
* Space: O(n)
*/
int DynamicProgramming::buyAndSellStockWithCooldown(const std::vector<int>& prices)
{
    size_t n = prices.size();

    if (n <= 1)
        return 0;

    std::vector<int> hold(n, 0), sold(n, 0), rest(n, 0);

    hold[0] = -prices[0];
    sold[0] = 0;
    rest[0] = 0;

    for (int i = 1; i < n; ++i)
    {
        hold[i] = std::max(hold[i - 1], rest[i - 1] - prices[i]);
        sold[i] = hold[i - 1] + prices[i];
        rest[i] = std::max(rest[i - 1], sold[i - 1]);
    }

    return std::max(sold[n - 1], rest[n - 1]);
}


/**
*
* Complexity:
* Time: O(n*m) *where m is the number of coin types, n is the target amount
* Space: O(n)
*/
int DynamicProgramming::coinChangeNumCombinations(const std::vector<int>& coins, int amount)
{
    std::vector<int> dp(amount + 1, 0);
    dp[0] = 1;

    for (int i = 0; i < coins.size(); ++i)
        for (int j = coins[i]; j <= amount; ++j)
            dp[j] += dp[j - coins[i]];

    return dp[amount];
}


/**
*
* Complexity:
* Time: O(n)
* Space: O(n)
*/
int DynamicProgramming::findTargetSumWays(const std::vector<int>& nums, int target)
{
    int totalSum = 0;
    for (int i = 0; i < nums.size(); ++i)
        totalSum += nums[i];

    if ((target + totalSum) % 2 != 0 || std::abs(target) > totalSum)
        return 0;

    int subsetSum = (target + totalSum) / 2;
    std::vector<int> dp(subsetSum + 1, 0);
    dp[0] = 1;

    for (int num : nums)
        for (int i = subsetSum; i >= num; i--)
            dp[i] += dp[i - num];

    return dp[subsetSum];
}


/**
*
* Complexity:
* Time: O(n*m)
* Space: O(n*m)
*/
int DynamicProgramming::editDistance(const std::string& word1, const std::string& word2)
{
    size_t m = word1.size(), n = word2.size();
    std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1));

    for (int i = 0; i < dp[0].size(); ++i)
        dp[0][i] = i;

    for (int i = 0; i < dp.size(); ++i)
        dp[i][0] = i;

    for (int i = 1; i < dp.size(); ++i)
    {
        for (int j = 1; j < dp[0].size(); ++j)
        {
            // we don't need to add an edit to the word when its already equivalent
            if (word1[i - 1] == word2[j - 1])
                dp[i][j] = dp[i - 1][j - 1];
            // otherwise, we have to either remove a letter or change it to the word we want
            else
                dp[i][j] = std::min({ dp[i - 1][j] + 1, dp[i][j - 1] + 1, dp[i - 1][j - 1] + 1 });
        }
    }

    return dp[m][n];
}


/**
*
* Complexity:
* Time: O(n*m)
* Space: O(n*m)
*/
bool DynamicProgramming::isInterleaved(const std::string& s1, const std::string& s2, const std::string& s3)
{
    if (s1.size() + s2.size() != s3.size())
        return false;

    int m = static_cast<int>(s1.size());
    int n = static_cast<int>(s2.size());
    std::vector<std::vector<bool>> dp(m + 1, std::vector<bool>(n + 1, false));

    // base cases
    dp[m][n] = true; // since both strings are null-terminated ;)

    for (int i = m; i >= 0; --i)
    {
        for (int j = n; j >= 0; --j)
        {
            if (i < s1.size() && s1[i] == s3[i + j] && dp[i + 1][j])
                dp[i][j] = true;
            if (j < s2.size() && s2[j] == s3[i + j] && dp[i][j + 1])
                dp[i][j] = true;
        }
    }

    return dp[0][0];
}

/**
*
* Complexity:
* Time: O(m*n)
* Space: O(m*n)
*/
unsigned long long DynamicProgramming::distinctSubsequences(const std::string& s, const std::string& t)
{
    int m = static_cast<int>(s.size()), n = static_cast<int>(t.size());
    std::vector<std::vector<unsigned long long>> dp(m + 1, std::vector<unsigned long long>(n + 1, 0));

    // first column gets zeros
    for (int i = 0; i <= m; ++i)
        dp[i][0] = 1;

    for (int i = 1; i <= m; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            // If chars match, take the sum of
            // 1 if we exclude this char, or include it
            if (s[i - 1] == t[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
            else
                dp[i][j] = dp[i - 1][j];
        }
    }

    return dp[m][n];
}


/**
* 
* Complexity:
* Time: O(m*n)
* Space: O(m*n)
*/
int DynamicProgramming::longestIncreasingPath(const std::vector<std::vector<int>>& matrix)
{
    if (matrix.size() == 1 && matrix[0].size() == 1)
        return matrix[0][0];

    int m = static_cast<int>(matrix.size());
    int n = static_cast<int>(matrix[0].size());

    std::vector<std::vector<int>> dp(m, std::vector<int>(n, 0));
    int maxPath = 0;
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
            // check all 4 directions, track previous value to make sure we only increase
            maxPath = std::max(maxPath, dfsLIP(matrix, dp, i, j, -1));

    return maxPath;
}

int DynamicProgramming::dfsLIP(const std::vector<std::vector<int>>& matrix, std::vector<std::vector<int>>& dp, int i, int j, int prevVal)
{
    // make sure we don't go out of bounds, or to a visited cell.
    if (i < 0 || i >= matrix.size() || j < 0 || j >= matrix[0].size() || matrix[i][j] <= prevVal)
        return 0;
    if (dp[i][j] != 0)
        return dp[i][j];

    // total the amount of paths at this cell
    int paths = 1;

    paths = std::max(paths, 1 + dfsLIP(matrix, dp, i + 1, j, matrix[i][j]));
    paths = std::max(paths, 1 + dfsLIP(matrix, dp, i - 1, j, matrix[i][j]));
    paths = std::max(paths, 1 + dfsLIP(matrix, dp, i, j + 1, matrix[i][j]));
    paths = std::max(paths, 1 + dfsLIP(matrix, dp, i, j - 1, matrix[i][j]));
    dp[i][j] = paths;

    return paths;
}

/**
*
* Complexity:
* Time: O(n*m)
* Space: O(n*m)
*/
bool DynamicProgramming::isMatchRegex(const std::string& s, const std::string& p)
{
    int m = static_cast<int>(s.size()), n = static_cast<int>(p.size());
    std::vector<std::vector<bool>> dp(m + 1, std::vector<bool>(n + 1, false));

    // base case
    dp[0][0] = true;

    // patterns like a*, a*b, a*b*c*
    for (int j = 1; j <= n; ++j)
        if (p[j - 1] == '*')
            dp[0][j] = dp[0][j - 2];

    // handle . and *
    for (int i = 1; i <= m; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            if (p[j - 1] == '.' || p[j - 1] == s[i - 1])
                dp[i][j] = dp[i - 1][j - 1];
            else if (p[j - 1] == '*')
                dp[i][j] = dp[i][j - 2] || (dp[i - 1][j] &&
                    (s[i - 1] == p[j - 2] || p[j - 2] == '.'));
        }
    }

    return dp[m][n];
}


/**
*
* Complexity:
* Time: O(n^3)
* Space: O(n^2)
*/
int DynamicProgramming::maxBurstBalloons(std::vector<int>& nums)
{
    // inserting 1's at front and back to maintain calculation of bursts at ends of vec
    nums.insert(nums.begin(), 1);
    nums.push_back(1);
    int n = static_cast<int>(nums.size());
    std::vector<std::vector<int>> dp(n, std::vector<int>(n, 0));

    for (int i = 2; i < n; ++i)
    {
        for (int l = 0; l < n - i; ++l)
        {
            int r = l + i;
            for (int k = l + 1; k < r; k++)
                dp[l][r] = std::max(dp[l][r],
                    nums[l] * nums[k] * nums[r] + dp[l][k] + dp[k][r]);
        }
    }

    return dp[0][n - 1];
}


