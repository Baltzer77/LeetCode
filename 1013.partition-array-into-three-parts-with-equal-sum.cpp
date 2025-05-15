class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& arr) {
        int sum = 0;
        for (int num : arr) {
            sum += num;
        } 
        if (sum % 3 != 0) return false;
        

        int target = sum / 3;
        int i = 0;

        int cur_sum = 0;
        int it = 0;
        while (it < 2) {
            cur_sum = 0;
            for(; i < arr.size(); i++) {
                cur_sum += arr[i];
                if(cur_sum == target) break;
            }
            i++;

            if(i == arr.size()) return false;
            it++;
        }
        
        cur_sum = 0;
        for(; i < arr.size(); i++) {
            cur_sum += arr[i];
        }

        return cur_sum == target;


    }
};
