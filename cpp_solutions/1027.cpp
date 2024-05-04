class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size();
        int res = 2;
        vector<vector<int>> dp(n, vector<int>(1002, 0));
        int shift = 500;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int diff = nums[j] - nums[i] + shift;
                dp[j][diff] = max({2, dp[j][diff], dp[i][diff] + 1});
                res = max(res, dp[j][diff]);
            }
        }
        return res;
    }
};