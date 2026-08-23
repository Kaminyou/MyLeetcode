class Solution {
public:
    static bool compare(vector<int>& a, vector<int>& b) {
        if (a[0] != b[0]) return a[0] < b[0];
        return a[1] > b[1];
    }
    long long minEnergy(int n, int brightness, vector<vector<int>>& intervals) {
        long long num = (brightness - 1) / 3 + 1;
        long long sum = 0;
        sort(intervals.begin(), intervals.end(), compare);
        int m = intervals.size();
        int start = intervals[0][0];
        int end = intervals[0][1];
        for (int i = 1; i < m; ++i) {
            if (intervals[i][0] > end) {
                sum += end - start + 1;
                start = intervals[i][0];
                end = intervals[i][1];
            }
            end = max(end, intervals[i][1]);
        }
        sum += end - start + 1;
        return sum * num;
    }
};


