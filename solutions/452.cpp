class Solution {
public:
    static bool compare(const vector<int>& v1, const vector<int>& v2) {
        return v1[1] < v2[1];
    }
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), compare);
        int end = points[0][1];
        int count = 1;
        for (int i = 1; i < points.size(); ++i) {
            if (points[i][0] <= end) continue;
            end = points[i][1];
            count++;
        }
        return count;
    }
};