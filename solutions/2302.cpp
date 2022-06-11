class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        int n = nums.size();
        // use prefix sum to query sum in O(1)
        vector<long long> prefixSum(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            prefixSum[i + 1] = prefixSum[i] + nums[i];
        }
        
        long long res = 0;
        // two pointer approach
        // keep add right pointer and move left pointer
        // to make the interval match the criteria
        int left = 0;
        for (int right = 0; right < n; ++right) {
            while ((prefixSum[right + 1] - prefixSum[left]) * (right - left + 1) >= k) left++;
            // only consider all the subarrays have the "right" pointer
            // to avoid duplicates
            // e.g.,
            // xxx[abc]xxx
            // count [abc], [bc], [c]
            long long len = (right - left + 1);
            res += len;
        }
        return res;
    }
};