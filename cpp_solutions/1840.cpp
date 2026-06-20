class Solution {
public:
    int maxBuilding(int n, vector<vector<int>>& restrictions) {
        restrictions.push_back({1, 0});
        sort(restrictions.begin(), restrictions.end());
        int m = restrictions.size();
        vector<int> pos(m);
        vector<int> limit(m);
        vector<int> h(m);
        for (int i = 0; i < m; ++i) {
            pos[i] = restrictions[i][0];
            limit[i] = restrictions[i][1];
        }
        h[0] = 0;
        for (int i = 1; i < m; ++i) {
           h[i] = min(limit[i], h[i - 1] + pos[i] - pos[i - 1]); 
        }
        for (int i = m - 2; i >= 0; --i) {
            h[i] = min(h[i], h[i + 1] + pos[i + 1] - pos[i]);
        }
        int res = 0;
        for (int i = 1; i < m; ++i) {
            int peak = (h[i] + pos[i] + h[i - 1] - pos[i - 1]) / 2;
            res = max(res, peak);
        }
        res = max(res, h[m - 1] + n - pos[m - 1]);
        return res;
    }
};
