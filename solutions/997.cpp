class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> inDegrees(n + 1, 0);
        vector<int> outDegrees(n + 1, 0);
        for (auto& p : trust) {
            inDegrees[p[1]]++;
            outDegrees[p[0]]++;
        }
        int cnt = 0;
        int res = -1;
        for (int i = 1; i <= n; ++i) {
            if (outDegrees[i] == 0 && inDegrees[i] == n - 1) {
                cnt++;
                res = i;
            }
        }
        if (cnt == 0 || cnt >= 2) return -1;
        return res;
    }
};