/*
 * @lc app=leetcode id=11 lang=cpp
 *
 * [11] Container With Most Water
 */

// @lc code=start
class Solution {
public:
    int maxArea(vector<int>& heights) {
        int maxArea = 0;
        int left = 0;
        int right = heights.size() -1;

        while(left < right) {
            int length = right - left;
            int height = 0;

            if(heights[left] <= heights[right]) {
                height = heights[left];
                left++;
            }else {
                height = heights[right];
                right--;
            }

            int size = length * height;

            maxArea = max(maxArea, size);


        }

        return maxArea;
    }
};
// @lc code=end

