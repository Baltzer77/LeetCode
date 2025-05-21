/*
 * @lc app=leetcode id=10 lang=cpp
 *
 * [10] Regular Expression Matching
 */

// @lc code=start
class Solution {
private: 
    struct pair_hash {
        std::size_t operator()(const std::pair<std::string, std::string>& p) const {
            std::hash<std::string> hasher;
            return hasher(p.first) ^ (hasher(p.second) << 1); // Combine hashes
        }
    };
    unordered_map<pair<string,string>, bool, pair_hash> memo;
public:
    bool isMatch(string s, string p) {
        return solve(s, p);
    }

    bool solve(string s, string p) {
        if(s.size() == 0 && p.size() == 0) return true;
        if(p.size() == 0) return false;

        if(memo.contains({s, p})) return memo[{s,p}];

        bool result = false;
        if(s.size() > 0 && (p[0] == s[0] || p[0] == '.')) {
            if(p.size() > 1 && p[1] == '*'){
                result = solve(s.substr(1, s.size() -1), p);
            }
            else {
                result = solve(s.substr(1, s.size() - 1), p.substr(1, p.size() -1));
            }
        }

        if(p.size() > 1 && p[1] == '*') {
            result = result || solve(s, p.substr(2, p.size() -2));
        }
        
        memo[{s,p}] = result;
        return result;
    }
};
// @lc code=end

