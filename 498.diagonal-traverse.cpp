class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {

        vector<int> result;

        int direction = 1;

        int x = 0;
        int y = 0;
        int m = mat.size();
        int n = mat[0].size();

        while(true) {
            if(x >= n || y >= m || y < 0 || x < 0) direction *= -1;

            if(x >= n) {
                x = n - 1;
                y += 2;
            }

            if(y >= m) {
                y = m - 1;
                x += 2;
            }

            if(x < 0) {
                x = 0;
            }

            if(y < 0) {
                y = 0;
            }



            x = max(x, 0);
            y = max(y, 0);
            x = min(x, n - 1);
            y = min(y, m - 1);

            result.push_back(mat[y][x]);

            if(y == m - 1 && x == n - 1) break;

            y -= direction;
            x += direction;

        }

        return result;
    }
};