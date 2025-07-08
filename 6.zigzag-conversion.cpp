class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1) return s;

        string result;
        vector<string> lines(numRows, "");
        int curRow = 0;
        int direction = 1;
        for(int i = 0; i < s.size(); i++) {
            lines[curRow] += s[i];

            curRow += direction;
            if(curRow == numRows -1 || curRow == 0) {
                direction *= -1;
            }
        }

        for(int i = 0; i < numRows; i++) {
            result += lines[i];
        }

        return result;
    }
};