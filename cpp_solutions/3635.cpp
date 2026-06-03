class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int m = landStartTime.size();
        int n = waterStartTime.size();
        int minLandFinish = INT_MAX;
        int minWaterFinish = INT_MAX;
        for (int i = 0; i < m; ++i) {
            minLandFinish = min(minLandFinish, landStartTime[i] + landDuration[i]);
        }
        for (int i = 0; i < n; ++i) {
            minWaterFinish = min(minWaterFinish, waterStartTime[i] + waterDuration[i]);
        }

        int res = INT_MAX;
        for (int i = 0; i < n; ++i) {
            res = min(res, max(minLandFinish, waterStartTime[i]) + waterDuration[i]);
        }
        for (int i = 0; i < m; ++i) {
            res = min(res, max(minWaterFinish, landStartTime[i]) + landDuration[i]);
        }
        return res;
    }
};
