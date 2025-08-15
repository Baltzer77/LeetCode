class Solution {
private:
    vector<vector<int>> grid;
    vector<vector<string>> result;
    vector<string> current;
    int n;

    void changeGrid(int y, int x, int amount) {
        int startVal = grid[y][x];
        for(int i = 0; i < n; i++) {
            grid[y][i] += amount;
            grid[i][x] += amount;

            int up = y - i;
            int down = y + i;

            int right = x + i;
            int left = x - i;

            if(up >= 0 && right < n) grid[up][right] += amount;
            if(up >= 0 && left >= 0) grid[up][left] += amount;
            if(down < n && right < n) grid[down][right] += amount;
            if(down < n && left >= 0) grid[down][left] += amount;
        }
        grid[y][x] = startVal + amount;
    }

    void dfs(int row) {
        if(row >= n) {
            vector<string> res = current;
            result.push_back(res);            
            return;
        }

        for(int x = 0; x < n; x++) {
            if(grid[row][x] > 0) continue;
            
            changeGrid(row, x, 1);
            current[row][x] = 'Q';
            dfs(row + 1);
            changeGrid(row, x, -1);
            current[row][x] = '.';
        }
    }
public:
    vector<vector<string>> solveNQueens(int size) {
        n = size;
        grid.resize(n, vector<int>(n, 0));
        current.resize(n, string(n, '.'));

        dfs(0);
        return result;
    }
};