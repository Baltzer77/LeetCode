class Solution {
public:
    bool isEqual(string& s1, string& s2, const int (&indices)[4]) {
        for(int i = 0; i < 4; i++) {
            if (s1[i] != s2[indices[i]])
                return false;
        }

        return true;
    }
    bool canBeEqual(string s1, string s2) {
        return 
            isEqual(s1, s2, {0,1,2,3})
            || isEqual(s1,s2, {0,3,2,1})
            || isEqual(s1, s2,{2,1,0,3})
            || isEqual(s1, s2, {2,3,0,1});
    }
};