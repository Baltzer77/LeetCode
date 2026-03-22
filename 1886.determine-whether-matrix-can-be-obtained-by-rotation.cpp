class Solution {
public:
    bool checkEquals(vector<vector<int>>& mat, vector<vector<int>>& target) {
        int n = mat.size();
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if (mat[i][j] != target[i][j]) return false;
            }    
        }

        return true;
    }

    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        if (checkEquals(mat, target)) return true;

        int n = mat.size();

        for(int rot = 0; rot < 3; rot++) {
            for(int i = 0; i < n; i++) {
                for(int j = 0; j <= i; j++) {
                    swap(mat[i][j], mat[j][i]);
                }    
            }

            for(int row = 0; row < n; row++) {
                reverse(mat[row].begin(), mat[row].end());
            }

            if (checkEquals(mat, target)) return true;
        }

        return false;
    }
};
