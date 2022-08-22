class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int minVal = arrays[0][0];
        int maxVal = arrays[0][arrays[0].size() - 1];
        int m = arrays.size();
        int res = INT_MIN;
        for (int i = 1; i < m; ++i) {
            int n = arrays[i].size();
            res = max(res, abs(maxVal - arrays[i][0]));
            res = max(res, abs(arrays[i][n - 1] - minVal));
            maxVal = max(maxVal, arrays[i][n - 1]);
            minVal = min(minVal, arrays[i][0]);
        }
        return res;
    }
};