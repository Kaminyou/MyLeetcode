class Solution {
public:
    static bool compare(vector<int>& v1, vector<int>& v2) {
        if (v1[0] != v2[0]) return v1[0] < v2[0];
        return v1[1] < v2[1];
    }
    int countWays(vector<vector<int>>& ranges) {
        sort(ranges.begin(), ranges.end(), compare);
        int n = ranges.size();
        int differenceGroup = 0;
        int index = 0;
        while (index < n) {
            int startLeft = ranges[index][0];
            int startRight = ranges[index][1];
            while (index + 1 < n && ranges[index + 1][0] <= startRight) {
                startRight = max(startRight, ranges[index + 1][1]);
                index++;
            }
            differenceGroup++;
            index++;
        }
        long long res = 1;
        long long mod = 1e9 + 7;
        for (int i = 0; i < differenceGroup; ++i) {
            res *= 2;
            res %= mod;
        }
        return res;
    }
};