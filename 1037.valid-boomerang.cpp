/*
 * @lc app=leetcode id=1037 lang=cpp
 *
 * [1037] Valid Boomerang
 */

// @lc code=start
class Solution {
public:
    bool isBoomerang(vector<vector<int>>& points) {
        if (points[0] == points[1] || points[0] == points[2] || points[1] == points[2]) return false; 
        int xVector = points[0][0] - points[1][0];
        int yVector = points[0][1] - points[1][1];
        int divider = gcd(xVector, yVector);

        xVector /= divider;
        yVector /=  divider;
        
        int otherXVector = points[0][0] - points[2][0];
        int otherYVector = points[0][1] - points[2][1];
        divider = gcd(otherXVector, otherYVector);

        otherXVector /= divider;
        otherYVector /= divider;
       
        if((xVector == otherXVector && yVector == otherYVector) 
        || (-xVector == otherXVector && -yVector == otherYVector))
            return false;

        return true;
    }
};
// @lc code=end

