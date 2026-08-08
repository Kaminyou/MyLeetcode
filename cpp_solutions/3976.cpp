class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        long long res = LLONG_MIN;
        long long dp0 = 0;
        long long dpa = 0;
        long long dpb = 0;
        long long dp1 = 0;
        for (auto& num : nums) {
            long long a = (long long)num * k;
            long long b = (long long)num / k;
            dp1 = max({dpb + num, dpa + num, dp1 + num});
            dpb = max({dpb + b, dp0 + b, b});
            dpa = max({dpa + a, dp0 + a, a});
            dp0 = max({dp0 + num, (long long)num});
            res = max({res, dp0, dpa, dpb, dp1});
        }
        return res;
    }
};
