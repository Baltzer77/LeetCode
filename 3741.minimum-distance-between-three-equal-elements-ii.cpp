class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int, vector<int>> hash{};
        for(int i = 0; i < nums.size(); i++) {
            if(!hash.contains(nums[i])) {
                hash[nums[i]] = vector<int>();
            }
            hash[nums[i]].emplace_back(i);
        }

        int smallest = INT_MAX;
        for (const auto& [k,indices] : hash) {
            if(indices.size() < 3) continue;
            for(int p = 0, q = 1, r = 2; r < indices.size();) {
                smallest = min(smallest, indices[q]-indices[p] + indices[r]-indices[p] + indices[r]-indices[q]);
                p++; q++; r++;
            }
        }

        return smallest == INT_MAX ? -1 : smallest;
    }
};