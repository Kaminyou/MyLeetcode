class Solution {
public:
    int maxScore(string s) {
        int n = s.size();
        int ones = 0;
        for (int i = n - 1; i >= 0; --i) {
            ones += (s[i] - '0');
        }
        int res = 0;
        int zeros = 0;
        for (int i = 0; i < n - 1; ++i) {
            zeros += abs(s[i] - '1');
            ones -= abs(s[i] - '0');
            res = max(res, zeros + ones);
        }
        return res;
    }
};
