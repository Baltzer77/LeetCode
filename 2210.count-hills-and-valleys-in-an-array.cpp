class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int n = nums.size() - 1;
        int amount = 0;
        for(int i = 1; i < n; i++) {
            int cur = nums[i];

            int left = i - 1;
            while(left >= 0 && nums[left] == cur) left--;
            if(left < 0) continue;

            int right = i + 1;
            while(right < nums.size() && nums[right] == cur) right++;
            if(right >= nums.size()) break;

            int leftVal = nums[left];
            int rightVal = nums[right];

            if((cur > leftVal && cur > rightVal) 
            || (cur < leftVal && cur < rightVal))
            {
                amount++;
            }            

            i = right - 1;
        }

        return amount;
    }
};