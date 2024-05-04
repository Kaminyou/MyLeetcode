class Solution {
public:
    char transform(char c) {
        if (c >= '0' && c <= '9') return c;
        if (c >= 'A' && c <= 'Z') return c;
        return 'A' + (c - 'a');
    }
    string licenseKeyFormatting(string s, int k) {
        int curr = 0;
        string out;
        for (int i = s.size() - 1; i >= 0; --i) {
            char c = s[i];
            if (c == '-') continue;
            char tC = transform(c);
            out.push_back(tC);
            curr++;
            if (curr == k) {
                out.push_back('-');
                curr = 0;
            }
        }
        if (out.size() == 0) return out;
        if (out[out.size() - 1] == '-') out.pop_back();
        reverse(out.begin(), out.end());
        return out;
    }
};