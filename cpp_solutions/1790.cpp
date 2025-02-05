class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        vector<int> hash(26, 0);
        int diff = 0;
        int n = s1.size();
        for (int i = 0; i < n; ++i) {
            if (s1[i] != s2[i]) diff++;
            hash[s1[i] - 'a']++;
            hash[s2[i] - 'a']--;
        }
        if (diff != 0 && diff != 2) return false;
        for (int i = 0; i < 26; ++i) {
            if (hash[i] != 0) return false;
        }
        return true;
    }
};
