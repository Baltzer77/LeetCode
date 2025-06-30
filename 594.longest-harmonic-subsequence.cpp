class Solution {
public:
    int findLHS(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int res = 0;
        int prev = 0;
        for(int i = 0; i < nums.size(); i++) {
            while(prev < i && nums[i] - nums[prev] > 1) prev++;
            if(nums[prev] != nums[i])
                res = max(res, i - prev + 1);
        }

        return res;
    }
};