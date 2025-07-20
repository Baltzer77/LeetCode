/*
 * @lc app=leetcode id=12 lang=cpp
 *
 * [12] Integer to Roman
 */

// @lc code=start
class Solution {
public:
    static constexpr string ones[] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
    static constexpr string tens[] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
    static constexpr string hunds[] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
    static constexpr string thous[] = {"", "M", "MM", "MMM"};
    string intToRoman(int num) {
        return thous[num / 1000] + hunds[(num% 1000) /100] + tens[(num% 100) / 10] + ones[num % 10];
    }
};
// @lc code=end

