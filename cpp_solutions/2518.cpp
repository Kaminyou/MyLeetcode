class Solution {
public:
    int countPartitions(vector<int>& nums, int k) {
        long long mod = 1e9 + 7;
        sort(nums.begin(), nums.end());
        // count [0, k - 1]
        vector<long long> dp(k + 1, 0);
        int n = nums.size();
        dp[0] = 1;
        long long sum = 0;
        for (auto& num : nums) {
            sum += num;
            for (int i = k; i >= 0; --i) {
                if (i + num > k) continue;
                dp[i + num] += dp[i];
                dp[i + num] %= mod;
            }
        }
        
        long long ans = 1;
        for (int i = 0; i < n; ++i) {
            ans *= 2;
            ans %= mod;
        }
        if (k > sum - k) return 0;
        for (int i = 0; i < k; ++i) {
            ans -= dp[i] * 2;
            ans += mod;
            ans %= mod;
        }
        ans += mod;
        ans %= mod;
        return ans;
    }
};

