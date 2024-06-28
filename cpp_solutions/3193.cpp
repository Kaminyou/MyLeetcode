class Solution {
public:
    long long mod = 1e9 + 7;
    long long fact(long long n) {
        long long ret = 1;
        for (int i=1; i<=n; i++)
            ret = ret * i % mod;
        return ret;
    }
    int numberOfPermutations(int n, vector<vector<int>>& requirements) {
        
        int m = 0;
        map<int, long long> mp;
        for (auto& requirement : requirements) {
            mp[requirement[0] + 1] = requirement[1];
            m = max(m, requirement[1]);
        }
        vector<vector<long long>> dp(n + 1, vector<long long>(m + 1, 0));
        dp[0][0] = 1;

        int cur = 0;
        for (int i = 1; i <= n; ++i) {
            if (mp.find(i) != mp.end()) {
                cur = mp[i];
            }
            auto iter = mp.lower_bound(i);
            long long limit = iter->second;
            for (int j = cur; j <= limit; ++j) {
                for (int k = 0; k <= j; ++k) {
                    if (j - k <= i - 1) {
                        dp[i][j] += dp[i - 1][k];
                        dp[i][j] %= mod;
                    }
                }
            }
            if (mp.upper_bound(i) == mp.end()) {
                return dp[i][cur] * fact(n - i) % mod;
            }
        }
        return -1;
    }
};
