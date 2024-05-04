class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<long long> dp(target + 1, 0);
        dp[0] = 1;
        for (int i = 1; i <= target; ++i) {
            for (auto& num : nums) {
                if (num > i) continue;
                if (dp[i] > INT_MAX - dp[i - num]) continue;
                dp[i] += dp[i - num];
            }
        }
        return dp[target];
    }
};