class Solution {
public:
    int countVowelPermutation(int n) {
        long long mod = 1e9 + 7;
        vector<long long> dp(5, 1);
        vector<long long> dpTemp(5, 0);
        for (int i = 1; i < n; ++i) {
            dpTemp[0] = dp[1] + dp[2] + dp[4];
            dpTemp[1] = dp[0] + dp[2];
            dpTemp[2] = dp[1] + dp[3];
            dpTemp[3] = dp[2];
            dpTemp[4] = dp[2] + dp[3];
            for (int j = 0; j < 5; ++j) {
                dpTemp[j] %= mod;
            }
            dp = dpTemp;
        }
        long long res = 0;
        for (auto& num : dp) {
            res += num;
            res %= mod;
        }
        return res;
    }
};
// a -> e
// e -> {a, i}
// i -> {a, e, o, u}
// o -> {i, u}
// u -> a

// {e, i, u} -> a
// {a, i} -> e
// {e, o} -> i
// {i} -> o
// {i, o} -> u