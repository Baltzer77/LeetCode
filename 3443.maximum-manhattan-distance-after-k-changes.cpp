/*
 * @lc app=leetcode id=3443 lang=cpp
 *
 * [3443] Maximum Manhattan Distance After K Changes
 */

// @lc code=start
class Solution {
public:
    vector<unordered_set<char>> quads{{'N','E'}, {'S', 'E'}, {'S', 'W'}, {'N', 'W'}};
    unordered_map<char, int> dirsX{{'N', 0}, {'S', 0}, {'E', 1}, {'W', -1}}; 
    unordered_map<char, int> dirsY{{'N', 1}, {'S', -1}, {'E', 0}, {'W', 0}}; 

    int checkDirection(int i, string& s, int k) {
        int maxDist = 0;
        int x = 0;
        int y = 0;
        for(char c: s) {
            int dirX = dirsX[c];
            int dirY = dirsY[c];
            if(k > 0 && !quads[i].contains(c)) {
                dirX = -dirX;
                dirY = -dirY;
                k--;
            }

            x += dirX;
            y += dirY;

            maxDist = max(maxDist, abs(x) + abs(y));
        }

        return maxDist;
    }

    int maxDistance(string s, int k) {
        int NE = checkDirection(0, s, k);
        int SE = checkDirection(1, s, k);
        int SW = checkDirection(2, s, k);
        int NW = checkDirection(3, s, k);

        return max(max(NE, SE), max(SW, NW));
    }
};
// @lc code=end

