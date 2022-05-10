class Solution {
public:
    int M;
    int N;
    int dp(int y, int x1, int x2, vector<vector<vector<int>>>& memo, vector<vector<int>>& grid) {
        if (y < 0 || y >= M || x1 < 0 || x1 >= N || x2 < 0 || x2 >= N) return 0;
        if (memo[y][x1][x2] != -1) return memo[y][x1][x2];
        
        int curr = grid[y][x1] + (x1 == x2 ? 0 : grid[y][x2]);
        int res = 0;
        for (int p = -1; p <= 1; p++) {
            for (int q = -1; q <= 1; q++) {
                res = max(res, dp(y + 1, x1 + p, x2 + q, memo, grid));
            }
        }
        return memo[y][x1][x2] = curr + res;;
    }
    
    int cherryPickup(vector<vector<int>>& grid) {
        M = grid.size();
        N = grid[0].size();
        // memo: [row][robot1's col][robot2's col]
        vector<vector<vector<int>>> memo(M, vector(N, vector<int>(N, -1)));
        return dp(0, 0, N - 1, memo, grid);
    }
};