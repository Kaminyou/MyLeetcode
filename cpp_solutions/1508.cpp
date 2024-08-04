class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int> sums;
        vector<int> prefix(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            prefix[i + 1] = prefix[i] + nums[i];
        }
        for (int i = 0; i < n; ++i) {
            for (int j = i; j < n; ++j) {
                int sum = prefix[j + 1] - prefix[i];
                sums.push_back(sum);
            }
        }
        sort(sums.begin(), sums.end());
        long long res = 0;
        long long mod = 1e9 + 7;
        for (int i = left; i <= right; i++) {
            res += sums[i - 1];
            res %= mod;
        }
        return res;
    }
};
