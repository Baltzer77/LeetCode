class Solution {
public:
    int maximum69Number (int num) {
        string numAsString = to_string(num);

        for(int i = 0; i < numAsString.size(); i++) {
            if(numAsString[i] == '6') {
                numAsString[i] = '9';
                break;
            }
        }

        return stoi(numAsString);
    }
};