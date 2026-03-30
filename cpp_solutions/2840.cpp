class Solution {
public:
    bool checkStrings(string s1, string s2) {
        vector<int> ones(26, 0);
        vector<int> twos(26, 0);
        int n = s1.size();
        for (int i = 0; i < n; i += 2) {
            ones[s1[i] - 'a']--;
            ones[s2[i] - 'a']++;
        }
        for (int i = 1; i < n; i += 2) {
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
