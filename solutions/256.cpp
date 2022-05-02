class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        vector<int> dp(3, 0);
        for (int i = 0; i < 3; i++) dp[i] = costs[0][i];
        
        for (int i = 1; i < costs.size(); i++) {
            int currR = costs[i][0] + min(dp[1], dp[2]);
            int currG = costs[i][1] + min(dp[0], dp[2]);
            int currB = costs[i][2] + min(dp[0], dp[1]);
            dp[0] = currR;
            dp[1] = currG;
            dp[2] = currB;
        }
        return *min_element(dp.begin(), dp.end());
    }
};