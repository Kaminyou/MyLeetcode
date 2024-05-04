class Solution {
public:
    static bool compare(vector<int>& v1, vector<int>& v2) {
        if (v1[1] == v2[1]) return v1[0] > v2[0];
        return v1[1] < v2[1];
    }
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), compare);
        int pointA = intervals[0][1] - 1;
        int pointB = intervals[0][1];
        int count = 2;
        for (auto& interval : intervals) {
            if (interval[0] <= pointA) continue;
            else if (interval[0] <= pointB) {
                pointA = pointB;
                pointB = interval[1];
                count++;
            }
            else {
                pointA = interval[1] - 1;
                pointB = interval[1];
                count += 2;
            }
        }
        return count;
    }
};