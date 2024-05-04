class Solution {
public:
    string lastNonEmptyString(string s) {
        vector<int> positions(26, -1);
        vector<int> counts(26, 0);
        int maxCount = 0;
        for (int i = 0; i < s.size(); ++i) {
            positions[s[i] - 'a'] = i;
            counts[s[i] - 'a'] += 1;
            maxCount = max(maxCount, counts[s[i] - 'a']);
        }
        vector<pair<int, char>> ps;
        for (int i = 0; i < 26; ++i) {
            if (counts[i] == maxCount) ps.push_back({positions[i], i + 'a'});
        }
        sort(ps.begin(), ps.end());
        string out;
        for (auto& [_, c] : ps) out.push_back(c);
        return out;
    }
};
