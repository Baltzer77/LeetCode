class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> grid(n, vector<int>(n, 0));
        int dir[]{-1, 0, 1, 0, -1};

        int curDirection = 1;

        int x = 0, y = 0;
        int index = 1;
        while(true) {
            grid[y][x] = index++;

            int nextY = y + dir[curDirection];
            int nextX = x + dir[curDirection + 1];

            if(nextY < 0 || nextX < 0 || nextX == n || nextY == n || grid[nextY][nextX] != 0) {
                curDirection = (curDirection + 1) % 4;

                nextY = y + dir[curDirection];
                nextX = x + dir[curDirection + 1];
            
                if(nextY < 0 || nextX < 0 || nextX == n || nextY == n || grid[nextY][nextX] != 0)
                    break;
            }

            y = nextY;
            x = nextX;
        }

        return grid;
    }
};