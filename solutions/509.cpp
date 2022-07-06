class Solution {
public:
    int fib(int n) {
        vector<int> dp(n + 1, 0);
        if (n == 0) return 0;
        dp[1] = 1;
        if (n == 1) return 1;
        for (int i = 2; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
};

// class Solution {
// public:
//     int fib(int n) {
//         if (n == 0) return 0;
//         int prev = 0;
//         int curr = 1;
//         n -= 1;
//         while (n) {
//             int next = prev + curr;
//             prev = curr;
//             curr = next;
//             n--;
//         }
//         return curr;
//     }
// };