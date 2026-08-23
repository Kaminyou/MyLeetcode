class Solution {
public:
    long long maxTotal(vector<int>& nums, string s) {
        int n = nums.size();
        vector<long long> dp0(n + 1, 0);
        vector<long long> dp1(n + 1, 0);
        if (s[0] == '1') dp1[1] = nums[0];
        for (int i = 1; i < n; ++i) {
            if (s[i] == '1') {
                dp1[i + 1] = max(dp1[i + 1], dp1[i] + nums[i]);
                dp1[i + 1] = max(dp1[i + 1], dp0[i] + nums[i]);
                dp0[i + 1] = max(dp0[i + 1], dp1[i - 1] + nums[i - 1]);
                dp0[i + 1] = max(dp0[i + 1], dp0[i] + nums[i - 1]);
            }
            else {
                dp0[i + 1] = max(dp0[i], dp1[i]);
            }
        }
        return max(dp0[n], dp1[n]);
    }
};
