class Solution {
public:
    static bool compare(const vector<int>& v1, const vector<int>& v2) {
        return v1[1] < v2[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.size() == 1) return 0;
        sort(intervals.begin(), intervals.end(), compare);
        int end = intervals[0][1];
        int count = 1;
        for (int i = 1; i < intervals.size(); ++i) {
            if (intervals[i][0] >= end) {
                end = intervals[i][1];
                count++;
            }
        }
        return intervals.size() - count;
    }
};