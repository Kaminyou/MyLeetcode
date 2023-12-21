class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        unordered_set<int> xs;
        for (auto& point : points) xs.insert(point[0]);
        vector<int> xss(xs.begin(), xs.end());
        sort(xss.begin(), xss.end());
        int n = xss.size();
        int res = 0;
        for (int i = 0; i < n - 1; ++i) {
            res = max(res, xss[i + 1] - xss[i]);
        }
        return res;
    }
};
