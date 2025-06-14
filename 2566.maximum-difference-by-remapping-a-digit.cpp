/*
 * @lc app=leetcode id=2566 lang=cpp
 *
 * [2566] Maximum Difference by Remapping a Digit
 */

// @lc code=start
class Solution {
public:
    int minMaxDifference(int num) {
        string numAsString = to_string(num);
        string largestString = numAsString;
        string smallestString = numAsString;

        char toChange = numAsString[0];
        for(int i = 0; i < numAsString.size(); i++) {
            if(numAsString[i] == toChange) {
                smallestString[i] = '0';
            }
        }

        toChange = '9';
        for(int i = 0; i < numAsString.size(); i++) {
            if(toChange == '9') {
                toChange = numAsString[i];
            }

            if(numAsString[i] == toChange) {
                largestString[i] = '9';
            }
        }

        return stoi(largestString) - stoi(smallestString);
    }
};
// @lc code=end

