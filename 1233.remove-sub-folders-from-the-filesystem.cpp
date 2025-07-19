/*
 * @lc app=leetcode id=1233 lang=cpp
 *
 * [1233] Remove Sub-Folders from the Filesystem
 */

// @lc code=start
class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folders) {
        sort(folders.begin(), folders.end());
        unordered_set<string> hash;

        vector<string> result;

        for(const string& folder : folders) {
            bool isSubFolder = false;
            for(int i = 0; i < folder.size(); i++) {
                while(i < folder.size() && folder[i] != '/') {++i;}

                if(hash.contains(folder.substr(0, i))) {
                    isSubFolder = true;
                    break;
                }
            }

            if(!isSubFolder) {
                result.push_back(folder);
                hash.insert(folder);
            }
            
        }

        return result;
    }
};
// @lc code=end

