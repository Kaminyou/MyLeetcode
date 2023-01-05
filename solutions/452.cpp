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

class Solution {
public:
    static bool compare(const vector<int>& point1, const vector<int>& point2) {
        return point1[1] < point2[1];
    }
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), compare);
        int cnt = 0;
        int n = points.size();
        int index = 0;
        int current = -1;
        while (index < n) {
            current = points[index][1];
            cnt++;
            while (index + 1 < n && points[index + 1][0] <= current) {
                index++;
            }
            index++;
        }
        return cnt;
    }
};