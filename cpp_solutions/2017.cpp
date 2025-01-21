class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        int n = grid[1].size();
        vector<long long> prefix1(n, 0);
        vector<long long> prefix2(n, 0);
        prefix2[0] = grid[1][0];
        for (int i = 1; i < n; ++i) {
            prefix2[i] = prefix2[i - 1] + grid[1][i];
        }
        prefix1[n - 1] = grid[0][n - 1];
        for (int i = n - 2; i >= 0; --i) {
            prefix1[i] = prefix1[i + 1] + grid[0][i];
        }
        long long res = LLONG_MAX;
        for (int i = 0; i < n; ++i) {
            long long a = 0;
            long long b = 0;
            if (i == 0) {
                b = 0;
            }
            else {
                b = prefix2[i - 1];
            }
            if (i == n - 1) {
                a = 0;
            }
            else {
                a = prefix1[i + 1];
            }
            res = min(res, max(a, b));
        }
        return res;
    }
};
