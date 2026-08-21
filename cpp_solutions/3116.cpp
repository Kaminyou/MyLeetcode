class Solution {
public:
    long long count(vector<int>& coins, long long val) {
        int n = coins.size();
        long long curr = 0;
        for (int mask = 1; mask < (1 << n); ++mask) {
            int isPos = __builtin_popcount(mask) & 1;
            long long factor = 1;
            if (!isPos) factor = -1;
            long long newCoin = 1;
            for (int i = 0; i < n; ++i) {
                if (mask & (1 << i)) newCoin = lcm(newCoin, coins[i]);
            }
            curr += (val / newCoin) * factor;
        }
        return curr;
    }
    long long findKthSmallest(vector<int>& coins, int k) {
        long long left = 0;
        long long right = LLONG_MAX;
        while (left < right) {
            long long mid = left + (right - left) / 2;
            if (count(coins, mid) >= k) right = mid;
            else left = mid + 1;
        }
        return left;
    }
};

