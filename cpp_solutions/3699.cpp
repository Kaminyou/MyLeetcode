class Solution {
public:
    int zigZagArrays(int n, int l, int r) {
        int mod = 1e9 + 7;
        r -= l;
        vector<int> dp(r + 1, 1);
        for (int i = 1; i < n; ++i) {
            int preSum = 0;
            int temp = 0;
            if (i & 1) {
                for (int k = 0; k <= r; ++k) {
                    temp = (preSum + dp[k]) % mod;
                    dp[k] = preSum;
                    preSum = temp;
                }
            }
            else {
                for (int k = r; k >= 0; --k) {
                    temp = (preSum + dp[k]) % mod;
                    dp[k] = preSum;
                    preSum = temp;
                }
            }
        }
        int res = 0;
        for (auto& num : dp) {
            res += num;
            res %= mod;
        }
        return (res * 2) % mod;
    }
};
