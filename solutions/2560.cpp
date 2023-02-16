class Solution {
public:
    bool criteria(vector<int>& nums, int k, int mid) {
        // select k not adjacent ones and the max is MID
        int n = nums.size();
        vector<int> dp(n, 0);
        if (nums[0] <= mid) dp[0] = 1;
        if (n > 1) {
            if (nums[1] <= mid) dp[1] = 1;
            else dp[1] = dp[0];
        }
        for (int i = 2; i < n; ++i) {
            if (nums[i] <= mid) {
                dp[i] = max(dp[i - 2] + 1, dp[i - 1]);
            }
            else {
                dp[i] = dp[i - 1];
            }
        }
        return dp[n - 1] >= k;
    }
    int minCapability(vector<int>& nums, int k) {
        int right = 1e9 + 1;
        int left = 0;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (criteria(nums, k, mid)) right = mid;
            else left = mid + 1;
        }
        return left;
    }
};
