class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int sum = 0;
        for (auto& num : nums) sum += num;
        if (sum % k) return false;
        
        sum /= k;
        if (nums[n - 1] > sum) return false;

        
        vector<bool> dp(1 << n, false);
        dp[0] = true;
        vector<int> total(1 << n, 0);
        for (int state = 0; state < (1 << n); ++state) {
            if (!dp[state]) continue;
            // find next state
            for (int i = 0; i < n; ++i) {
                if ((state & (1 << i)) == 0) {
                    if (nums[i] <= (sum - (total[state] % sum))) {
                        dp[state | (1 << i)] = true;
                        total[state | (1 << i)] = total[state] + nums[i];
                    }
                    // due to sorting
                    else {
                        break;
                    }
                }
            }
        }
        return dp[(1 << n) - 1];
    }
};