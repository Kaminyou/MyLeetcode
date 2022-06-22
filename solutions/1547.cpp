class Solution {
public:
    int dp(vector<int>& prefixSum, int left, int right, vector<vector<int>>& memo) {
        if (right - left < 1) return 0;
        if (right - left == 1) return prefixSum[right + 1] - prefixSum[left];
        if (memo[left][right] != -1) return memo[left][right];
        int res = INT_MAX;
        for (int i = left; i + 1 <= right; ++i) {
            res = min(res, dp(prefixSum, left, i, memo) + dp(prefixSum, i + 1, right, memo));
        }
        memo[left][right] = res + prefixSum[right + 1] - prefixSum[left];
        return memo[left][right];
    }
    int minCost(int n, vector<int>& cuts) {
        sort(cuts.begin(), cuts.end());
        // make cuts as prefix sum
        // [1, 3, 4, 5] => [0, 1, 3, 4, 5, 9]
        // m elements but m - 1 intervals (from 0 to m - 2)
        
        cuts.insert(cuts.begin(), 0);
        cuts.push_back(n);
        int m = cuts.size();

        vector<vector<int>> memo(m - 1, vector<int>(m - 1, -1));
        return dp(cuts, 0, m - 2, memo);
    }
};