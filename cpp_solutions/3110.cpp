class Solution {
public:
    int scoreOfString(string s) {
        int res = 0;
        int n = s.size();
        for (int i = 0; i < n - 1; ++i) {
            res += abs(s[i + 1] - s[i]);
        }
        return res;
    }
};
