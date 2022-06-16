class Solution {
public:
    int queryRange(int x1, int y1, int x2, int y2, vector<vector<int>>& prefix) {
        return prefix[x1 + 1][y1 + 1] - prefix[x2][y1 + 1] - prefix[x1 + 1][y2] + prefix[x2][y2];
    }
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> prefix(m + 1, vector<int>(n + 1, 0));
        
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                prefix[i][j] = prefix[i - 1][j] + prefix[i][j - 1] + matrix[i - 1][j - 1] - prefix[i - 1][j - 1];
            }
        }
        
        int res = 0;
        for (int r1 = 0; r1 < m; r1++) {
            for (int r2 = r1; r2 < m; r2++) {
                unordered_map<int, int> mp;
                mp[0] = 1;
                for (int c = 0; c < n; ++c) {
                    int curr = queryRange(r2, c, r1, 0, prefix);
                    if (mp.find(curr - target) != mp.end()) res += mp[curr - target];
                    mp[curr]++;
                }
            }
        }
        return res;
    }
};