class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<bool> hash(1001, 0);

        for(int i = 0; i < nums1.size(); i++) {
            hash[nums1[i]] = true;
        }

        vector<int> res;
        for(int i = 0; i < nums2.size(); i++) {
            if(hash[nums2[i]]) {
                res.push_back(nums2[i]);
                hash[nums2[i]] = false;
            }
        }

        return res;
    }
};