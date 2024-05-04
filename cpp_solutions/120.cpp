class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        if (n == 1) return triangle[0][0];
        vector<vector<int>> dp;
        dp.push_back({triangle[0][0]});
        dp.push_back({triangle[0][0] + triangle[1][0], triangle[0][0] + triangle[1][1]});
        for (int i = 2; i < n; i++) {
            vector<int> curr;
            for (int j = 0; j <= i; j++) {
                if (j == 0) curr.push_back(dp[i - 1][j] + triangle[i][j]);
                else if (j == i) curr.push_back(dp[i - 1][j - 1] + triangle[i][j]);
                else curr.push_back(min(dp[i - 1][j], dp[i - 1][j - 1]) + triangle[i][j]);    
            }
            dp.push_back(curr);
        }
        int ans = INT_MAX;
        for (int i = 0; i < n; i++) {
            ans = min(ans, dp[n - 1][i]);
        }
        return ans;
    }
};