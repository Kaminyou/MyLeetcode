class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        unordered_map<int, unordered_set<int>> row2cols;
        //unordered_map<int, unordered_set<int>> col2rows;
        for (auto& point : points) {
            row2cols[point[0]].insert(point[1]);
            //col2rows[point[1]].insert(point[0]);
        }
        
        int res = INT_MAX;
        int n = points.size();
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (points[i][0] == points[j][0]) continue;
                if (points[i][1] == points[j][1]) continue;
                if (!row2cols[points[i][0]].count(points[j][1])) continue;
                if (!row2cols[points[j][0]].count(points[i][1])) continue;
                
                int width = abs(points[i][0] - points[j][0]);
                int height = abs(points[i][1] - points[j][1]);
                res = min(res, width * height);
            }
        }
        return (res == INT_MAX) ? 0 : res;
    }
};