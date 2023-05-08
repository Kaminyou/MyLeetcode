class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        int k = arr.size();
        vector<int> rowCnt(n, 0);
        vector<int> colCnt(m, 0);
        vector<pair<int, int>> locations(m * n);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                locations[mat[i][j] - 1] = {i, j};
            }
        }
        for (int i = 0; i < k; ++i) {
            auto [x, y] = locations[arr[i] - 1];
            rowCnt[y]++;
            colCnt[x]++;
            if (rowCnt[y] == m) return i;
            if (colCnt[x] == n) return i;
        }
        return k;
    }
};