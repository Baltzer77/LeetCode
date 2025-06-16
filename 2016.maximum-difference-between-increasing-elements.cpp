/*
 * @lc app=leetcode id=2016 lang=cpp
 *
 * [2016] Maximum Difference Between Increasing Elements
 */

// @lc code=start
class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int n = nums.size();
        vector<int> preMin(n);
        preMin[0] = nums[0];
        for(int i = 1; i < n; i++) {
            preMin[i] = min(preMin[i -1], nums[i]);
        }

        int res = -1;
        for(int i = 0; i < n; i++) {
            if(nums[i] > preMin[i]) {
                res = max(res, nums[i] - preMin[i]);
            }
        }

        return res;
    }
};
// @lc code=end

