class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int sum = 0;
        for(int row = m -1; row >= 0; row--) {
            for(int col = n - 1; col >= 0; col--) {
                if(matrix[row][col] == 0) continue;

                int right = col < n - 1 ? matrix[row][col + 1] : 0;
                int down = row < m - 1 ? matrix[row + 1][col] : 0;
                int diag = col < n - 1 && row < m - 1 ? matrix[row + 1][col + 1] : 0;

                int maxSquare = min(right, min(down, diag)) + 1;
                matrix[row][col] = maxSquare;
                sum += maxSquare;
            }
        }

        return sum;
    }
};