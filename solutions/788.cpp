class Solution {
public:
    int rotatedDigits(int n) {
        int res = 0;
        vector<int> dp(n + 1, 0);
        
        for (int i = 0; i <= n; ++i) {
            if (i < 10) {
                if (i == 0 || i == 1 || i == 8) dp[i] = 1;
                else if (i == 2 || i == 5 || i == 6 || i == 9) {
                    dp[i] = 2;
                    res += 1;
                }
            }
            else {
                int prefix = i / 10;
                int suffix = i % 10;
                if (dp[prefix] == 0 || dp[suffix] == 0) dp[i] = 0;
                else if (dp[prefix] == 1 && dp[suffix] == 1) dp[i] = 1;
                else {
                    dp[i] = 2;
                    res += 1;
                }
            }
        }
        return res;
    }
};