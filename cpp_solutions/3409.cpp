class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        vector<vector<int>> dp(301, vector<int>(301, 0));
        int n = nums.size();
        for (int i = n - 1; i >= 0; --i) {
            int num = nums[i];
            for (int next = 1; next <= 300; ++next) {
                int diff = abs(next - num);
                dp[num][diff] = max(dp[num][diff], dp[next][diff] + 1);
            }
            for (int diff = 1; diff <= 300; ++diff) {
                dp[num][diff] = max(dp[num][diff], dp[num][diff - 1]);
            }
        }
        int res = 0;
        for (int i = 0; i <= 300; ++i) {
            for (int j = 0; j <= 300; ++j) {
                res = max(res, dp[i][j]);
            }
        }
        return res;
    }
};
