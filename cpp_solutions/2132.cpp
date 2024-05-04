class Solution {
public:
    int M;
    int N;
    void toPrefixSum(vector<vector<int>>& from, vector<vector<int>>& to) {
        to[0][0] = from[0][0];
        for (int i = 1; i < M; i++) to[i][0] = from[i][0] + to[i - 1][0];
        for (int j = 1; j < N; j++) to[0][j] = from[0][j] + to[0][j - 1];
        for (int i = 1; i < M; ++i) {
            for (int j = 1; j < N; ++j) {
                to[i][j] = to[i - 1][j] + to[i][j - 1] + from[i][j] - to[i - 1][j - 1];
            }
        }
    }
    int queryPrefixSum(int r1, int c1, int r2, int c2, vector<vector<int>>& prefixSum) {
        // all inclusive
        int up = (r1 == 0 ? 0 : prefixSum[r1 - 1][c2]);
        int left = (c1 == 0 ? 0 : prefixSum[r2][c1 - 1]);
        int duplicate = ((r1 == 0 || c1 == 0) ? 0 : prefixSum[r1 - 1][c1 - 1]);
        return prefixSum[r2][c2] - up - left + duplicate;
    }
    bool possibleToStamp(vector<vector<int>>& grid, int stampHeight, int stampWidth) {
        M = grid.size();
        N = grid[0].size();
        vector<vector<int>> prefixSum(M, vector<int>(N, 0));
        toPrefixSum(grid, prefixSum);
        
        vector<vector<int>> stamp(M, vector<int>(N, 0));
        // possible to put a stamp at right button corner (e.g, 3*3)
        // (i - stampHeight + 1, j - stampWidth + 1)-> ### 
        //                                             ###
        //                                             ##O <- (i, j)
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                if (i < stampHeight - 1 || j < stampWidth - 1) continue;
                int sum = queryPrefixSum(i - stampHeight + 1, j - stampWidth + 1, i, j, prefixSum);
                if (sum == 0) stamp[i][j] = 1;
            }
        }
        vector<vector<int>> prefixSumStamp(M, vector<int>(N, 0));
        toPrefixSum(stamp, prefixSumStamp);
        // if > 1 stamp at curr to right botton corner, then this cell is covered
        // (i, j) -> V00
        //           011
        //           101 <- (i + stampHeight - 1, j + stampWidth - 1)
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                int downCorner = min(M - 1, i + stampHeight - 1);
                int rightCorner = min(N - 1, j + stampWidth - 1);
                int sum = queryPrefixSum(i, j, downCorner, rightCorner, prefixSumStamp);
                if (sum == 0 && grid[i][j] != 1) return false;
            }
        }
        return true;
    }
};