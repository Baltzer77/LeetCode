class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        
        int result = 1;
        int best = -1;

        for(int i = 0; i < n; i++) {

            int cur = nums[i];
            int size = 0;
            while(i < n && cur == nums[i]) {
                ++i;
                ++size;
            }

            if(cur > best) {
                result = size;
                best = cur;
            }
            else if (cur == best) result = max(result, size);  

            --i;
        }

        return result;


        return result;
    }
};