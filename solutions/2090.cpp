class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> prefixSum(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            prefixSum[i + 1] = prefixSum[i] + nums[i];
        }

        vector<int> res(n, -1);
        for (int i = 0; i < n; ++i) {
            int prevIdx = i - k;
            int nextIdx = i + k + 1;
            if (prevIdx < 0) continue;
            if (nextIdx > n) continue;
            res[i] = (prefixSum[nextIdx] - prefixSum[prevIdx]) / (2 * k + 1);
        }
        return res;
    }
};
