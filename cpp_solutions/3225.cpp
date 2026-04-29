class Solution {
public:
    long long maximumScore(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<long long> prevColW(n + 1, 0);
        vector<long long> prevColWO(n + 1, 0);
        vector<long long> currColW(n + 1, 0);
        vector<long long> currColWO(n + 1, 0);
        if (n == 1) return 0;
        for (int j = 1; j < n; ++j) {
            for (int i = 0; i <= n; ++i) {
                currColW[i] = 0;
                currColWO[i] = 0;
            }
            for (int i = 0; i <= n; ++i) {
                long long prevColVal = 0;
                long long currColVal = 0;
                for (int p = 0; p < i; ++p) {
                    currColVal += grid[p][j];
                }
                for (int k = 0; k <= n; ++k) {
                    if (k > 0 && k <= i) {
                        currColVal -= grid[k - 1][j];
                    }
                    if (k > i) {
                        prevColVal += grid[k - 1][j - 1];
                    }
                    currColWO[k] = max(currColWO[k], prevColVal + prevColWO[i]);
                    currColWO[k] = max(currColWO[k], prevColW[i]);
                    currColW[k] = max(currColW[k], currColVal + prevColW[i]);
                    currColW[k] = max(currColW[k], currColVal + prevColVal + prevColWO[i]);
                }
            }
            for (int i = 0; i <= n; ++i) {
                prevColW[i] = currColW[i];
                prevColWO[i] = currColWO[i];
            }
        }
        long long res = 0;
        for (int i = 0; i <= n; ++i) {
            res = max(res, currColW[i]);
        }
        return res;
    }
};
