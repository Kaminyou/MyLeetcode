class Solution {
public:
    bool lower[26];
    bool upper[26];
    int numberOfSpecialChars(string word) {
        for (int i = 0; i < 26; ++i) {
            lower[i] = false;
            upper[i] = false;
        }
        for (auto& c : word) {
            if (c >= 'a' && c <= 'z') lower[c - 'a'] = true;
            if (c >= 'A' && c <= 'Z') upper[c - 'A'] = true;
        }
        int res = 0;
        for (int i = 0; i < 26; ++i) {
            if (lower[i] && upper[i]) res++;
        }
        return res;
    }
};
