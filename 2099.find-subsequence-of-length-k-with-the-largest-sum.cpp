/*
 * @lc app=leetcode id=2099 lang=cpp
 *
 * [2099] Find Subsequence of Length K With the Largest Sum
 */

// @lc code=start
class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<int> index(nums.size());
        iota(index.begin(), index.end(), 0);

        stable_sort(index.begin(), index.end(), [&nums](size_t index1, size_t index2) { return nums[index1] < nums[index2];});

        stable_sort(index.end() - k, index.end());

        vector<int> res;
        for(int i = nums.size() - k; i < nums.size(); i++) {
            res.push_back(nums[index[i]]);
        }

        return res;
    }
};
// @lc code=end

