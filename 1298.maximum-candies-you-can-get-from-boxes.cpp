/*
 * @lc app=leetcode id=1298 lang=cpp
 *
 * [1298] Maximum Candies You Can Get from Boxes
 */

// @lc code=start
class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        int n = status.size();
        int result = 0;
        deque<int> q;
        bool* ownedBoxes = new bool[n];
        bool* ownedKeys = new bool[n];
        bool* checkedBoxes = new bool[n];
        for(int i = 0; i < n; i++) {
            ownedBoxes[i] = false;
            ownedKeys[i] = false;
            checkedBoxes[i] = false;
        }

        for(int i = 0; i < initialBoxes.size(); i++) {
            int box = initialBoxes[i];
            ownedBoxes[box] = true;
            if(status[box])
                q.push_back(box);
        }
        
        while(q.size() > 0) {
            int box = q.front(); q.pop_front();
            result += candies[box];
            candies[box] = 0;

            if(checkedBoxes[box]) continue;
            checkedBoxes[box] = true;

            for(int innerBoxIndex = 0; innerBoxIndex < containedBoxes[box].size(); innerBoxIndex++) {
                int innerBox = containedBoxes[box][innerBoxIndex]; 
                ownedBoxes[innerBox] = true;
                if(status[innerBox] || ownedKeys[innerBox])
                    q.push_back(innerBox);
            }

            for(int keyIndex = 0; keyIndex < keys[box].size(); keyIndex++) {
                int key = keys[box][keyIndex];
                ownedKeys[key] = true;
                if(ownedBoxes[key])
                    q.push_back(key);
            }
        }

        return result;
        
    }
};
// @lc code=end

