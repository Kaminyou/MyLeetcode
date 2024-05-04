class Solution {
public:
    int _rob(vector<int>& nums, int start, int end) {
        int n = end - start;
        vector<int> dp(n, 0);
        dp[0] = nums[start];
        if (n == 1) return dp[0];
        dp[1] = max(dp[0], nums[start + 1]);
        if (n == 2) return dp[1];
        
        for (int i = 2; i < n; i++) {
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[start + i]);
        }
        return dp[n - 1];
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        if (n == 2) return max(nums[0], nums[1]);
        return max(_rob(nums, 0, n - 1), _rob(nums, 1, n));
    }
};