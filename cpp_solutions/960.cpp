class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size();
        int m = strs[0].size();
        vector<int> dp(m, 1);
        int invRes = 1;
        for (int i = 1; i < m; ++i) {
            for (int j = 0; j < i; ++j) {
                bool okay = true;
                for (int k = 0; k < n; ++k) {
                    if (strs[k][j] > strs[k][i]) {
                        okay = false;
                        break;
                    }
                }
                if (okay) {
                    dp[i] = max(dp[i], dp[j] + 1);
                    invRes = max(invRes, dp[i]);
                }
            }
        }
        return m - invRes;
    }
};
