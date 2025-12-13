class Solution {
public:
    int countPartitions(vector<int>& nums, int k) {
        deque<int> dq1, dq2; // max, min
        int n = nums.size();
        vector<long long> prefixSum(n + 1);
        vector<long long> dp(n + 1);
        dp[0] = 1;
        prefixSum[0] = 1;
        long long mod = 1e9 + 7;
        
        int left = 0;
        for (int right = 0; right < n; ++right) {
            while (!dq1.empty() && nums[dq1.back()] < nums[right]) dq1.pop_back();
            dq1.push_back(right);

            while (!dq2.empty() && nums[dq2.back()] > nums[right]) dq2.pop_back();
            dq2.push_back(right);

            while (nums[dq1.front()] - nums[dq2.front()] > k) {
                if (dq1.front() == left) dq1.pop_front();
                if (dq2.front() == left) dq2.pop_front();
                left++;
            }

            dp[right + 1] = prefixSum[right] - (left > 0 ? prefixSum[left - 1] : 0);
            prefixSum[right + 1] = prefixSum[right] + dp[right + 1];
            
            dp[right + 1] = (dp[right + 1] + mod) % mod;
            prefixSum[right + 1] = (prefixSum[right + 1] + mod) % mod;
        }
        return dp[n];
    }
};
