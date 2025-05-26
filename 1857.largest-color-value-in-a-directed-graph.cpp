/*
 * @lc app=leetcode id=1857 lang=cpp
 *
 * [1857] Largest Color Value in a Directed Graph
 */

// @lc code=start
class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        vector<int>* edgesMap = new vector<int>[colors.size()];
        for(int i = 0; i < colors.size(); i++) {
            edgesMap[i] = {};
        }

        //populate map
        for(int i = 0; i < edges.size(); i++) {
            edgesMap[edges[i][0]].push_back(edges[i][1]);
        }

        // reverse sorted, the first element is the rightmost topological
        vector<int> sorted;
        sortTopological(sorted, edgesMap, colors.size());

        bool* visited = new bool[colors.size()];
        for(int i = 0; i< colors.size(); i++) {
            visited[i] = false;
        }

        auto dp = new int[colors.size()][26];

        int result = 0;


        for(int i = 0; i < sorted.size(); i++) {

            int curVertex = sorted[i];
            visited[curVertex] = true;

            for(int c = 0; c < 26; c++) {
                dp[curVertex][c] = 0;
            }
            for(int edgeIndex = 0; edgeIndex < edgesMap[curVertex].size(); edgeIndex++){
                int edgeVertex = edgesMap[curVertex][edgeIndex];
                if(!visited[edgeVertex] || edgeVertex == curVertex)
                    return -1; // there is a loop
                
                for(int c = 0; c < 26; c++) {
                    dp[curVertex][c] = max(dp[curVertex][c], dp[edgeVertex][c]);
                }
            }

            int newVal = dp[curVertex][colors[curVertex] - 'a'] + 1;

            dp[curVertex][colors[curVertex] - 'a'] = newVal;
            result = max(result, newVal);
        }

        // for(int i = 0; i < sorted.size(); i++) {
        //     for(char c = 'a'; c < 'd'; c++) {
        //         cout << "Vertex: " << i << " has a path where the color " << c << " appears " << dp[i][c - 'a'] << endl;
        //     }
        // } 


        delete[] edgesMap;

        return result;
    }

    void sortTopological(vector<int>& result, vector<int> edges[], int vertexCount) {
        bool* visited = new bool[vertexCount];
        for(int i = 0; i < vertexCount; i++)
            visited[i] = false;
        
        for(int i = 0; i < vertexCount; i++) {
            if(!visited[i]) {
                sortTopologicalDFS(i, result, edges, visited);

            }
        }

        delete[] visited;
    }

    void sortTopologicalDFS(int vertex, vector<int>& result, vector<int> edges[], bool visited[]) {
        visited[vertex] = true;
        int edgeCount = edges[vertex].size();
        for(int i = 0; i < edgeCount; i++) {
            int nextVertex = edges[vertex][i];
            if(!visited[nextVertex])
                sortTopologicalDFS(nextVertex, result, edges, visited);
        }

        result.push_back(vertex);
    }
};
// @lc code=end










