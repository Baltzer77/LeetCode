class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n <= 0) return false;

        int largest = 1162261467;

        return largest % n == 0;
    }
};