class Solution {
private:
    vector<vector<int>> result;
    vector<int> current;

    void dfs(int i, int n, int k) {
        if(k == 0) {
            result.push_back(current);
            return;
        }

        for(; i < n - k + 1; i++) {
            current.push_back(i + 1);
            dfs(i + 1, n, k - 1);
            current.pop_back();
        }
    }

public:
    vector<vector<int>> combine(int n, int k) {
        dfs(0, n, k);

        return result;
    }
};