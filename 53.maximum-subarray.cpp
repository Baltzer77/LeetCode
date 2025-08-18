class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int maxEnding = nums[0];
        int result = nums[0];

        for(int i = 1; i < nums.size(); i++) {
            maxEnding = max(nums[i], maxEnding + nums[i]);

            result = max(result, maxEnding);
        }

        return result;
    }
};