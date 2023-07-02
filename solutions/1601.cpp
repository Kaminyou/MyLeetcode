class Solution {
public:
    vector<int> buildings;
    bool check(int state, int n, int m, vector<vector<int>>& requests) {
        for (int i = 0; i < n; ++i) buildings[i] = 0;
        for (int i = 0; i < m; ++i) {
            if (state & (1 << i)) {
                buildings[requests[i][0]]++;
                buildings[requests[i][1]]--;
            }
        }
       for (int i = 0; i < n; ++i) {
           if (buildings[i] != 0) return false;
       }
       return true;
    }
    int maximumRequests(int n, vector<vector<int>>& requests) {
        int m = requests.size();
        buildings.resize(n, 0);
        int res = 0;
        for (int state = 0; state < (1 << m); ++state) {
            if (check(state, n, m, requests)) res = max(res, __builtin_popcount(state));
        }
        return res;
    }
};
