class Solution {
public:
    int climbStairs(int n) {
        if (n == 1) return 1;
        if (n == 2) return 2;
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        dp[1] = 1;
        dp[2] = 2;
        for (int i = 3; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
};

class Solution {
public:
    int climbStairs(int n) {
        if (n == 1) return 1;
        if (n == 2) return 2;
        int prevTwo = 1;
        int prevOne = 2;
        for (int i = 2; i < n; ++i) {
            int current = prevTwo + prevOne;
            prevTwo = prevOne;
            prevOne = current;
        }
        return prevOne;
    }
};