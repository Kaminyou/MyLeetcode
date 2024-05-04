class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int n = points.size();
        int res = 0;
        for (int i = 0; i < n - 1; ++i) {
            int xs = abs(points[i + 1][0] - points[i][0]);
            int ys = abs(points[i + 1][1] - points[i][1]);
            res += max(xs, ys);
        }
        return res;
    }
};
