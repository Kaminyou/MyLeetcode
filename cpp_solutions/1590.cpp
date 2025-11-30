class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        // find a subarray that has a sum of k, k+p, k+2p... => mod p = k
        long long sum = 0;
        for (auto& num : nums) sum += num;
        if (sum < p) return -1;
        long long k = sum % (long long)p;
        if (k == 0) return 0;
        unordered_map<long long, int> mod2loc;
        int res = INT_MAX;
        sum = 0;
        int n = nums.size();
        mod2loc[0] = -1;
        bool flag = false;
        for (int i = 0; i < n; ++i) {
            sum += nums[i];
            sum %= (long long)p;
            long long target = ((sum - k + p) % p);
            if (mod2loc.count(target)) {
                if (target == 0 && i == n - 1) {
                    if (flag) res = min(res, i - mod2loc[target]);
                }
                else res = min(res, i - mod2loc[target]);
            }
            mod2loc[sum] = i;
            if (sum == 0) flag = true;
        }
        return (res == INT_MAX) ? -1 : res;
    }
};

