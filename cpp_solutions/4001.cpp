class Solution {
public:
    vector<vector<int>> aggregateTimeSeries(vector<vector<int>>& series1, vector<vector<int>>& series2) {
        vector<vector<int>> res;
        series1.push_back({INT_MAX, 0});
        series2.push_back({INT_MAX, 0});
        int m = series1.size();
        int n = series2.size();
        int idx1 = 0;
        int idx2 = 0;
        while (idx1 < m && idx2 < n) {
            int t1 = series1[idx1][0];
            int t2 = series2[idx2][0];
            int v1 = series1[idx1][1];
            int v2 = series2[idx2][1];
            if (t1 < t2) {
                if (t1 != INT_MAX) res.push_back({t1, v1 + v2});
                idx1++;
            }
            else if (t1 > t2) {
                if (t2 != INT_MAX) res.push_back({t2, v1 + v2});
                idx2++;
            }
            else {
                if (t1 != INT_MAX) res.push_back({t1, v1 + v2});
                idx1++;
                idx2++;
            }
        }
        return res;
    }
};
