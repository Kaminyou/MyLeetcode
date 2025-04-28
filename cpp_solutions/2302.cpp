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

class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        long long res = 0;
        int n = nums.size();
        int right = 0;
        long long cur = 0;
        long long sum = 0;
        long long length = 0;
        for (int left = 0; left < n; ++left) {
            while (right < n && cur + sum + nums[right] * (length + 1) < k) {
                cur = cur + sum + nums[right] * (length + 1);
                sum += nums[right];
                length++;
                right++;
            }
            if (cur < k) res += (right - left);
            cur -= length * nums[left];
            sum -= nums[left];
            cur -= sum;
            length--;
        }
        return res;
    }
};
