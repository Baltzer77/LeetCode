class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long result = 0;
        long long amountBefore = 0;
        int n = nums.size();
        
        for(int i = 0; i < n; ++i) {
            int amountBefore = 0;
            while(i < n && nums[i] == 0) {
                ++amountBefore;
                result += amountBefore;
                ++i;
            }
        }



        return result;
    }
};