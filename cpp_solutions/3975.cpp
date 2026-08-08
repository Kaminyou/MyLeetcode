class Solution {
public:
    static bool compare(vector<int>& v1, vector<int>& v2) {
        if (v1[0] != v2[0]) return v1[0] < v2[0];
        return v1[1] < v2[1];
    }
    vector<vector<int>> filterOccupiedIntervals(vector<vector<int>>& occupiedIntervals, int freeStart, int freeEnd) {
        sort(occupiedIntervals.begin(), occupiedIntervals.end(), compare);
        int start = occupiedIntervals[0][0];
        int end = occupiedIntervals[0][1];
        int n = occupiedIntervals.size();
        vector<vector<int>> newIntervals;
        for (int i = 1; i < n; ++i) {
            if (occupiedIntervals[i][0] > end + 1) {
                newIntervals.push_back({start, end});
                start = occupiedIntervals[i][0];
                end = occupiedIntervals[i][1];
            }
            else {
                end = max(end, occupiedIntervals[i][1]);
            }
        }
        newIntervals.push_back({start, end});

        // remove free
        int m = newIntervals.size();
        vector<vector<int>> finalIntervals;
        for (int i = 0; i < m; ++i) {
            int s = newIntervals[i][0];
            int e = newIntervals[i][1];
            if (e < freeStart) {
                finalIntervals.push_back(newIntervals[i]);
            }
            else if (s > freeEnd) {
                finalIntervals.push_back(newIntervals[i]);
            }
            else {
                if (s < freeStart) finalIntervals.push_back({s, freeStart - 1});
                if (e > freeEnd) finalIntervals.push_back({freeEnd + 1, e});
            }
        }
        return finalIntervals;
    }
};
