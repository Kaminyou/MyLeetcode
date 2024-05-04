class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();
        vector<int> prefixSum(n + 1, 0);
        for (int i = 0; i < n; ++i) prefixSum[i + 1] = prefixSum[i] + nums[i];
        int maxVal = prefixSum[n];
        
        vector<int> prefixSumCount(maxVal + 1, 0);
        for (auto& num : prefixSum) prefixSumCount[num]++;
        int left = 0;
        int res = 0;
        for (; left + goal <= maxVal; left++) {
            int right = left + goal;
            if (left == right) {
                res += (prefixSumCount[left] * (prefixSumCount[left] - 1)) / 2;
            }
            else {
                res += prefixSumCount[left] * prefixSumCount[right];
            }
        }
        return res;
    }
};