class Solution {
public:
    pair<int, int> posOfChar(char a) {
        return {
            (a - 'A') / 6,
            (a - 'A') % 6
        };
    }
    int dist(char a, char b) {
        auto aPos = posOfChar(a);
        auto bPos = posOfChar(b);

        return abs(aPos.first - bPos.first) + abs(aPos.second - bPos.second);
    }
    int minimumDistance(string word) {
        int n = word.size();
        vector<vector<vector<int>>> dp(n + 1,vector<vector<int>>(26, vector<int>(26, 0)));
        // ABEF
        for(int k = 0; k < n; k++) {
            int index = word[k] - 'A';
            for(int i = 0; i < 26; i++) {
                for(int j = 0; j < 26; j++) {
                    dp[k+1][i][j] = 1e8;
                }
            }
            for(int i = 0; i < 26; i++) {
                for(int j = 0; j < 26; j++) {
                    dp[k+1][index][j] = min(dp[k+1][index][j], dp[k][i][j] + dist(i + 'A', word[k])); 
                    dp[k+1][i][index] = min(dp[k+1][i][index], dp[k][i][j] + dist(j + 'A', word[k]));
                }
            }
        }

        int smallest = INT_MAX;
        for(int i = 0; i < 26; i++) {
            for(int j = 0; j < 26; j++) {
                smallest = min(smallest, dp[n][i][j]);
            }
        }

        return smallest;
    }
};