class Solution {
public:
    int distinctSubseqII(string s) {
        const uint mod = 1e9 + 7;
        int n = s.size();
        vector<long long> dp(n + 1, 0);
        dp[0] = 1;
        vector<uint> positions(26, -1);
        for (int i = 1; i <= n; ++i) {
            int c = s[i - 1] - 'a';
            dp[i] = dp[i - 1] * 2;
            dp[i] %= mod;
            // e.g., abcdb
            //        ^  ^
            // => xxxb so delete those ones end with b during [ab]
            // which is dp[a idx], since a_(this) or ab
            if (positions[c] != -1) {
                dp[i] -= dp[positions[c] - 1];
            }
            dp[i] %= mod;
            positions[c] = i;
        }
        return (dp[n] - 1 + mod) % mod;
    }
};