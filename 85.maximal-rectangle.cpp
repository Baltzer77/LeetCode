class Solution {
private:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int best = 0, n = heights.size();
        for(int i = 0; i < n; i++) {
            while(!st.empty() && heights[st.top()] > heights[i]) {
                int top = st.top(); st.pop();
                int previousSmallerElement = st.empty() ? -1 : st.top();
                int width = i - previousSmallerElement - 1;
                best = max(best, width * heights[top]);
            } 

            st.push(i);
        }
        while(!st.empty()) {
            int top = st.top(); st.pop();
            int previousSmallerElement = st.empty() ? -1 : st.top();
            int width = n - previousSmallerElement - 1;
            best = max(best, width * heights[top]);
        }

        return best;
    }
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int best = 0;
        int m = matrix.size();
        int n = matrix[0].size();

        vector<int> curRow(n, 0);
        for(int row = 0; row < m; row++) {
            for(int col = 0; col < n; col++) {
                if(matrix[row][col] == '0') {
                    curRow[col] = 0;
                }
                else{
                    curRow[col]++;
                }
            }

            // We now have a correct row time to calculate max rectangle in row.
            best = max(best, largestRectangleArea(curRow));
        }


        return best;
    }
};