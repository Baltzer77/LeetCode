class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        unordered_map<int64_t, vector<pair<int,int>>> hash{};
        
        int m = grid.size();
        int n = grid[0].size();

        vector<int64_t> horizontalSums(m, 0);
        vector<int64_t> verticalSums(n, 0);

        for(int i = 0; i < m; i++) {
            int64_t rowSum = 0;
            for(int j = 0; j < n; j++) {
                int val = grid[i][j];
                rowSum += val;
                verticalSums[j] += val;
                if(!hash.contains(val)) {
                    hash[val] = vector<pair<int,int>>{};
                }
                hash[val].emplace_back(i,j);
            }
            horizontalSums[i] = rowSum + (i > 0 ? horizontalSums[i - 1] : 0);
        }

        for(int i = 1; i < n; i++) {
            verticalSums[i] += verticalSums[i - 1];            
        }

        int64_t max = horizontalSums[m - 1];
        for(int row = 0; row < m - 1; row++) {
            int64_t sum_under = max - horizontalSums[row];
            int64_t diff = sum_under - horizontalSums[row];
            if(diff == 0) {
                return true;
            }

            if(hash.contains(abs(diff))) {
                vector<pair<int,int>> candidates = hash[abs(diff)];
                for(const auto &[i, j] : candidates) {
                    bool correct_side = (diff > 0 && i > row) || (diff < 0 && i <= row);
                    bool on_border = n == 1 || (row == 0 && i == 0) || (row == m-2 && i == m-1);
                    bool is_corner = (i == row || i == row + 1 || i == 0 || i == m - 1) && (j == 0 || j == n - 1);
                    if (
                        correct_side // is on correct side
                        && 
                        (!on_border || is_corner)
                    ) return true;
                }

            }

        }

        max = verticalSums[n - 1];
        for(int col = 0; col < n - 1; col++) {
            int64_t sum_right = max - verticalSums[col];
            int64_t diff = sum_right - verticalSums[col];
            if(diff == 0) {
                return true;
            }

            if(hash.contains(abs(diff))) {
                vector<pair<int,int>> candidates = hash[abs(diff)];
                for(const auto &[i, j] : candidates) {
                    bool correct_side = (diff > 0 && j > col) || (diff < 0 && j <= col);
                    bool on_border = m == 1 || (col == 0 && j == 0) || (col == n - 2 && j == n - 1);
                    bool is_corner = ( i == 0 || i == m - 1) && (j == col || j == col + 1 || j == 0 || j == n - 1);
                    if (correct_side && (!on_border || is_corner))
                        return true;
                }

            }
        }

        return false;
    }
}
