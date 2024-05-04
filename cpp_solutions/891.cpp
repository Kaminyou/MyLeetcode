class Solution {
public:
    int sumSubseqWidths(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        long long res = 0;
        long long mod = 1e9 + 7;
        long long power = 1;
        for (int i = 0; i < n; ++i) {
            res += (nums[i] - nums[n - i - 1]) * power;
            res %= mod;
            power <<= 1;
            power += mod;
            power %= mod;
        }
        return res;
    }
};