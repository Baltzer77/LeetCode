/*
 * @lc app=leetcode id=1021 lang=cpp
 *
 * [1021] Remove Outermost Parentheses
 */

// @lc code=start
class Solution {
public:
    string removeOuterParentheses(string s) {
        string result{};

        for(int i = 0; i < s.size(); i++){
            int leftCount = 1;
            int rightCount = 0;
            
            int lefti = i;
            while(leftCount > rightCount) {
                if(s[++i] == '(') {
                    ++leftCount;
                }
                else {
                    ++rightCount;
                }
            }
            result += s.substr(lefti + 1, i - lefti - 1);          
        }

        return result;
    }
};
// @lc code=end

