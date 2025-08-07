class Solution {
private:
    int getStartIndex(int i, int n) {
        return max(n - 1 - i, i + 1);
    }
public:
    int maxCollectedFruits(vector<vector<int>>& fruits) {
        int topLeft = 0;
        int n = fruits.size();
        for(int i = 0; i < n; i++) {
            topLeft += fruits[i][i];
        }

        // going from top right
        for(int i = 1; i < n - 1; i++) {
            for(int j = getStartIndex(i, n); j < n; j++) {
                int prevStartIndex = getStartIndex(i - 1, n);

                int left = (j - 1 >= prevStartIndex) ? fruits[i - 1][j - 1] : 0;
                int middle = (j >= prevStartIndex) ? fruits[i - 1][j] : 0;
                int right = (j + 1 >= prevStartIndex && j + 1 < n) ? fruits[i - 1][j + 1] : 0;
                fruits[i][j] += max(left, max(right, middle)); 
            }
        } 
        int topRight = fruits[n - 2][n - 1];


        // going from bottom left
        for(int j = 1; j < n - 1; j++) {
            for(int i = getStartIndex(j, n); i < n; i++) {
                int prevStartIndex = getStartIndex(j - 1, n);

                int left = (i - 1 >= prevStartIndex) ? fruits[i - 1][j - 1] : 0;
                int middle = (i >= prevStartIndex) ? fruits[i][j - 1] : 0;
                int right = (i + 1 >= prevStartIndex && i + 1 < n) ? fruits[i + 1][j - 1] : 0;
                fruits[i][j] += max(left, max(right, middle)); 
            }
        }

        int bottomLeft = fruits[n- 1][n- 2];
        
        return  topLeft + topRight + bottomLeft;
    }
};