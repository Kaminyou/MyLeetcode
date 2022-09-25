class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> prefixSum(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            prefixSum[i + 1] = prefixSum[i] + nums[i];
        }
        
        deque<int> dq;
        int res = INT_MAX;
        for (int i = 0; i <= n; ++i) {
            while (!dq.empty() && prefixSum[dq.back()] > prefixSum[i]) dq.pop_back();
            while (!dq.empty() && prefixSum[i] - prefixSum[dq.front()] >= k) {
                res = min(res, i - dq.front());
                dq.pop_front();
            }
            dq.push_back(i);
        }
        return res == INT_MAX ? -1 : res;
    }
};