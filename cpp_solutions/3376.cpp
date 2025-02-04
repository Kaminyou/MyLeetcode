class Solution {
public:
    int _findMinimumTime(vector<int>& strength, int k, int index, int mask, int x) {
        int n = strength.size();
        // current
        int curr = strength[index];
        int time = (curr - 1) / x + 1;
        int res = INT_MAX;
        bool isFollow = false;
        for (int i = 0; i < n; ++i) {
            if ((mask & (1 << i)) == 0) {
                int next = _findMinimumTime(strength, k, i, mask | (1 << i), x + k);
                res = min(res, time + next);
                isFollow = true;
            }
        }
        if (!isFollow) return time;
        return res;
    }
    int findMinimumTime(vector<int>& strength, int k) {
        int n = strength.size();
        int mask = 0;
        int res = INT_MAX;
        for (int i = 0; i < n; ++i) {
            int next = _findMinimumTime(strength, k, i, mask | (1 << i), 1);
            res = min(res, next);
        }
        return res;
    }
};
