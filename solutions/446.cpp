class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        vector<unordered_map<int, int>> dp(n);
        int res = 0;
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                long long diff = static_cast<long long>(nums[i]) - nums[j];
                if (diff < INT_MIN || diff > INT_MAX) continue;
                dp[i][diff]++;
                if (dp[j].count(diff)) {
                    res += dp[j][diff];
                    dp[i][diff] += dp[j][diff];
                }
            }
        }
        return res;
    }
};