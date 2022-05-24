class Solution {
public:
    const int INF = 1e7;
    int recursive(vector<vector<int>>& cost, vector<vector<int>>& memo, int n, int k, int i) {
        if (k == 0 && i == n) return 0;
        if (k == 0 || i == n) return INF;
        if (memo[k][i] != -1) return memo[k][i];
        int res = INF;
        for (int j = i; j < n; ++j) {
            res = min(res, cost[i][j] + recursive(cost, memo, n, k - 1, j + 1));
        }
        return memo[k][i] = res;
    }
    int minDistance(vector<int>& houses, int k) {
        int n = houses.size();
        vector<vector<int>> cost(n + 1, vector<int>(n + 1, 0));
        vector<vector<int>> memo(n + 1, vector<int>(n + 1, -1));
        
        sort(houses.begin(), houses.end());
        for (int i = 0; i < n; ++i) {
            for (int j = i; j < n; ++j) {
                int mid = houses[(i + j) / 2];
                for (int k = i; k <= j; ++k) {
                    cost[i][j] += abs(houses[k] - mid);
                }
            }
        }
        return recursive(cost, memo, n, k, 0);
    }
};