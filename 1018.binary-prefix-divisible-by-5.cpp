/*
 * @lc app=leetcode id=1018 lang=cpp
 *
 * [1018] Binary Prefix Divisible By 5
 */

// @lc code=start
class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        vector<bool> result(nums.size());
        int last_digit = 0;
        for(int i = 0; i < nums.size(); i++) {
            last_digit = (last_digit * 2 + nums[i]) % 10;    
            result[i] = last_digit % 5 == 0;
        }
       return result;
    }
};
// @lc code=end

