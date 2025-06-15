/*
 * @lc app=leetcode id=1432 lang=cpp
 *
 * [1432] Max Difference You Can Get From Changing an Integer
 */

// @lc code=start
class Solution {
public:
    int maxDiff(int num) {
        string numAsString = to_string(num);
        string largest = numAsString;
        string smallest = numAsString;
        int n = numAsString.size();

        //largest
        char toChange = '9';
        for(int i = 0; i < n; i++) {
            if(toChange == '9') {
                toChange = numAsString[i];
            }

            if(numAsString[i] == toChange) {
                largest[i] = '9';
            }
        }

        // smallest
        toChange = numAsString[0];
        // if first isn't 1 we change all its occurences to 1.
        // otherwise change first non-1 to 0
        if(toChange != '1') {
            for(int i = 0; i < n; i++) {
                if(numAsString[i] == toChange) smallest[i] = '1';
            }
        }
        else {
            toChange = '0';
            for(int i = 0; i < n; i++) {
                if(toChange == '0' && numAsString[i] != '1') {
                    toChange = numAsString[i];
                }

                if(numAsString[i] == toChange) {
                    smallest[i] = '0';
                }
            }
        }

        return stoi(largest) - stoi(smallest);

    }
};
// @lc code=end

