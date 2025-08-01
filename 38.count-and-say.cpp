class Solution {
private:
    string RLE(string& str) {
        string result = "";

        for(int i = 0; i < str.size(); i++) {
            int amount = 0;
            char digit = str[i];
            while(i < str.size() && str[i] == digit) {
                i++;
                amount++;
            }
            result += to_string(amount);
            result += digit;
            i--;
        }

        return result;
    }
public:
    string countAndSay(int n) {
        string result = "1";
        
        for(int i = 1; i < n; i++) {
            result = RLE(result);
        }


        return result;
    }
};