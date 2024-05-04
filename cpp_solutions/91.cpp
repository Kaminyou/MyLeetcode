class Solution {
public:
    int numDecodings(string s) {
        if (s[0] == '0') return 0;
        int n = s.size();
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 1; i < n; ++i) {
            if (s[i] != '0') dp[i + 1] = dp[i];
            int temp = stoi(s.substr(i - 1, 2));
            if (temp >= 10 && temp <= 26) {
                dp[i + 1] += dp[i - 1];
            }
        }
        return dp[n];
    }
};