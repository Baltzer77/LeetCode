/*
 * @lc app=leetcode id=3403 lang=cpp
 *
 * [3403] Find the Lexicographically Largest String From the Box I
 */

// @lc code=start
class Solution {

private:
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
public:
    string answerString(string word, int numFriends) {
        if (numFriends == 1) return word;
        string largest = lastSubstring(word);

        int maxSize = word.size() - numFriends + 1;

        return largest.substr(0, min(maxSize, (int)largest.size()));
    }
};
// @lc code=end

