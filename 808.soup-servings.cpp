class Solution {
public:
    double soupServings(int n) {
        if(n >= 4450) return 1.0;

        n = (n + 24) / 25;

        vector<vector<double>> memo(n + 1, vector<double>(n + 1, -1.0));        
        return dfs(n, n, memo);
    }

    double dfs(int a, int b, vector<vector<double>>& memo) {
        if(a <= 0 && b <= 0) return 0.5;
        if(a <= 0) return 1.0;
        if(b <= 0) return 0.0;
        if(memo[a][b] != -1.0) return memo[a][b];

        double res = 0.25 * (
            dfs(a - 4, b, memo) +
            dfs(a - 3, b - 1, memo) +
            dfs(a - 2, b - 2, memo) +
            dfs(a - 1, b - 3, memo)
        );

        memo[a][b] = res;
        return res;
    }
};