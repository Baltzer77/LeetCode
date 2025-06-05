/*
 * @lc app=leetcode id=1061 lang=cpp
 *
 * [1061] Lexicographically Smallest Equivalent String
 */

// @lc code=start
class Solution {
public:
    int dfs(int cur, vector<vector<int8_t>>& map, vector<bool>& seen, vector<int8_t>& scc) {
        scc.push_back(cur);
        seen[cur] = true;
        int smallest = cur;
        for(const int neighbour : map[cur]) {
            if(seen[neighbour]) continue;

            int result = dfs(neighbour, map, seen, scc);
            if(result < smallest) smallest = result;
        }

        return smallest;
    }

    void findBest(vector<vector<int8_t>>& map, vector<char>& result) {
        vector<bool> seen(26, false);

        for(int i = 0; i < 26; i++) {
            if(seen[i]) continue;

            vector<int8_t> scc;
            char smallest = dfs(i, map, seen, scc);
            for(const int8_t index : scc) {
                result[index] = smallest + 'a';
            }
        }

    }

    string smallestEquivalentString(string s1, string s2, string baseStr) {
        vector<vector<int8_t>> map(26, vector<int8_t>{});
        for(int i = 0; i < s1.size(); i++) {
            int8_t index1 = s1[i] - 'a';
            int8_t index2 = s2[i] - 'a';
            map[index1].push_back(index2);
            map[index2].push_back(index1);
        }

        vector<char> best(26, 'z');
        findBest(map, best);

        int sz = baseStr.size();
        for(int i = 0; i < sz; i++) {
            baseStr[i] = best[baseStr[i] - 'a'];
        }
        return baseStr;
    }
};
// @lc code=end

