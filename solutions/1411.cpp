typedef long long LL;
class Solution {
public:
    int numOfWays(int n) {
        LL mod = 1e9 + 7;
        vector<vector<int>> availableSet;
        vector<vector<vector<LL>>> dp(3, vector<vector<LL>>(3, vector<LL>(3, 0)));
        vector<vector<vector<LL>>> dpTemp(3, vector<vector<LL>>(3, vector<LL>(3, 0)));
        
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                for (int k = 0; k < 3; ++k) {
                    if (i != j && j != k) {
                        dp[i][j][k] = 1;
                        availableSet.push_back({i, j, k});
                    }
                }
            }
        }
        
        for (int t = 1; t < n; ++t) {
            for (auto& to : availableSet) {
                int i = to[0];
                int j = to[1];
                int k = to[2];
                dpTemp[i][j][k] = 0;
                for (auto& from : availableSet) {
                    int iF = from[0];
                    int jF = from[1];
                    int kF = from[2];
                    if (iF != i && jF != j && kF != k) {
                        dpTemp[i][j][k] += dp[iF][jF][kF];
                        dpTemp[i][j][k] %= mod;
                    }
                }
            }
            dp = dpTemp;
        }
        
        LL res = 0;
        for (auto& e : availableSet) {
            res += dp[e[0]][e[1]][e[2]];
            res %= mod;
        }
        
        return res;
    }
};