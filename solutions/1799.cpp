class Solution {
public:
    vector<vector<int>> gcd;
    int dp(int n, int m, int curr, int state, vector<int>& memo) {
        if (curr == m) return 0;
        if (memo[state] != -1) return memo[state];
        int res = INT_MIN;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if ((state & (1 << i)) == 0 && (state & (1 << j)) == 0) {
                    int nextState = (state | (1 << i));
                    nextState |= (1 << j);
                    res = max(res, (curr + 1) * gcd[i][j] + dp(n, m, curr + 1, nextState, memo));
                }
            }
        }
        return memo[state] = res;
    }
    int maxScore(vector<int>& nums) {
        int n = nums.size();
        int m = n / 2;
        int state = 0;
        gcd.resize(n, vector<int>(n, 0));
        vector<int> memo(1 << n, -1);
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                gcd[i][j] = __gcd(nums[i], nums[j]);
            }
        }
        return dp(n, m, 0, state, memo);
    }
};