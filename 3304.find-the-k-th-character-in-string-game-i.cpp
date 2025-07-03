class Solution {
public:
    char kthCharacter(int k) {
        return 'a' + bitset<32>(k-1).count();
    }
};