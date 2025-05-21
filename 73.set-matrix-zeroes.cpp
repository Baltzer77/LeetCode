/*
 * @lc app=leetcode id=73 lang=cpp
 *
 * [73] Set Matrix Zeroes
 */

// @lc code=start
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {

        bool first_col = false;
        for(int row = 0; row < matrix.size(); row++) {
            if(matrix[row][0] == 0) {
                first_col = true; 
                break;
            } 
        }

        bool first_row = false;
        for(int col = 0; col < matrix[0].size(); col++) {
            if(matrix[0][col] == 0) {
                first_row = true; 
                break;
            } 
        }
            

        for(int row = 1; row < matrix.size(); row++) {
            for(int col = 1; col < matrix[0].size(); col++) {
                if(matrix[row][col] == 0) {
                    matrix[row][0] = 0;
                    matrix[0][col] = 0;
                }
            }
        }

        for(int row = 1; row < matrix.size(); row++) {
            for(int col = 1; col < matrix[0].size(); col++) {
                if(matrix[row][0] == 0 || matrix[0][col] == 0) 
                    matrix[row][col] = 0;
            }
        }

        if(first_col) {
            for(int row = 0; row < matrix.size(); row++)      
                matrix[row][0] = 0;
        }
        if(first_row) {
            for(int col = 0; col < matrix[0].size(); col++)      
                matrix[0][col] = 0;
        }
    }
};
// @lc code=end

