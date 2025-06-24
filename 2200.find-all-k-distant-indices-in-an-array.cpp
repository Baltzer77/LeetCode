/*
 * @lc app=leetcode id=2200 lang=cpp
 *
 * [2200] Find All K-Distant Indices in an Array
 */

// @lc code=start
class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        vector<int> res;
        int n = nums.size();

        for(int i = 0; i < n; i++) {
            if(nums[i] == key) {
                int j = 0;
                if(res.size() != 0 && res[res.size() - 1] >= i - k)
                {
                    j = res[res.size() - 1] + 1;
                }
                else {
                    j = max(0, i - k);
                }

                while(j <= i + k && j < n) {
                    res.push_back(j++);
                }
            }
        }

        return res;

    }
};
// @lc code=end

