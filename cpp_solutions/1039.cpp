class Solution {
public:
    int dp(int memo[51][51], vector<int>& values, int start, int end) {
        if (end - start < 2) return 0;
        if (end - start == 2) return values[start] * values[start + 1] * values[end];
        if (memo[start][end] != 0) return memo[start][end];
        int res = INT_MAX;
        for (int k = start + 1; k < end; ++k) {
            int curr = values[start] * values[k] * values[end];
            res = min(res, curr + dp(memo, values, start, k) + dp(memo, values, k, end));
        }
        return memo[start][end] = res;
    }
    int minScoreTriangulation(vector<int>& values) {
        int n = values.size();
        int memo[51][51];
        for (int i = 0; i < 51; ++i) {
            for (int j = 0; j < 51; ++j) {
                memo[i][j] = 0;
            }
        }
        return dp(memo, values, 0, n - 1);
    }
};
