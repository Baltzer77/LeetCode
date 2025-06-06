/*
 * @lc app=leetcode id=2434 lang=cpp
 *
 * [2434] Using a Robot to Print the Lexicographically Smallest String
 */

// @lc code=start
class Solution {
public:
    string robotWithString(string s) {
        vector<vector<int>> charIndexes(26, vector<int>{});
        for(int i = 0; i < s.size(); i++) {
            charIndexes[s[i] - 'a'].push_back(i);
        }
        string result;
        int totalIndex = 0;
        deque<char> stack;



        for(int i = 0; i < 26; i++) {
            while(stack.size() > 0 && stack.front() <= 'a' + i) {
                result += stack.front();
                stack.pop_front();
            }

            if(totalIndex >= s.size()) break;


            vector<int> indexes = charIndexes[i];
            for(int index : indexes) {
                if(totalIndex > index) continue;

                while(totalIndex < index) {
                    stack.push_front(s[totalIndex++]);
                }
                result += 'a' + i;
                totalIndex = index + 1;
            }
        }

        while(stack.size() > 0) {
            result += stack.front(); stack.pop_front();
        }

        return result;
    }
};
// @lc code=end

