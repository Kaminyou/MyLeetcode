class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> left(n, 0);
        vector<int> right(n, n - k);
        vector<int> prefixSum(n + 1, 0);
        for (int i = 1; i <= n; ++i) {
            prefixSum[i] = prefixSum[i - 1] + nums[i - 1];
        }
        
        int currSum = prefixSum[k] - prefixSum[0];
        for (int i = k; i < n; ++i) {
            if (prefixSum[i + 1] - prefixSum[i + 1 - k] > currSum) {
                currSum = prefixSum[i + 1] - prefixSum[i + 1 - k];
                left[i] = i + 1 - k;
            }
            else left[i] = left[i - 1];
        }
        
        currSum = prefixSum[n] - prefixSum[n - k];
        for (int i = n - k - 1; i >= 0; --i) {
            if (prefixSum[i + k] - prefixSum[i] >= currSum) { //mind >=
                currSum = prefixSum[i + k] - prefixSum[i];
                right[i] = i;
            }
            else right[i] = right[i + 1];
        }
        
        int currMax = INT_MIN;
        vector<int> res;
        for (int i = k; i <= n - k * 2; ++i) {
            int l = left[i - 1];
            int r = right[i + k];
            int lSum = prefixSum[l + k] - prefixSum[l];
            int iSum = prefixSum[i + k] - prefixSum[i];
            int rSum = prefixSum[r + k] - prefixSum[r];
            if (lSum + iSum + rSum > currMax) {
                currMax = lSum + iSum + rSum;
                res = {l, i, r};
            }
        }
        return res;
    }
};
