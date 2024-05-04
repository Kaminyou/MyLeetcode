class Solution {
public:
    int dp(vector<vector<int>>& memo, int state, int position, int n) {
        if (position == 0) return 1;
        if (memo[state][position] != -1) return memo[state][position];
        int res = 0;
        for (int i = 1; i <= n; ++i) {
            if ((((state & (1 << (i - 1))) == 0) && (((i % position) == 0) || (position % i) == 0))) {
                res += dp(memo, (state | (1 << (i - 1))), position - 1, n);
            }
        }
        return memo[state][position] = res;
    }
    int countArrangement(int n) {
        // memo[state][position]: state => bitmask for usage
        vector<vector<int>> memo(1 << n, vector<int>(n + 1, -1));
        return dp(memo, 0, n, n);
    }
};