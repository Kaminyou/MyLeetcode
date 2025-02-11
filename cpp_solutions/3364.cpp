class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n = nums.size();
        vector<int> prefix(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            prefix[i + 1] = prefix[i] + nums[i];
        }
        int res = INT_MAX;
        for (int size = l; size <= r; ++size) {
            for (int i = 0; i + size <= n; ++i) {
                int sum = prefix[i + size] - prefix[i];
                if (sum > 0) res = min(res, sum);
            }
        }
        if (res == INT_MAX) return -1;
        return res;
    }
};
