class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> dp(n, INT_MIN);
        dp[n - 1] = nums[n - 1];
        deque<int> q;
        q.push_back(n - 1);
        
        for (int i = n - 2; i >= 0; --i) {
            dp[i] = nums[i] + dp[q.front()];
            if (q.front() >= i + k) q.pop_front();
            while (!q.empty() && dp[q.back()] <= dp[i]) {
                q.pop_back();
            }
            q.push_back(i);
        }
        return dp[0];
    }
};