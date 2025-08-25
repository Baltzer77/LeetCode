class Solution {
    vector<int> current;
    vector<vector<int>> result;
    int n;
    void dfs(int i, vector<int>& nums) {
        result.push_back(current);

        for(int j = i + 1; j < n; j++) {
            current.push_back(nums[j]);
            dfs(j, nums);
            current.pop_back();
        }
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        n = nums.size();
    
        dfs(-1, nums);

        return result;
    }
};