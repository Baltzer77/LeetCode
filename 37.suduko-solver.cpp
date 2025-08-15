class Solution {
private:
    vector<vector<vector<int>>> possible;
    void updatePossible(int y, int x, int val, int amount) {
        
        int quadStartY = (y / 3) *3;
        int quadStartX = (x / 3) *3;

        int startVal = possible[y][x][val - 1];
        for(int i = 0; i < 9; i++) {
            possible[y][i][val - 1] += amount;
            possible[i][x][val - 1] += amount;
            
            possible[quadStartY + i / 3][quadStartX + i % 3][val - 1] += amount;
        }

        possible[y][x][val - 1] = startVal + amount;
    }

    bool dfs(vector<vector<char>>& board, int y, int x) {
        while(y < 9) {
            while(x < 9) {
                if(board[y][x] == '.') {
                    for(int val = 1; val <= 9; val++) {
                        if(possible[y][x][val - 1] <= 0) {
                            board[y][x] = '0' + val;
                            updatePossible(y, x, val, 1);
                            if(dfs(board, y, x)) {
                                return true;
                            }

                            updatePossible(y,x, val, -1);
                            board[y][x] = '.';
                        }
                    }
                    return false;
                }
                x++;
            }
            x = 0;
            y++;
        }

        return true;
    }
public:
    void solveSudoku(vector<vector<char>>& board) {
        possible.resize(9, vector<vector<int>>(9, vector<int>(9, 0)));

        for(int y = 0; y < 9; y++) {
            for(int x = 0; x < 9; x++) {
                if(board[y][x] == '.') continue;

                updatePossible(y, x, board[y][x] - '0', 1);
            }
        }

        dfs(board, 0, 0);
    }
};