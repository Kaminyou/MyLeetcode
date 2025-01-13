class Solution {
public:
    int minimumLength(string s) {
        vector<int> counts(26, 0);
        for (auto& c : s) counts[c - 'a']++;
        int res = 0;
        for (int i = 0; i < 26; ++i) {
            if (counts[i] == 0) continue;
            if (counts[i] & 1) res += 1;
            else res += 2;
        }
        return res;
    }
};

