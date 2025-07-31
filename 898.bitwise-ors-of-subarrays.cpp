class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        unordered_set<int> prev {0}, cur{};
        unordered_set<int> result;


        for(int x : arr) {
            for(int y : prev) {
                cur.insert(x | y);
                result.insert(x | y);
            }
            cur.insert(x);
            result.insert(x);
            prev = cur;

            cur.clear();
        }

        return result.size();
    }
};