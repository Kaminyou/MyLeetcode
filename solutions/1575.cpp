class Solution {
public:
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        const long long mod = 1e9 + 7;
        int n = locations.size();
        vector<vector<long long>> dp(n, vector<long long>(fuel + 1, 0));
        dp[start][fuel] = 1;
        for (int f = fuel; f >= 0; f--) {
            for (int from = 0; from < n; from++) {
                for (int to = 0; to < n; to++) {
                    if (from == to) continue;
                    int cost = abs(locations[to] - locations[from]);
                    if (cost <= f) {
                        dp[to][f - cost] += dp[from][f];
                        dp[to][f - cost] %= mod;
                    }
                }
            }
        }
        long long res = 0;
        for (int i = 0; i <= fuel; ++i) {
            res += dp[finish][i];
            res %= mod;
        }
        return res;
    }
};