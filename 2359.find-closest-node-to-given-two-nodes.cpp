/*
 * @lc app=leetcode id=2359 lang=cpp
 *
 * [2359] Find Closest Node to Given Two Nodes
 */

// @lc code=start
class Solution {
public:
    void dfs(int current, int distance, const vector<int>& edges, vector<int>& distances) {
        while(current != -1 && distances[current] == -1) {
            distances[current] = distance++;
            current = edges[current];
        }
    }

    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int res = -1, MinOfMax = INT_MAX, n = edges.size();
        vector<int> dist1(n, -1), dist2(n, -1);
        dfs(node1, 0, edges, dist1);
        dfs(node2, 0, edges, dist2);

        for(int i = 0; i < n; i++) {
            if(dist1[i] >= 0 && dist2[i] >= 0) {
                int maximum = max(dist1[i], dist2[i]);
                if(maximum < MinOfMax) {
                    res = i;
                    MinOfMax = maximum;
                }
            }
        }

        return res;
    }
};
// @lc code=end

