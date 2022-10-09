class Solution {
public:
    int hardestWorker(int n, vector<vector<int>>& logs) {
        int res = 0;
        int diff = 0;
        int currentTime = 0;
        int m = logs.size();
        
        for (int i = 0; i < m; ++i) {
            int currentDiff = logs[i][1] - currentTime;
            if (currentDiff > diff) {
                res = logs[i][0];
                diff = currentDiff;
            }
            else if (currentDiff == diff) {
                res = min(res, logs[i][0]);
            }
            currentTime = logs[i][1];
        }
        return res;
    }
};