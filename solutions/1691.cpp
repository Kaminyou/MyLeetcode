class Solution {
public:
    int maxHeight(vector<vector<int>>& cuboids) {
        for (auto& cuboid : cuboids) sort(cuboid.begin(), cuboid.end(), greater<int>());
        sort(cuboids.begin(), cuboids.end());
        int n = cuboids.size();
        vector<int> dp(n, 0);
        int res = INT_MIN;
        for (int i = 0; i < n; i++) {
            dp[i] = cuboids[i][0];
            for (int j = 0; j < i; j++) {
                if (cuboids[j][1] <= cuboids[i][1] && cuboids[j][2] <= cuboids[i][2]) {
                    dp[i] = max(dp[i], dp[j] + cuboids[i][0]);
                }
            }
            res = max(res, dp[i]);
        }
        return res;
    }
};