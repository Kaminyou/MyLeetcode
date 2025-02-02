class Solution {
public:
    string findValidPair(string s) {
        vector<int> counts(10, 0);
        for (auto& c : s) counts[c - '0']++;
        int n = s.size();
        for (int i = 0; i < n - 1; ++i) {
            if (s[i] == s[i + 1]) continue;
            if (s[i] - '0' != counts[s[i] - '0']) continue;
            if (s[i + 1] - '0' != counts[s[i + 1] - '0']) continue;
            return s.substr(i, 2);
        }
        return "";
    }
};
