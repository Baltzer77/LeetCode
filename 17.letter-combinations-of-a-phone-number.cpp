class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0) return {};

        vector<string> combinations{
            "abc",
            "def",
            "ghi",
            "jkl",
            "mno",
            "pqrs",
            "tuv",
            "wxyz"
        };


        vector<string> result{""};

        for(int digitIndex = digits.size() - 1; digitIndex >= 0; digitIndex--) {
            string combination = combinations[digits[digitIndex] - '2'];
            vector<string> newResult;
            for(char c: combination) {
                for(string word : result) {
                    newResult.push_back(c + word);
                }
            }

            result = newResult;
        }

        return result;

    }
};