/*
 * @lc app=leetcode id=22 lang=cpp
 *
 * [22] Generate Parentheses
 */

// @lc code=start
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        if(n == 1) return {"()"};

        int open = 0;
        int closed = 0;
        
        string cur = "";
        vector<string> result;

        while(cur.size() == 0 || cur[0] != ')') {
            while(open < n) {
                cur += "(";
                open++;
            }
            while(closed < open) {
                cur += ")";
                closed++;
            }
            result.push_back(cur);

            int index = cur.size() - 1;
            bool foundReplacement = false;
            while(index >= 0  && !foundReplacement) {
                char par = cur[index];
                cur = cur.erase(index, 1);
                index--;
                if(par == '(') {
                    open--;
                    if(open > closed) {
                        cur += ")";
                        closed++;
                        foundReplacement = true;
                    }
                }
                else {
                    closed--;
                }

            }

            if(!foundReplacement) break;
        }

        return result;
    }
};
// @lc code=end

