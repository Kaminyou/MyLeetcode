class Solution {
public:
    string greatestLetter(string s) {
        vector<bool> lower(26, false);
        vector<bool> upper(26, false);
        for (auto& c : s) {
            if (c >= 'a' && c <= 'z') lower[c - 'a'] = true;
            if (c >= 'A' && c <= 'Z') upper[c - 'A'] = true;
        }
        string res = "";
        for (int i = 25; i >= 0; --i) {
            if (lower[i] && upper[i]) {
                char ch = i + 'A';
                res.push_back(ch);
                break;
            }
        }
        return res;
    }
};