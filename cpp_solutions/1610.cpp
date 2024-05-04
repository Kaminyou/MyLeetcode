class Solution {
public:
    double PI = 3.1415926;
    double getAngle(const vector<int>& from, const vector<int>& to) {
        int x = to[0] - from[0];
        int y = to[1] - from[1];
        double degree = atan2(y, x) * 180 / PI;
        return degree;
    }
    int visiblePoints(vector<vector<int>>& points, int angle, vector<int>& location) {
        vector<double> degrees;
        int duplicates = 0;
        for (auto& point : points) {
            if (point[0] == location[0] && point[1] == location[1]) {
                duplicates++;
                continue;
            }
            degrees.push_back(getAngle(location, point));
        }
        sort(degrees.begin(), degrees.end());
        
        
        int n = degrees.size();
        for (int i = 0; i < n; ++i) {
            degrees.push_back(degrees[i] + 360);
        }
        
        // sliding window
        n = degrees.size();
        int left = 0;
        int res = 0;
        for (int right = 0; right < n; ++right) {
            while (degrees[right] - degrees[left] > angle) left++;
            res = max(res, right - left + 1);
        }
        return res + duplicates;
    }

};