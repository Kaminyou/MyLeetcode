class Solution {
public:
    int distance(vector<int>& worker, vector<int>& bike) {
        return abs(worker[0] - bike[0]) + abs(worker[1] - bike[1]);
    }
    int assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
        int workerNum = workers.size();
        int bikeNum = bikes.size();
        vector<int> dp(1 << workerNum, INT_MAX / 2);
        dp[0] = 0;
        
        for (auto& bike : bikes) {
            for (int state = (1 << workerNum) - 1; state >= 0; --state) {
                for (int i = 0; i < workerNum; ++i) {
                    if ((state & (1 << i)) == 0) {
                        dp[state | (1 << i)] = min(dp[state | (1 << i)], dp[state] + distance(workers[i], bike));
                    }
                }
            }
        }
        return dp[(1 << workerNum) - 1];
    }
};