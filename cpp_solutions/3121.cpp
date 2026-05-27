class Solution {
public:
    int numberOfSpecialChars(string word) {
        bool lower[26];
        bool upper[26];
        bool valid[26];
        for (int i = 0; i < 26; ++i) {
            lower[i] = false;
            upper[i] = false;
            valid[i] = true;
        }
        for (auto& c : word) {
            if (c >= 'a' && c <= 'z') {
                lower[c - 'a'] = true;
                if (upper[c - 'a']) {
                    valid[c - 'a'] = false;
                }
            }
            if (c >= 'A' && c <= 'Z') {
                upper[c - 'A'] = true;
            }
        }
        int res = 0;
        for (int i = 0; i < 26; ++i) {
            if (lower[i] && upper[i] && valid[i]) res++;
        }
        return res;
    }
};
