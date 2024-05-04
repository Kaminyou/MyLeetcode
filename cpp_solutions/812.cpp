class Solution {
public:
    double heron(vector<int>& v1, vector<int>& v2, vector<int>& v3) {
        double a = sqrt((v1[0] - v2[0]) * (v1[0] - v2[0]) + (v1[1] - v2[1]) * (v1[1] - v2[1]));
        double b = sqrt((v2[0] - v3[0]) * (v2[0] - v3[0]) + (v2[1] - v3[1]) * (v2[1] - v3[1]));
        double c = sqrt((v1[0] - v3[0]) * (v1[0] - v3[0]) + (v1[1] - v3[1]) * (v1[1] - v3[1]));
        double s = (a + b + c) / 2;
        return sqrt(s * (s - a) * (s - b) * (s - c));
    }
    double largestTriangleArea(vector<vector<int>>& points) {
        int n = points.size();
        double res = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                for (int k = j + 1; k < n; ++k) {
                    double current = heron(points[i], points[j], points[k]);
                    res = max(res, current);
                }
            }
        }
        return res;
    }
};