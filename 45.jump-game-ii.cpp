class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;

        for(int i = 0; i < n; i++) {
            int step = dp[i] + 1;

            int dist = min(i + nums[i], n);

            for(int j = dist; j > i; j--) {
                if(dp[j] <= step) break;
                dp[j] = step;
            }
        }

        return dp[n - 1];
    }
};