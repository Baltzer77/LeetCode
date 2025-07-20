/*
 * @lc app=leetcode id=15 lang=cpp
 *
 * [15] 3Sum
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> res;
        
        for(int x = 0; x < nums.size()- 2; ++x) {
            if(x > 0 && nums[x-1] == nums[x]) continue;

            int y = x +1;
            int z = nums.size() - 1;

            while(y < z) {
                int sum = nums[x] + nums[y] + nums[z];
                if(sum < 0) {
                    ++y;
                }
                else if(sum > 0) {
                    --z;
                }
                else {
                    res.push_back({nums[x], nums[y], nums[z]});
                    
                    while(y < z && nums[y++] == nums[y]) {}
                    while(y < z && nums[z--] == nums[z]) {}
                }
            }
        } 

        return res;
    }
};
// @lc code=end

