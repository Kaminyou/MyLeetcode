class Solution {
public:
    int countVowelStrings(int n) {
        vector<int> dp = {0, 1, 1, 1, 1, 1};
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= 5; ++j) {
                dp[j] = dp[j - 1] + dp[j];
            }
        }
        return dp[5];
    }
};