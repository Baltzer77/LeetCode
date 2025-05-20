/*
 * @lc app=leetcode id=3355 lang=cpp
 *
 * [3355] Zero Array Transformation I
 */

// @lc code=start
class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> d(nums.size() + 1, 0);
        d[0] = nums[0];
        for(int i = 1; i < nums.size(); ++i) {
            d[i] = nums[i] - nums[i -1];
        }

        for(const auto& interval : queries) {
            d[interval[0]] -= 1;
            d[interval[1] + 1] += 1;
        }

        nums[0] = d[0];
        if(nums[0] > 0) return false;
        
        for(int i = 1; i < nums.size(); i++) {
            nums[i] = d[i] + nums[i - 1];
            if(nums[i] > 0) return false;
        }
        return true;
    }
};
// @lc code=end

