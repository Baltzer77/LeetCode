/*
 * @lc app=leetcode id=1009 lang=cpp
 *
 * [1009] Complement of Base 10 Integer
 */

// @lc code=start
class Solution {
public:
    int bitwiseComplement(int n) {
        if (n == 0) return 1;

        int numBits = 0;
        for (int temp = n; temp > 0; temp >>= 1) {
            numBits++;
        }

        int mask = (1 << numBits) - 1;
        return n ^ mask;
    }
};
// @lc code=end

