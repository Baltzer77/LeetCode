/*
 * @lc app=leetcode id=2138 lang=cpp
 *
 * [2138] Divide a String Into Groups of Size k
 */

// @lc code=start
class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> res;
        int sz = s.size();
        for(int i = 0; i < sz; ) {
            string temp;
            for(int j = 0; j + i <sz && j < k; j++) {
                temp += s[i + j];
            }
            i += k;

            res.push_back(temp);
        }

        while(res[res.size() - 1].size() < k) {
            res[res.size() - 1] += fill;
        }

        return res;
    }
};
// @lc code=end

