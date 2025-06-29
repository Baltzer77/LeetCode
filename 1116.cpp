class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        int sum = 0;
        vector<int> freq(26, 0);

        for(char c : chars) {
            freq[c - 'a']++;
        }

        for(int wordIndex = 0; wordIndex < words.size(); wordIndex++) {
            vector<int> freqCopy = freq;

            string word = words[wordIndex];
            bool good = true;
            for(char c : word) {
                if(--freqCopy[c - 'a'] < 0) {
                    good = false;
                    break;
                }
            }

            if(good) {
                cout << word.size();
                sum += word.size();
            }
        }

        return sum;
    }
};