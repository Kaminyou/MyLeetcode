class Solution {
public:
    long long maximumTotalDamage(vector<int>& power) {
        map<int, int> mp;
        for (auto& p : power) mp[p]++;
        int m = mp.size();
        long long numbers[m];
        long long counts[m];
        int index = 0;
        for (auto& [n, c] : mp) {
            numbers[index] = n;
            counts[index] = c;
            index++;
        }
        long long dp[m];
        for (int i = 0; i < m; ++i) dp[i] = 0;
        long long res = 0;
        for (int i = 0; i < m; ++i) {
            if (i >= 1) dp[i] = max(dp[i], dp[i - 1]);
            long long curr = numbers[i] * counts[i];
            dp[i] = max(dp[i], curr);
            for (int j = 1; j <= 3; ++j) {
                if (i - j < 0) break;
                if (numbers[i - j] < numbers[i] - 2) {
                    dp[i] = max(dp[i], curr + dp[i - j]);
                }
            }
            res = max(res, dp[i]);
        }
        return res;
    }
};

