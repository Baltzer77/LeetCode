/*
 * @lc app=leetcode id=1163 lang=cpp
 *
 * [1163] Last Substring in Lexicographical Order
 */

// @lc code=start
class Solution {
public:
    string lastSubstring(string s) {
        int n = s.size();
        int i = 0;
        int j = 1;
        int k = 0;
        while(j + k < n) {
            if(s[i + k] == s[j + k]) {
                ++k;
            }else if(s[i + k] > s[j + k]) {
                j = j + k + 1;
                k = 0;
            }
            else {
                i = max(i + k + 1, j);
                j = i + 1;
                k = 0;
            }
        }

        return s.substr(i);
    }
};
// @lc code=end

