class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        int shift = n + 1;
        vector<int> counts(2 * shift + 2, 0);
        vector<int> prefixSum(2 * shift + 2, 0);
        counts[shift] = 1;
        prefixSum[shift] = 1;
        long long res = 0;
        int curr = 0;
        for (int i = 0; i < n; ++i) {
            curr += (nums[i] == target ? 1 : -1);
            counts[curr + shift] += 1;
            // lazy update: curr only change 1 or -1 every time
            prefixSum[curr + shift] = counts[curr + shift] + prefixSum[curr + shift - 1];
            res += prefixSum[curr + shift - 1];
        }
        return res;
    }
};
