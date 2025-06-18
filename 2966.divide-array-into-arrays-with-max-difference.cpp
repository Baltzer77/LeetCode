/*
 * @lc app=leetcode id=2966 lang=cpp
 *
 * [2966] Divide Array Into Arrays With Max Difference
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        int n = nums.size();
        for(int i = 0; i < n; i += 3) {
            res.push_back({nums[i], nums[i + 1], nums[i + 2]});

            if(nums[i + 2] - nums[i] > k) {
                return {};
            }
        }

        return res;
    }
};
// @lc code=end

