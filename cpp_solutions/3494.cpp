class Solution {
public:
    long long minTime(vector<int>& skill, vector<int>& mana) {
        int n = skill.size();
        int m = mana.size();
        long long dp[n];  // earlist time when wizard[i] is free
        for (int i = 0; i < n; ++i) dp[i] = 0;
        for (int j = 0; j < m; ++j) {
            long long now = dp[0];
            long long mmmm = mana[j];
            // forward
            for (int i = 1; i < n; ++i) {
                now = max(now + mmmm * skill[i - 1], dp[i]); // after i - 1 finish and current i's free time
            }
            dp[n - 1] = now + mmmm * skill[n - 1];

            // backward
            for (int i = n - 2; i >= 0; --i) {
                dp[i] = dp[i + 1] - mmmm * skill[i + 1];
            }
        }
        return dp[n - 1];
    }
};
