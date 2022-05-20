class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        // left + right = sum
        // left - right = target
        // left = (sum + target) / 2
        int sum = 0;
        for (auto num : nums) sum += num;
        if (abs(target) > sum) return 0;
        if ((sum + target) & 1) return 0;
        int newTarget = (sum + target) / 2;
        
        vector<int> dp(newTarget + 1, 0);
        dp[0] = 1;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = newTarget; j >= 0; j--) {
                if (j < nums[i]) continue;
                dp[j] += dp[j - nums[i]];
            }
        }
        return dp[newTarget];
    }
};