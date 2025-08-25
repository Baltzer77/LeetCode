class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int minX = INT_MAX, minY = INT_MAX, maxX = INT_MIN, maxY = INT_MIN;
        int m = grid.size();
        int n = grid[0].size();

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 0) continue;

                minX = min(j, minX);
                minY = min(i, minY);
                maxX = max(j, maxX);
                maxY = max(i, maxY);
            }
        }

        return (maxY - minY + 1) * (maxX - minX + 1);
    }
};