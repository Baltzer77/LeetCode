/*
 * @lc app=leetcode id=3170 lang=cpp
 *
 * [3170] Lexicographically Minimum String After Removing Stars
 */

// @lc code=start
class Solution {
public:
    string clearStars(string s) {
        vector<deque<int>> hash(26, deque<int>());
        int sz = s.size();
        unordered_set<int> indexesToRemove;

        for(int i = 0; i < sz; i++) {
            if(s[i] == '*') {
                indexesToRemove.insert(i);
                for(int c = 0; c < 26; c++) {
                    if(hash[c].size() > 0) {
                        indexesToRemove.insert(hash[c].front());
                        hash[c].pop_front();


                        break;
                    }
                }
            }
            else {
                hash[s[i] - 'a'].push_front(i);
            }
        }

        string result;
        for(int i = 0; i < sz; i++) {
            if(indexesToRemove.contains(i)) continue;
            result += s[i];
        }

        return result;
    }
};
// @lc code=end

