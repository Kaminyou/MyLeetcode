class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int n = nums.size();
        int dp[3] = {0, 0, 0};
        for (int i = 0; i < n; ++i) {
            int tempDP[3];
            int num = nums[i];
            for (int j = 0; j < 3; ++j) tempDP[j] = dp[j];
            for (int j = 0; j < 3; ++j) {
                int sum = tempDP[j] + num;
                int remain = sum % 3;
                dp[remain] = max(dp[remain], sum);
            }
        }
        return dp[0];
    }
};
