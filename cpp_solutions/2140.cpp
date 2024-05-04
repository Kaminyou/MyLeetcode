class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        vector<long long> dp(n + 1, 0);
        for (int i = n - 1; i >= 0; --i) {
            int point = questions[i][0];
            int skip = questions[i][1];
            if (i + skip + 1 >= n) {
                dp[i] = max((long long)point, dp[i + 1]);
            }
            else dp[i] = max(point + dp[i + skip + 1], dp[i + 1]);
        }
        return dp[0];
    }
};