class Solution {
public:
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        sort(arr2.begin(), arr2.end());
        int n = arr1.size();
        arr1.insert(arr1.begin(), 0);
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, INT_MAX));
        dp[0][0] = INT_MIN;

        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j <= i; ++j) {
                if (dp[i - 1][j] < arr1[i]) {
                    dp[i][j] = min(dp[i][j], arr1[i]);
                }
                if (j >= 1) {
                    auto it = upper_bound(arr2.begin(), arr2.end(), dp[i - 1][j - 1]);
                    if (it != arr2.end()) {
                        dp[i][j] = min(dp[i][j], *it);
                    }
                }
            }
        }

        int res = INT_MAX;
        for (int j = 0; j <= n; ++j) {
            if (dp[n][j] != INT_MAX) res = min(res, j);
        }
        return res == INT_MAX ? -1 : res;
    }
};