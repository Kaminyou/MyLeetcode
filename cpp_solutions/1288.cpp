class Solution {
public:
    const static bool compare(vector<int>& a, vector<int>& b) {
        if (a[0] != b[0]) return a[0] < b[0];
        return a[1] > b[1];
    }
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), compare);
        int n = intervals.size();
        int cnt = 0;
        int maxBoundary = intervals[0][1];
        for (int i = 1; i < n; ++i) {
            if (intervals[i][1] <= maxBoundary) cnt++;
            maxBoundary = max(maxBoundary, intervals[i][1]);
        }
        return n - cnt;
    }
};

