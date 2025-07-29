class Solution {
private:
    int findBiggestIndex(vector<int>& bitIndexes, int bestOR, int cur, int curIndex) {
        if(bestOR == 0) return curIndex;

        int biggestIndex = 0;
        int index = 0;
        while(bestOR > 0) {
            if((bestOR & 1) == 1) {
                if((cur & 1) == 1) {
                    bitIndexes[index] = curIndex;
                }

                biggestIndex = max(bitIndexes[index], biggestIndex);
            }
            bestOR >>= 1;
            cur >>= 1;
            index++;
        }

        return biggestIndex;


    }

public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        vector<int> bitIndexes(31, nums.size() - 1);

        vector<int> result(nums.size(), 1);
        int bestOR = 0;
        for(int i = nums.size() - 1; i >= 0; i--)  {
            bestOR |= nums[i];

            int biggestIndex = findBiggestIndex(bitIndexes, bestOR, nums[i], i);
            result[i] = biggestIndex - i + 1;        
        }

        return result;
    }
};