class Solution {
public:
    int dp(int left, int right, vector<vector<int>>& memo) {
        if (left >= right) return 0;
        if (memo[left][right] != 0) return memo[left][right];
        int res = INT_MAX;
        for (int i = left; i <= right; ++i) {
            res = min(res, i + max(dp(left, i - 1, memo), dp(i + 1, right, memo)));
        }
        return memo[left][right] = res;
    }
    int getMoneyAmount(int n) {
        vector<vector<int>> memo(n + 1, vector<int>(n + 1, 0));
        return dp(1, n, memo);
    }
};
