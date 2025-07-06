class FindSumPairs {
private:
    unordered_map<int, int> hash;
    vector<int> arr1, arr2;
public:
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        arr1 = nums1;
        arr2 = nums2;

        for(int i = 0; i< nums2.size(); i++) {
            hash[nums2[i]]++;
        }
    }
    
    void add(int index, int val) {

        if(index >= arr2.size()) return;
        hash[arr2[index]]--;
        hash[arr2[index] + val]++;
        arr2[index] += val;
    }
    
    int count(int tot) {
        int sum = 0;

        for(int i = 0; i < arr1.size(); i++) {
            if(hash.contains(tot - arr1[i])) {
                sum += hash[tot - arr1[i]];
            }
        }

        return sum;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */