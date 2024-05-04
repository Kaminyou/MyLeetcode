class Solution {
public:
    int minCost(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;
        for (int i = 0; i < n; ++i) {
            int trim = 0;
            vector<int> hash(1000, 0);
            for (int j = i; j < n; ++j) {
                hash[nums[j]]++;
                if (hash[nums[j]] == 2) trim += 2;
                else if (hash[nums[j]] > 2) trim += 1;
                dp[j + 1] = min(dp[j + 1], dp[i] + trim + k);
            }
        }
        return dp[n];
    }
};
