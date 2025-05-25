/*
 * @lc app=leetcode id=2131 lang=cpp
 *
 * [2131] Longest Palindrome by Concatenating Two Letter Words
 */

// @lc code=start
class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string, int> hash;

        for(int i = 0; i < words.size(); i++) {
            hash[words[i]]++;
        }

        int center = 0;
        int result = 0;

        for(const auto& pair : hash) {
            string word = pair.first;
            string reversed{word[1], word[0]};
            int count = pair.second;

            if(word == reversed) {
                center = center | (count & 1);
                result += (count >> 1) << 1;
            }
            else if(hash.contains(reversed)) {
                result += min(count, hash[reversed]) << 1;
                hash[reversed] = 0;
            }
        }

        return (result + center) << 1;
    }
};
// @lc code=end

