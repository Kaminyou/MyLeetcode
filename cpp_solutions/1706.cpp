class Solution {
public:
    int M;
    int N;
    int dfs(vector<vector<int>>& grid, int x, int y) {
        if (x == M) return y;
        if (grid[x][y] == 1) {
            if (y == N - 1) return -1;
            if (grid[x][y + 1] == -1) return -1; 
            return dfs(grid, x + 1, y + 1);
        }
        else {
            if (y == 0) return -1;
            if (grid[x][y - 1] == 1) return -1; 
            return dfs(grid, x + 1, y - 1);
        }
    }
    vector<int> findBall(vector<vector<int>>& grid) {
        M = grid.size();
        N = grid[0].size();
        vector<int> res(N, 0);
        for (int i = 0; i < N; i++) {
            res[i] = dfs(grid, 0, i);
        }
        return res;
    }
};