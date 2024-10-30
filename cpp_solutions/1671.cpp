class Solution {
public:
    vector<int> LIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] > nums[j]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }
        return dp;
    }
    int minimumMountainRemovals(vector<int>& nums) {
        vector<int> left = LIS(nums);
        reverse(nums.begin(), nums.end());
        vector<int> right = LIS(nums);
        reverse(right.begin(), right.end());

        int n = nums.size();
        int maxLength = 0;
        for (int i = 1; i < n - 1; ++i) {
            if (left[i] == 1) continue;
            if (right[i] == 1) continue;
            maxLength = max(maxLength, left[i] + right[i] - 1);
        }
        
        return n - maxLength;
    }
};
