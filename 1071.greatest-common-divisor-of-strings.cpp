/*
 * @lc app=leetcode id=1071 lang=cpp
 *
 * [1071] Greatest Common Divisor of Strings
 */

// @lc code=start
class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        if(str1 + str2 != str2 + str1) return "";

        int gcdSz = gcd(str1.size(), str2.size());
        return str1.substr(0, gcdSz);
    }
};
// @lc code=end

