class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int maxDay = days[days.size() - 1];
        vector<int> dp(maxDay + 1, 0);
        int index = 0;
        for (int i = 1; i <= maxDay; i++) {
            if (i == days[index]) {
                index++;
                dp[i] = min({dp[max(i - 1, 0)] + costs[0], dp[max(i - 7, 0)] + costs[1], dp[max(i - 30, 0)] + costs[2]});
            }
            else {
                dp[i] = dp[i - 1];
            }
        }
        return dp[maxDay];
    }
};