class Solution {
public:
    int longestIdealString(string s, int k) {
        vector<int> dp(26, INT_MIN);
        int n = s.size();
        int res = 0;
        for (int i = 0; i < n; ++i) {
            int maxLength = 1;
            int c = s[i] - 'a';
            for (int j = 0; j < 26; ++j) {
                if (abs(c - j) > k) continue;
                maxLength = max(maxLength, dp[j] + 1);
            }
            dp[c] = maxLength;
            res = max(res, dp[c]);
        }
        return res;
    }
};