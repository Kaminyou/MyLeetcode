class Solution {
public:
    unordered_map<long long, int> memo;
    int helper(long long n) {
        if (n == 1) return 0;
        if (n == 2) return 1;
        if (memo.find(n) != memo.end()) return memo[n];
        if ((n & 1) == 0) return memo[n] = 1 + helper(n / 2);
        return memo[n] = 1 + min(helper(n + 1), helper(n - 1));
    }
    int integerReplacement(int n) {
        return helper(n);
    }
};