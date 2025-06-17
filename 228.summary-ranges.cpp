/*
 * @lc app=leetcode id=228 lang=cpp
 *
 * [228] Summary Ranges
 */

// @lc code=start
class Solution {
public:
    string stringify(int a, int b) {
        if(a == b) return to_string(a);
        return to_string(a) + "->" + to_string(b);
    }
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;

        if(nums.size() == 0) return res;

        int start = 0;
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] != nums[start] + (i - start)) {
                res.push_back(stringify(nums[start],nums[i -1]));
                start = i;
            }
        }

        res.push_back(stringify(nums[start], nums[nums.size() - 1]));

        return res;
    }
};
// @lc code=end

