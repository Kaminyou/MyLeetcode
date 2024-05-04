class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int sum = 0;
        for (auto stone : stones) sum += stone;
        int n = sum / 2 + 1;
        vector<bool> dp(n, false);
        dp[0] = true;
        int maxVal = 0;
        for (auto stone : stones) {
            for (int i = n - 1; i >= 0; --i) {
                if (i < stone) continue;
                if (!dp[i]) dp[i] = dp[i - stone];
                if (dp[i]) {
                    maxVal = max(maxVal, i);
                }
            }
        }
        return sum - maxVal - maxVal;
    }
};