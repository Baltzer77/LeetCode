class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        unordered_map<int,int> freq1, freq2;
        int n = basket1.size();
        int smallest = INT_MAX;
        for(int i = 0; i < n; ++i) {
            ++freq1[basket1[i]];
            ++freq2[basket2[i]];

            int small = min(basket1[i], basket2[i]);
            smallest = min(smallest, small);
        }


        vector<int> excess1;
        for(auto it : freq1) {
            int sum = freq2[it.first] + it.second;
            if((sum & 1) == 1) return -1;

            for(int i = it.second; i > sum/2; i--) {
                excess1.push_back(it.first);
            }
        }

        vector<int> excess2;
        for(auto it : freq2) {
            int sum = freq1[it.first] + it.second;

            if((sum & 1) == 1) return -1;
            for(int i = it.second; i > sum/2; i--) {
                excess2.push_back(it.first);
            }
        }

        sort(excess1.begin(), excess1.end());
        sort(excess2.begin(), excess2.end());

        n = excess1.size();
        int smallestCost = smallest * 2;
        long long result = 0;
        for(int i = 0; i < n; i++) {
            result += min(smallestCost, min(excess1[i], excess2[n - i  - 1]));
        }

        return result;
    }
};