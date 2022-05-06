class Solution {
public:
    string removeDuplicates(string s) {
        vector<char> st;
        for (auto c : s) {
            if (!st.empty() && st.back() == c) {
                while (!st.empty() && st.back() == c) st.pop_back();
            }
            else st.push_back(c);
        }
        string res;
        for (auto c : st) res.push_back(c);
        return res;
    }
};