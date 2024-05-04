class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n = nums.size();
        vector<long long> prefixSum(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            prefixSum[i] = prefixSum[i - 1] + nums[i - 1];
        }
        
        int count = 0;
        for (int i = 1; i < n; i++) {
            long long pre = prefixSum[i] - prefixSum[0];
            long long post = prefixSum[n] - prefixSum[i];
            if (pre >= post) count++;
        }
        return count;
    }
};