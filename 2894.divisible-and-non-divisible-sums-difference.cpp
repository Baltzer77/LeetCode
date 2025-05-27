/*
 * @lc app=leetcode id=2894 lang=cpp
 *
 * [2894] Divisible and Non-divisible Sums Difference
 */

// @lc code=start
class Solution {
public:
    int differenceOfSums(int n, int m) {
        int sum = n * (n +1) / 2;
        int k = n / m;
        int num2 = k * (k + 1) * m / 2;

        return sum - 2 * num2;
    }
};
// @lc code=end

