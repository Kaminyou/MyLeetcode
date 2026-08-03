class Solution {
public:
    string rearrangeString(string s, char x, char y) {
        vector<int> counts(26, 0);
        for (auto& c : s) {
            counts[c - 'a']++;
        }
        string res;
        for (int i = 0; i < counts[y - 'a']; ++i) {
            res.push_back(y);
        }
        for (int i = 0; i < counts[x - 'a']; ++i) {
            res.push_back(x);
        }
        for (int i = 0; i < 26; ++i) {
            if (i == x - 'a' || i == y - 'a') continue;
            for (int j = 0; j < counts[i]; ++j) {
                res.push_back(i + 'a');
            }
        }
        return res;
    }
};
