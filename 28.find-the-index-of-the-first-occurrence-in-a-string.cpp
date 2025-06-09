/*
 * @lc app=leetcode id=28 lang=cpp
 *
 * [28] Find the Index of the First Occurrence in a String
 */

// @lc code=start
class Solution {
public:
    int strStr(string haystack, string needle) {
        if(haystack.size() < needle.size()) {
            return -1;
        }

        int left = 0;
        int right = 0;
        while(left <= haystack.size() &&  right < haystack.size()) {
            if(haystack[right] == needle[right - left] && haystack[left] == needle[0]) {
                right++;
                if(right - left == needle.size()) return left;
            }else
            {
                left++;
                right = left;
            }
        }

        return -1;
    }
};
// @lc code=end

