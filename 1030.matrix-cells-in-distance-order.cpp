/*
 * @lc app=leetcode id=1030 lang=cpp
 *
 * [1030] Matrix Cells in Distance Order
 */

// @lc code=start
class Solution {
public:
    struct node {
        int row;
        int col;
        int dir;
    };

    vector<vector<int>> allCellsDistOrder(int rows, int cols, int rCenter, int cCenter) {
        vector<vector<int>> result(rows * cols);
        deque<node> q;
        q.push_back({rCenter, cCenter, -1});
        int index = 0;
        
        while(q.size() > 0) {
            node n = q.front(); q.pop_front();
            result[index++] = {n.row, n.col};
            
            if(n.dir == -1) {
                for(int i = 0; i < 4; i++) {
                    take_step(rows, cols, n.row, n.col, q, i);
                }
            }
            else if(n.dir == 1 || n.dir == 3) { // going up or down
                take_step(rows, cols, n.row, n.col, q, 0);
                take_step(rows, cols, n.row, n.col, q, 2);
                take_step(rows, cols, n.row, n.col, q, n.dir);
            }
            else {
                take_step(rows, cols, n.row, n.col, q, n.dir);
            }
        }
        return result;
    }
    int dir[5] = {-1, 0, 1, 0, -1};

    void take_step(int maxRows, int maxCols, int row, int col, deque<node>& q, int direction) {
        int newRow = row + dir[direction];
        int newCol = col + dir[direction + 1];

        if(newRow < 0 || newCol < 0 || newRow >= maxRows || newCol >= maxCols) return;
        q.push_back({newRow, newCol, direction});
    }
};
// @lc code=end

