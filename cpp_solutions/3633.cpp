class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int n = landStartTime.size();
        int m = waterStartTime.size();
        int res = INT_MAX;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                int lst = landStartTime[i];
                int let = lst + landDuration[i];
                int wst = waterStartTime[j];
                int wet = wst + waterDuration[j];
                // land -> water
                if (let <= wst) res = min(res, wet);
                else res = min(res, let + waterDuration[j]);
                // water -> land
                if (wet <= lst) res = min(res, let);
                else res = min(res, wet + landDuration[i]);
            }
        }
        return res;
    }
};
