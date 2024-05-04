class Solution {
public:
    static bool compare(const vector<int>& v1, const vector<int>& v2) {
        return v1[1] < v2[1];
    }
    int maxValue(vector<vector<int>>& events, int k) {
        int n = events.size();
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
    
        sort(events.begin(), events.end(), compare);
        // iterate events
        for (int i = 1; i <= n; ++i) {
            auto it = lower_bound(events.begin(), events.begin() + i, vector<int>{0, events[i - 1][0], 0}, compare);
            const int p = it - events.begin(); 
            // so p - 1 item < current begin => match dp[p][...] one
            // iterate backpack
            for (int j = 1; j <= k; ++j) {
                dp[i][j] = max(dp[i - 1][j], dp[p][j - 1] + events[i - 1][2]);
            }
        }
        return dp[n][k];
    }
};