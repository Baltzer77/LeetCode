/*
 * @lc app=leetcode id=3423 lang=cpp
 *
 * [3423] Maximum Difference Between Adjacent Elements in a Circular Array
 */

// @lc code=start
class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int maxDiff = 0;
        int n = nums.size();
        int prev = nums[n - 1];
        for(int i = 0; i < n; i++) {
            int cur = nums[i];
            int diff = abs(prev - cur);
            prev = cur;
            maxDiff = max(maxDiff, diff);
        }

        return maxDiff;
    }
};
// @lc code=end

