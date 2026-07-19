class Solution {
public:
    string smallestSubsequence(string s) {
        vector<char> st;
        bool seen[26];
        int mp[26];
        memset(seen, 0, sizeof(seen));
        int n = s.size();
        for (int i = 0; i < n; ++i) {
            mp[s[i] - 'a'] = i;
        }
        for (int i = 0; i < n; ++i) {
            if (!seen[s[i] - 'a']) {
                while (!st.empty() && st.back() - 'a' > s[i] - 'a' && mp[st.back() - 'a'] > i) {
                    seen[st.back() - 'a'] = false;
                    st.pop_back();
                }
                seen[s[i] - 'a'] = true;
                st.push_back(s[i]);
            }
        }
        string res;
        for (auto& c : st) {
            res.push_back(c);
        }
        return res;
    }
};
