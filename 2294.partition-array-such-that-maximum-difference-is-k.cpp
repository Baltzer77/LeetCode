/*
 * @lc app=leetcode id=2294 lang=cpp
 *
 * [2294] Partition Array Such That Maximum Difference Is K
 */

// @lc code=start
class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        int res = 1;

        sort(nums.begin(), nums.end());
        int left = nums[0];
        int n = nums.size();
        for(int i = 1; i < n; i++) {
            int right = nums[i];

            if(right - left > k) {
                left = right;
                res++;
            }
        }

        return res;
    }
};
// @lc code=end

