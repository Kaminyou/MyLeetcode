class Solution {
public:
    int sumOfPower(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        long long res = 0;
        long long mod = 1e9 + 7;
        long long temp = 0;
        for (auto& num : nums) {
            res += (((long long)num * num) % mod) * (temp + num);
            res %= mod;
            temp = 2 * temp + num;
            temp %= mod;
        }
        return res;
    }
};

