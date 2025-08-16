class Solution {
private:
    vector<vector<int>> result;
    vector<int> current;
    int n;
    void permute(int length, vector<int>& nums) {
        if(length == n) {
            result.push_back(current);
            return;
        }

        for(int i = 0; i < n; i++) {
            int val = nums[i];
            if(val != INT_MIN) {
                current.push_back(val);
                
                nums[i] = INT_MIN;
                permute(length + 1, nums);
                nums[i] = val;
                current.pop_back();

                while(i < n - 1 && nums[i] == nums[i + 1]) {
                    i++;
                }
            }
        }
    }

public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        n = nums.size();
        permute(0, nums);

        return result;
    }
};