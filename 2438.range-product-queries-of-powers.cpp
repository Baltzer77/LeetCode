class Solution {
    private:
    static constexpr int mod = 1000000007;
public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<int> powers{0};
        int power = 0;
        while(n > 0) {
            if((n & 1) == 1) powers.push_back(power + powers[powers.size() - 1]);
            
            n >>= 1;
            ++power;
        }

        vector<int> result;
        for(const vector<int>& query : queries) {
            long long product = 1;

            int left = query[0];
            int right = query[1];

            int sum = powers[right + 1] - powers[left];

            while(sum > 30) {
                sum -= 30;
                product = (product << 30) % mod;
            }

            product = (product << sum) % mod;
            

            result.push_back(product);
        }

        return result;
    }
};