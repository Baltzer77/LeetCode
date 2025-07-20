class Solution {
public:
    int myAtoi(string s) {
        bool isNegative = false;
        int index = 0;
        // first find the start of the number
        for(; index < s.size(); index++) {
            if(s[index] >= '0' && s[index] <= '9') { 
                break;
            }

            if(s[index] == '-' || s[index] == '+') {
                isNegative = s[index] == '-';
                index++;
                break;
            }

            if(s[index] != ' ') return 0;
        }

        long long result = 0;
        
        for(; index < s.size(); index++) {
            if(s[index] < '0' || s[index] > '9') {
                return static_cast<int>(result);
            }

            int digit = s[index] - '0';
            result *= 10;
            result += isNegative ? -digit : digit;
            
            if(result > INT_MAX) return INT_MAX;
            if(result < INT_MIN) return INT_MIN;
        }

        return static_cast<int>(result);
    }
};