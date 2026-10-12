class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        vector<int> counts(32, 0);
        for (auto& num : nums) {
            for (int i = 0; i < 32; ++i) {
                if (num & (1 << i)) counts[i]++;
            }
        }
        long long res = 0;
        long long mod = 1e9 + 7;
        while (k--) {
            long long cur = 0;
            for (int i = 0; i < 32; ++i) {
                if (counts[i]) {
                    counts[i]--;
                    cur += (1 << i);
                }
            }
            res += cur * cur;
            res %= mod;
        }
        return res;
    }
};

