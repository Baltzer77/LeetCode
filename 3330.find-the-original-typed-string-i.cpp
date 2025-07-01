class Solution {
public:
    int possibleStringCount(string word) {
        int result = 1;
        int start = 0;

        for(int i = 0; i < word.size(); i++) {
            while(i < word.size() && word[start] == word[i]) ++i;
            result += i - start - 1;
            start = i;
        }

        return result;
    }
};