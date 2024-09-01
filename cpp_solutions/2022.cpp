class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        int k = original.size();
        if (m * n != k) return {};
        vector<vector<int>> res(m, vector<int>(n, 0));
        int index = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                res[i][j] = original[index];
                index++;
            }
        }
        return res;
    }
};
