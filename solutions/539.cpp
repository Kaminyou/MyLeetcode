class Solution {
public:
    int differenceOfTime(const string& t1, const string& t2) {
        int h1 = stoi(t1.substr(0, 2));
        int h2 = stoi(t2.substr(0, 2));
        int m1 = stoi(t1.substr(3, 2));
        int m2 = stoi(t2.substr(3, 2));
        int t1Minute = h1 * 60 + m1;
        int t2Minute = h2 * 60 + m2;
        return abs(t2Minute - t1Minute);
    }
    int findMinDifference(vector<string>& timePoints) {
        int res = INT_MAX;
        sort(timePoints.begin(), timePoints.end());
        int n = timePoints.size();
        for (int i = 0; i < n; ++i) {
            int diff = differenceOfTime(timePoints[(i - 1 + n) % n], timePoints[i]);
            res = min(res, diff);
            res = min(res, 1440 - diff);
        }
        return res;
    }
};