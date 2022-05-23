class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        int res = 0;
        for (auto str : strs) {
            int zeroCount = 0;
            int oneCount = 0;
            for (auto c : str) {
                if (c == '0') zeroCount++;
                else oneCount++;
            }
            for (int i = m; i >= zeroCount; --i) {
                for (int j = n; j >= oneCount; --j) {
                    dp[i][j] = max(dp[i][j], dp[i - zeroCount][j - oneCount] + 1);
                    res = max(res, dp[i][j]);
                }
            }
        }
        return res;
    }
};