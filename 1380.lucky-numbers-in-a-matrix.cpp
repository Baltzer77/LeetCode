class Solution {
public:
    vector<int> luckyNumbers(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<int> minRow(m, INT_MAX);
        vector<int> maxCol(n, 0);

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                minRow[i] = min(minRow[i], matrix[i][j]);
                maxCol[j] = max(maxCol[j], matrix[i][j]);
            }
        }

        vector<int> res;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(minRow[i] == matrix[i][j] && maxCol[j] == matrix[i][j]) res.push_back(matrix[i][j]);
            }
        }

        return res;
    } 
};