class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if(n <= 2) return 0;
        int left = 0, right = 0, result = 0;

        for(; right < n; right++) {
            if(height[right] >= height[left]) {
                int index = left + 1;
                while(index < right) {
                    result += height[left] - height[index];
                    index++;
                }
                left = right;
            }
        }

        right = n - 1;
        for(left = n - 1; left >= 0; left--) {
            if(height[left] > height[right]) {
                int index = right - 1;

                while(index > left) {
                    result += height[right] - height[index];
                    index--;
                }
                right = left;
            }
        }

        return result;

    }
};