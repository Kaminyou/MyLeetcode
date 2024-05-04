class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        int maxIdx = 0;
        int maxCnt = 0;
        vector<int> counts(m, 0);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (mat[i][j] == 1) counts[i]++;
            }
            if (counts[i] > maxCnt) {
                maxCnt = counts[i];
                maxIdx = i;
            }
        }
        return {maxIdx, maxCnt};
    }
};