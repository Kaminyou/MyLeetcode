class Solution {
public:
    vector<string> res;
    void backtracking(string& s, unordered_set<string>& st, int curr, vector<string>& path) {
        if (curr == s.size()) {
            string out;
            for (auto word : path) out += word + " ";
            out.pop_back();
            res.push_back(out);
            return;
        }
        for (int i = curr + 1; i <= s.size(); i++) {
            string temp = s.substr(curr, i - curr);
            if (st.find(temp) != st.end()) {
                path.push_back(temp);
                backtracking(s, st, i, path);
                path.pop_back();
            }
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> st;
        for (auto word : wordDict) st.insert(word);
        
        vector<string> path;
        backtracking(s, st, 0, path);
        
        return res;
    }
};