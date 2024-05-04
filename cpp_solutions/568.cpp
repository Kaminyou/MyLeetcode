class Solution {
public:
    int maxVacationDays(vector<vector<int>>& flights, vector<vector<int>>& days) {
        int cityNum = flights.size();
        int weekNum = days[0].size();
        
        vector<int> dp(cityNum, INT_MIN);
        dp[0] = 0;
        
        for (int wk = 0; wk < weekNum; ++wk) {
            vector<int> dpTemp(cityNum, INT_MIN);
            for (int to = 0; to < cityNum; ++to) {
                for (int from = 0; from < cityNum; ++from) {
                    if (to == from || flights[from][to]) {
                        dpTemp[to] = max(dpTemp[to], dp[from] + days[to][wk]);
                    }
                }
            }
            dp = dpTemp;
        }
        return *max_element(dp.begin(), dp.end());
    }
};