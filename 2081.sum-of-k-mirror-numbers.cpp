/*
 * @lc app=leetcode id=2081 lang=cpp
 *
 * [2081] Sum of k-Mirror Numbers
 */

// @lc code=start
class Solution {
public:
    bool isPalindrome(string s) {
        string temp = s;
        int left = 0;
        int right = s.size() - 1;

        while(left < right) {
            if(s[left++] != s[right--]) return false;
        }

        return true;
    }

    string findNextPallindrome(string &s, int base) {
        int mid = (s.size() - 1) / 2;
        bool carry = true;
        int left = mid;
        int right = mid + 1;
        if((s.size() & 1) == 1) {
            if(s[mid] < '0' + base - 1) {
                s[mid] += 1;
                carry = false;
            }
            else {
                s[mid] = '0';
            }
            left--;
        } 
        while(carry && left >= 0 && right < s.size()) {

            if(s[left] < '0' + base - 1) {
                s[left--] += 1;
                s[right++] += 1;
                carry = false;
            }
            else {
                s[left--] = '0';
                s[right++] = '0';
            }
        }

        if(!carry) {
            return s;
        }

        s[0] = '1';

        return s + '1';
    }

    long long convertPalindromeToBase10(string &s, int base) {
        long long val = 0;

        for(int i = s.size() - 1; i >= 0; i--) {
            int digit = s[i] - '0';

            val += pow(base, s.size() - i - 1) * digit;
        }
        return val;
    }


    long long kMirror(int k, int n) {
        long long sum = 1;
        n--;
        string s = "1";
        while(n > 0) {
            s = findNextPallindrome(s, k);
            long long val = convertPalindromeToBase10(s, k);
            if(isPalindrome(to_string(val)))
            {
                n--;
                sum += val;
            }
        }

        return sum;
    }
};
// @lc code=end

