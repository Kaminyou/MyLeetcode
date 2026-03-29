class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        vector<int> ones(26, 0);
        vector<int> twos(26, 0);
        for (int i = 0; i < 4; i += 2) {
            ones[s1[i] - 'a']--;
            ones[s2[i] - 'a']++;
        }
        for (int i = 1; i < 4; i += 2) {
            twos[s1[i] - 'a']--;
            twos[s2[i] - 'a']++;
        }
        for (int i = 0; i < 26; ++i) {
            if (ones[i] != 0) return false;
            if (twos[i] != 0) return false;
        }
        return true;
    }
};
