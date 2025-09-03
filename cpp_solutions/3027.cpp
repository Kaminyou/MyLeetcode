class Solution {
public:
    static bool compare(vector<int>& a, vector<int>& b) {
        if (a[0] == b[0]) return a[1] > b[1];
        return a[0] < b[0];
    }
    int numberOfPairs(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), compare);
        int n = points.size();
        int res = 0;
        for (int i = 0; i < n; ++i) {
            int height = INT_MIN;
            for (int j = i + 1; j < n; ++j) {
                if (points[i][1] >= points[j][1] && points[j][1] > height) {
                    height = points[j][1];
                    res++;
                }
            }
        }
        return res;
    }
};
