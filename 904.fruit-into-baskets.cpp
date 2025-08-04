class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int best = 1;
        int left = 0;
        int prevStartOfRight = 0;
        unordered_set<int> baskets;
        for(int right = 1; right < fruits.size(); ++right) {
            while(!baskets.contains(fruits[right])
                    && left < right && left < prevStartOfRight) {
                        left++;
            }

            if(fruits[right - 1] != fruits[right]) {
                baskets = {fruits[right - 1], fruits[right]};
                prevStartOfRight = right;
            }


            best = max(best, right - left + 1);
        }

        return best;
    }
};