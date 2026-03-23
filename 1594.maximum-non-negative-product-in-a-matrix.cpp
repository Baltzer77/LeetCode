class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {

        constexpr int MOD = 1000000007;

        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<pair<int64_t,int64_t>>> dp(m, vector<pair<int64_t,int64_t>>(n, {0, 0}));
        dp[0][0] = {grid[0][0], grid[0][0]};
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if (i == 0 && j == 0) continue;
                auto [up_min, up_max] = i > 0 ? dp[i-1][j] : dp[i][j - 1];
                auto [left_min, left_max] = j > 0 ? dp[i][j-1] : dp[i -1][j];
                int64_t grid_val = grid[i][j];

                int64_t val_up_min = up_min * grid_val;
                int64_t val_up_max = up_max * grid_val;
                int64_t val_left_min = left_min * grid_val;
                int64_t val_left_max = left_max * grid_val;
                
                int64_t val_min = min(min(val_up_min, val_up_max), min(val_left_min, val_left_max));
                int64_t val_max = max(max(val_up_min, val_up_max), max(val_left_min, val_left_max));
                dp[i][j] = {val_min, val_max};
            }
        }

        auto [min_val, max_val] = dp[m -1][n -1 ];
        if(max_val < 0) return -1;
        return max_val % MOD;
    }
};