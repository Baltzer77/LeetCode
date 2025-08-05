class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = fruits.size(), ans = n;

        for(int j = 0; j < n; j++) {
            for(int i = 0; i < n; i++) {
                if(baskets[i] >= fruits[j]) {
                    baskets[i] = 0;
                    ans--;
                    break;
                }
            }
        }

        return ans;
    }
};