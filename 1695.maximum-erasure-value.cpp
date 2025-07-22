/*
 * @lc app=leetcode id=1695 lang=cpp
 *
 * [1695] Maximum Erasure Value
 */

// @lc code=start
class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int res = 0;

        int left = 0;
        int right = 0;
        int curSum = 0;
        unordered_set<int> hash;

        while(right < nums.size()) {
            while(hash.contains(nums[right])) {
                curSum -= nums[left];
                hash.erase(nums[left++]);
            }
            
            curSum += nums[right];
            hash.insert(nums[right]);
            right++;
            res = max(curSum, res);

        }

        return res;
    }
};
// @lc code=end

