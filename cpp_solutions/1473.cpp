class Solution {
public:
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        const int INF = 1e9 + 7;
        
        // dp[group][house][color]
        vector<vector<vector<int>>> dp(target + 1, vector<vector<int>>(m + 1, vector<int>(n + 1, INF)));
        for (int i = 0; i <= n; i++) dp[0][0][i] = 0;
        
        for (int k = 1; k <= target; ++k) {
            for (int i = k; i <= m; ++i) {
                int hi = houses[i - 1];
                int hj = (i >= 2) ? houses[i - 2] : 0;
                
                int si, ei, sj, ej;
                if (hi == 0) {
                    si = 1;
                    ei = n;
                }
                else si = ei = hi;
                if (hj == 0) {
                    sj = 1;
                    ej = n;
                }
                else sj = ej = hj;
                
                for (int ci = si; ci <= ei; ci++) {
                    int val = (ci == hi) ? 0 : cost[i - 1][ci - 1];
                    for (int cj = sj; cj <= ej; cj++) {
                        dp[k][i][ci] = min(dp[k][i][ci], dp[k - (ci != cj)][i - 1][cj] + val);
                    }
                }
            }
        }
        int res = INF;
        for (int i = 0; i <= n; i++) res = min(res, dp[target][m][i]);
        return res >= INF ? -1 : res;
     }
};