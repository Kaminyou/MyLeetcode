class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        const long long mod = 1e9 + 7;
        vector<vector<long long>> dp(n, vector<long long>(forget, 0));
        dp[0][0] = 1;
        for (int i = 1; i < n; ++i) {
            for (int j = forget - 1; j >= 1; j--) {
                dp[i][j] = dp[i - 1][j - 1];
            }
            for (int j = delay; j < forget; ++j) {
                dp[i][0] += dp[i][j];
                dp[i][0] %= mod;
            }
        }
        long long sum = 0;
        for (int j = 0; j < forget; ++j) {
            sum += dp[n - 1][j];
            sum %= mod;
        }
        return sum;
    }
};

class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        vector<long long> days(n + 1, 0);
        days[1] = 1;
        long long mod = 1e9 + 7;
        for (int i = 2; i <= n; ++i) {
            for (int j = n; j >= 1; --j) {
                days[j] = days[j - 1];
            }
            days[1] = 0;
            for (int j = delay + 1; j <= forget; ++j) {
                days[1] += days[j];
                days[1] %= mod;
            }
        }
        long long res = 0;
        for (int i = 1; i <= forget; ++i) {
            res += days[i];
            res %= mod;
        }
        return res;
    }
};

