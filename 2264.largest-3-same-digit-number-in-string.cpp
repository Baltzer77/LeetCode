class Solution {
public:
    string largestGoodInteger(string num) {
        char largest = 0;
        int n = num.size();

        for(int i = 0; i < n; i++) {
            if(num[i] > largest) {
                int index = i;
                while(index < n && num[index] == num[i]) {
                    ++index;
                }

                if(index - i >= 3) {
                    largest = num[i];
                }
                i = index - 1;
            }
        }

        if(largest == 0) return "";
        return {largest, largest, largest};
    }
};