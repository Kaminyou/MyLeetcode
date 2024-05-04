class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<char> st;
        unordered_set<char> seen;
        unordered_map<char, int> mp;
        
        int n = s.size();
        for (int i = 0; i < n; ++i) mp[s[i]] = i;

        for (int i = 0; i < n; ++i) {
            char c = s[i];
            if (seen.find(c) == seen.end()) {
                while (!st.empty() && c < st.back() && i < mp[st.back()]) {
                    char temp = st.back();
                    st.pop_back();
                    seen.erase(temp);
                }
                seen.insert(c);
                st.push_back(c);
            }
        }
        string out;
        for (auto& c : st) out.push_back(c);
        return out;
    }
};
