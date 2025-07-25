/*
 * @lc app=leetcode id=3487 lang=cpp
 *
 * [3487] Maximum Unique Subarray Sum After Deletion
 */

// @lc code=start
class Solution {
public:
    int maxSum(vector<int>& nums) {
        unordered_set<int> hash;
        int sum = 0;
        int maxNum = -101;
        for(int num : nums) {
            maxNum = max(num, maxNum);
            if(num >= 0 && !hash.contains(num)) {
                hash.insert(num);
                sum += num;
            }
        }

        return sum == 0 ? maxNum : sum;
    }
};
// @lc code=end

