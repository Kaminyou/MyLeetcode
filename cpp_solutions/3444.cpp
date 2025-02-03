class Solution {
public:
    int minimumIncrements(vector<int>& nums, vector<int>& target) {
        int m = target.size();
        vector<long long> mask2LCM((1 << m), 0);

        for (int mask = 1; mask <= (1 << m) - 1; ++mask) {
            long long l = 1;
            for (int j = 0; j < m; ++j) {
                if ((1 << j) & mask) {
                    l = lcm(l, target[j]);
                }
            }
            mask2LCM[mask] = l;
        }

        vector<long long> dp((1 << m), INT_MAX);
        dp[0] = 0;
        for (auto& num : nums) {
            vector<long long> tempDP = dp;
            for (int mask = 1; mask < (1 << m); ++mask) {
                long long l = mask2LCM[mask];
                long long cost = num % l;
                if (cost != 0) cost = l - cost;
                for (int oldMask = 0; oldMask < (1 << m); ++oldMask) {
                    int newMask = mask | oldMask;
                    tempDP[newMask] = min(tempDP[newMask], dp[oldMask] + cost);
                }
            }
            dp = tempDP;
        }
        return dp[(1 << m) - 1];
    }
    long long lcm(long long a, long long b) {
        return a * b / __gcd(a, b);
    }
};
