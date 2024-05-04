class Solution {
public:
    int tallestBillboard(vector<int>& rods) {
        unordered_map<int, int> dp;
        dp[0] = 0;
        for (auto& rod : rods) {
            unordered_map<int, int> tempDp(dp);
            for (auto [diff, height] : dp) {
                tempDp[diff + rod] = max(tempDp[diff + rod], dp[diff]);
                tempDp[abs(diff - rod)] = max(tempDp[abs(diff - rod)], dp[diff] + min(diff, rod));
            }
            dp = tempDp;
        }
        return dp[0];
    }
};
