class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        unordered_map<string, int> freq;

        for(const auto& word : words) {
            freq[word]++;
        }

        int k = words[0].size();
        int n = s.size();
        int completeSize = words.size() * k;
        vector<int> result;

        for(int offset = 0; offset < k; offset++) {
            unordered_map<string,int> localFreq;
            int left = offset;
            int right = offset;
                
            while(right < n) {
                string word = s.substr(right, k);

                if(!freq.contains(word)) {

                    while(left < right) {
                        string innerWord = s.substr(left, k);
                        localFreq[innerWord]--;
                        left += k;
                    }

                    left += k;
                    right = left;
                    continue;
                }
                else if(freq[word] == localFreq[word]) {
                    while(left < right) {
                        string innerWord = s.substr(left, k);
                        localFreq[innerWord]--;
                        left += k;
                        if(innerWord == word) {
                            break; 
                        }
                    }
                }

                localFreq[word]++;
                right += k;

                if(right - left == completeSize) result.push_back(left);
            }
            
        }
        

        return result;
    }
};