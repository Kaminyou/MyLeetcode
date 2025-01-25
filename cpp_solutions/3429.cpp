class Solution {
public:
    vector<vector<vector<long long>>> memo;
    long long dp(int idx, int n, int p1, int p2, vector<vector<int>>& cost) {
        if (idx >= n / 2) return 0;
        if (p1 != -1 && p2 != -1 && memo[idx][p1][p2] != -1) return memo[idx][p1][p2];
        long long res = LLONG_MAX;
        for (int c1 = 0; c1 < 3; ++c1) {
            for (int c2 = 0; c2 < 3; ++c2) {
                if (c1 == c2) continue;
                if (c1 == p1 || c2 == p2) continue;
                long long temp = cost[idx][c1] + cost[n - idx - 1][c2] + dp(idx + 1, n, c1, c2, cost);
                res = min(res, temp);      
            }
        }
        if (p1 == -1 && p2 == -1) return res;
        return memo[idx][p1][p2] = res;
    }
    long long minCost(int n, vector<vector<int>>& cost) {
        memo.resize(n + 1, vector<vector<long long>>(4, vector<long long>(4, -1)));
        return dp(0, n, -1, -1, cost);
    }
};


