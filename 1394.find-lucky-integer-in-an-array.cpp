/*
 * @lc app=leetcode id=1394 lang=cpp
 *
 * [1394] Find Lucky Integer in an Array
 */

// @lc code=start
class Solution {
public:
    int findLucky(vector<int>& arr) {
        vector<int> freq(501, 0);
        int n = arr.size();
        for(int i = 0; i < n; i++) {
            freq[arr[i]]++;
        }
        
        for(int i = 500; i >= 1; i--) {
            if(freq[i] == i) return i;
        }

        return -1;
    }
};
// @lc code=end

