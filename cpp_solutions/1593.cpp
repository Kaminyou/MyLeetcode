class Solution {
public:
    int res = 0;
    void backtracking(string& s, int index, unordered_set<string>& st, int cnt) {
        if (index == s.size()) {
            res = max(res, cnt);
            return;
        }
        for (int i = index; i < s.size(); ++i) {
            string sub = s.substr(index, i - index + 1);
            if (!st.count(sub)) {
                st.insert(sub);
                backtracking(s, i + 1, st, cnt + 1);
                st.erase(sub);
            }
        }
    }
    int maxUniqueSplit(string s) {
        unordered_set<string> st;
        backtracking(s, 0, st, 0);
        return res;
    }
};
