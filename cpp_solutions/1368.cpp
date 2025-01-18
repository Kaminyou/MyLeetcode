class Solution {
public:
    vector<pair<int, int>> directions = {{0, 0}, {0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    void dfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, queue<pair<int, int>>& q, int r, int c) {
        if (visited[r][c]) return;
        int m = grid.size();
        int n = grid[0].size();
        q.push({r, c});
        visited[r][c] = true;
        int nextIdx = grid[r][c];
        pair<int, int> direction = directions[nextIdx];
        int nextR = r + direction.first;
        int nextC = c + direction.second;
        if (nextR < 0 || nextR >= m || nextC < 0 || nextC >= n) return;
        dfs(grid, visited, q, nextR, nextC);
    }
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        queue<pair<int, int>> q;
        dfs(grid, visited, q, 0, 0);

        int res = 0;
        while (!q.empty()) {
            int k = q.size();
            while (k--) {
                auto [r, c] = q.front();
                q.pop();
                if (r == m - 1 && c == n - 1) return res;
                for (auto& direction : directions) {
                    int nextR = r + direction.first;
                    int nextC = c + direction.second;
                    if (nextR < 0 || nextR >= m || nextC < 0 || nextC >= n) continue;
                    if (!visited[nextR][nextC]) {
                        dfs(grid, visited, q, nextR, nextC);
                    }
                }
            }
            res++;
        }
        return -1;
    }
};
