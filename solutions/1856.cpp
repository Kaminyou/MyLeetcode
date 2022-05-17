class Solution {
public:
    int maxSumMinProduct(vector<int>& nums) {
        // concept: given a min value
        // => the max = max range of interval contain this value
        // => {more min, ... this min, ..., more min}
        // use monotonic stack from min->max
        // will be like [1, 2, 5] and meet next 3
        // 2 < {5} > 3 => get left and right boundary
        const long long mod = 1e9 + 7;
        int n = nums.size();
        vector<long long> prefixSum(n + 1, 0);
        for (int i = 1; i <= n; ++i) {
            prefixSum[i] = prefixSum[i - 1] + nums[i - 1];
        }
        
        stack<long long> st;
        
        long long res = 0;
        for (int i = 0; i <= n; i++) {
            while (!st.empty() && (i == n || nums[i] < nums[st.top()])) {
                int minVal = nums[st.top()];
                st.pop();
                int rightBoundary = i;
                // curr: index i < top => index i - 1 is boundary (inclusive)
                // but prefixSum start from 1 so index i - 1 + 1 = i
                int leftBoundary = (st.empty() ? 0 : st.top() + 1);
                // index st.top + 1 is left boundary should be excluded
                // so the range sum should be right - (left - 1)
                // but prefixSum start from 1 so st.top + 1 - 1 + 1 = st.top + 1
                res = max(res, minVal * (prefixSum[rightBoundary] - prefixSum[leftBoundary]));
            }
            st.push(i);
        }
        return res % mod;
    }
};