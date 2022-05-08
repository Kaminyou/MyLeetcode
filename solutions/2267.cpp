class Solution {
public:
    int M;
    int N;
    bool res = false;
    vector<pair<int, int>> directions = {{0, 1}, {1, 0}};
    vector<vector<vector<int>>> dp;
    
    bool dfs(vector<vector<char>>& grid, int x, int y, int path) {
        if (x == M - 1 && y == N - 1) {
            if (path == 0) {
                res = true;
                dp[x][y][path] = true;
                return true;
            }
            else return false;
        }
        if (res) return true;
        if (dp[x][y][path] != -1) return dp[x][y][path];
        
        vector<bool> v(2, false);
        for (int i = 0; i < 2; i++) {
            auto direction = directions[i];
            int _x = x + direction.first;
            int _y = y + direction.second;
            if (_x < 0 || _x >= M || _y < 0 || _y >= N) {
                v[i] = false;
                continue;
            }
            if (grid[_x][_y] == ')') {
                if (path == 0) {
                    v[i] = false;
                    continue;
                }
                else {
                    v[i] = dfs(grid, _x, _y, path - 1);
                }
            }
            else {
                v[i] = dfs(grid, _x, _y, path + 1);
            }
        }
        dp[x][y][path] = (v[0] || v[1]);
        return dp[x][y][path];
    }
    bool hasValidPath(vector<vector<char>>& grid) {
        M = grid.size();
        N = grid[0].size();
        dp = vector(M, vector(N, vector<int>(M + N, -1)));
        
        if ((M + N) % 2 == 0) return false;
        
        if (grid[0][0] == ')') return false;
        if (grid[M - 1][N - 1] == '(') return false;
        int path = 1;
        dfs(grid, 0, 0, path);
        return res;
    }
};