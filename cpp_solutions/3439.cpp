class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        int currentTime = 0;
        vector<int> intervals;
        int n = startTime.size();
        for (int i = 0; i < n; ++i) {
            int end = startTime[i];
            intervals.push_back(end - currentTime);
            currentTime = endTime[i];
        }
        intervals.push_back(eventTime - currentTime);

        int m = intervals.size();
        // merge k + 1 intervals;
        int s = min(k + 1, m);
        vector<int> prefix(m + 1, 0);
        for (int i = 0; i < m; ++i) {
            prefix[i + 1] = prefix[i] + intervals[i];
        }
        int res = 0;
        for (int i = 0; i + s <= m; ++i) {
            res = max(res, prefix[i + s] - prefix[i]);
        }
        return res;
    }
};

