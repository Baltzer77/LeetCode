class Solution {
public:
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
};