/*
 * @lc app=leetcode id=3442 lang=cpp
 *
 * [3442] Maximum Difference Between Even and Odd Frequency I
 */

// @lc code=start
class Solution {
public:
    int maxDifference(string s) {
        vector<int> freq(26, 0);

        for(int i = 0; i < s.size(); i++) {
            freq[s[i] - 'a']++;
        }

        int smallestOdd = INT_MAX;
        int smallestEven = INT_MAX;
        int biggestOdd = INT_MIN;
        int biggestEven = INT_MIN;

        for(int i = 0; i < 26; i++) {
            if(freq[i] == 0) continue;

            if((freq[i] & 1) == 1) {
                smallestOdd = min(smallestOdd, freq[i]);
                biggestOdd = max(biggestOdd, freq[i]);
            }
            else
            {
                smallestEven = min(smallestEven, freq[i]);
                biggestEven = max(biggestEven, freq[i]);
            }
        }

        long diff1 = biggestOdd - smallestEven;
        long diff2 = smallestOdd - biggestEven;
        if(diff1 > diff2) {
            return diff1;
        }

        return diff2;
        
    }
};
// @lc code=end

