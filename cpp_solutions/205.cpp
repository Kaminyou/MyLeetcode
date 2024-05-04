class Solution {
public:
    bool isIsomorphic(string s, string t) {
        vector<int> s2t(256, -1);
        vector<int> t2s(256, -1);
        int n = s.size();
        for (int i = 0; i < n; ++i) {
            char from = s[i];
            char to = t[i];
            if (s2t[from] == -1 && t2s[to] == -1) {
                s2t[from] = to;
                t2s[to] = from;
            }
            else if (s2t[from] != -1 && t2s[to] != -1) {
                if (s2t[from] != to) return false;
                if (t2s[to] != from) return false;
            }
            else return false;
        }
        return true;
    }
};