/*
 * @lc app=leetcode id=909 lang=cpp
 *
 * [909] Snakes and Ladders
 */

// @lc code=start
class Solution {
public:

    struct Node {
        int label;
        int dist;

    };

    pair<int,int> convertLabelToIndex(int label, int n) {
        label--;
        int row = label / n;
        int col = label % n;
        col = (row & 1) == 1 ? n - col - 1 : col;   
        return {n - row - 1, col}; // ughhh it was topdown
    }

    int convertIndexToLabel(int n,int row, int col) {
        return row * n + ((row & 1) == 1 ? n - col : col) + 1;
    }


    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        int nsqr = n * n;
        deque<Node> q;
        q.push_back({1, 0});
        bool* visited = new bool[nsqr + 1];
        for(int i = 0; i < nsqr + 1; i++)
            visited[i] = false;
        int result = INT_MAX;

        while(q.size() > 0) {
            Node p = q.front(); q.pop_front();

            cout << "Reached: " << p.label << " in: " << p.dist << endl;

            if(p.label == nsqr) {
                if(p.dist < result) {
                    result = p.dist;
                }
            }

            for(int i = 1; i <= 6; i++) {
                int newLabel = p.label + i;
                if(newLabel > nsqr) continue;
                pair<int,int> pos = convertLabelToIndex(newLabel, n);
                int boardVal = board[pos.first][pos.second];
                if(boardVal == -1) {
                    if(visited[newLabel]) continue;
                    visited[newLabel] = true;
                    q.push_back({newLabel, p.dist + 1});
                }
                else
                {
                    if(visited[boardVal]) continue;
                    visited[boardVal] = true;
                    q.push_back({boardVal, p.dist + 1});
                }
            }
        }

        return result == INT_MAX ? -1 : result;
    }
};
// @lc code=end

