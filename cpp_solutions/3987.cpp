class Solution {
public:
    long long mod = 1e9 + 7;
    long long inv(long long a) {
        if (a == 1) return 1;
        return (mod - mod / a) * inv(mod % a) % mod;
    }
    int minimumCost(vector<int>& nums, int k) {
        long long sum = 0;
        for (auto& num : nums) sum += num;
        long long multi = (sum + k - 1) / k - 1;
        multi %= mod;
        long long cost = ((1 + multi) * multi) % mod;
        cost *= inv(2);
        return cost % mod;
    }
};

