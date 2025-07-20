class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.size() < 1) return {-1, -1};

        int left = 0;
        int right = nums.size() - 1;

        int res = -1;
        while(left < right) {
            int mid = (left + right) >> 1;

            if(nums[mid] >= target) {
                right = mid;
            }
            else {
                left = mid + 1;
            }
        }

        if(nums[left] != target) return {-1, -1};

        int resLeft = left;
        right = nums.size() - 1;
        while(left <= right) {
            int mid = (left + right) >> 1;

            if(nums[mid] > target) {
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        } 

        return {resLeft, right};

    }
};