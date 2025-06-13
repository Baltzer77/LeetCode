/*
 * @lc app=leetcode id=2616 lang=cpp
 *
 * [2616] Minimize the Maximum Difference of Pairs
 */

// @lc code=start
class Solution {
public:
    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int left = 0;
        int right = nums[n - 1] - nums[0];

        while(left < right){
            int pairs = 0;
            int mid = ((right + left) >> 1);
            for(int i = 0; i < n - 1; ++i) {
                if(nums[i + 1] - nums[i] <= mid) {
                    ++pairs;
                    ++i;
                }
            }

            if(pairs >= p) {
                right = mid;
            }
            else {
                left = mid + 1;
            }
        }

        return left;
    }
};
// @lc code=end

