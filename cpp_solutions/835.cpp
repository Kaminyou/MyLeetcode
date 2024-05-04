class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();
        int m = n * 3 - 2;
        vector<vector<bool>> pseudo(m, vector<bool>(m, false));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                pseudo[i + n - 1][j + n - 1] = (img2[i][j] == 1);
            }
        }
        
        int res = 0;
        for (int i = 0; i <= m - n; ++i) {
            for (int j = 0; j <= m - n; ++j) {
                bool flag = true;
                int cnt = 0;
                for (int x = 0; x < n; ++x) {
                    if (!flag) break;
                    for (int y = 0; y < n; ++y) {
                        bool value = (img1[x][y] == 1);
                        if (value && pseudo[i + x][j + y]) cnt++;
                    }
                }
                res = max(res, cnt);
            }
        }
        return res;
    }
};
