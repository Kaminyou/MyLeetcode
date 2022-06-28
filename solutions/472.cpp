class Solution {
public:
    vector<string> res;
    unordered_set<string> st;
    unordered_set<string> visited;
    void backtracking(const string& s, int curr, int count) {
        if (curr == s.size()) {
            if (count >= 2 && visited.find(s) == visited.end()) {
                res.push_back(s);
                visited.insert(s);
            }
            return;
        }
        string temp;
        for (int i = curr; i < s.size(); ++i) {
            temp.push_back(s[i]);
            if (st.find(temp) != st.end()) backtracking(s, i + 1, count + 1);
        }
    }
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        for (auto& word : words) st.insert(word);
        for (auto& word : words) {
            backtracking(word, 0, 0);
        }
        return res;
    }
};