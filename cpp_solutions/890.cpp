class Solution {
public:
    bool isBijective(string& s, string& t) {
        vector<int> s2t(26, -1);
        vector<int> t2s(26, -1);
        int n = s.size();
        for (int i = 0; i < n; ++i) {
            int si = s[i] - 'a';
            int ti = t[i] - 'a';
            if (s2t[si] != -1 || t2s[ti] != -1) {
                if (t2s[ti] != si || s2t[si] != ti) return false;
            }
            else {
                s2t[si] = ti;
                t2s[ti] = si;
            }
        }
        return true;
    }
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> res;
        for (auto& word : words) {
            if (isBijective(word, pattern)) res.push_back(word);
        }
        return res;
    }
};