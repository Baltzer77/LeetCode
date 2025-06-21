/*
 * @lc app=leetcode id=3085 lang=cpp
 *
 * [3085] Minimum Deletions to Make String K-Special
 */

// @lc code=start
class Solution {
public:
    int minimumDeletions(string word, int k) {
        vector<int> freq(26, 0);
        
        for(char c : word) {
            freq[c - 'a']++;
        }

        int smallest = INT_MAX;
        for(int i = 0; i < 26; i++) {
            if(freq[i] != 0 && freq[i] < smallest) smallest = freq[i];
        }
        int res = word.size();

        for(int i = 0; i < 26; i++) {
            if(freq[i] == 0) continue;

            int temp = 0;
            for(int j = 0; j < 26; j++) {
                if(freq[j] == 0) continue;
            
                if(freq[j] < freq[i])
                    temp += freq[j];
                else 
                    temp += max(0, freq[j] - freq[i] - k);
            }
            res = min(res, temp);
            
        }

        return res;

    }
};
// @lc code=end

