class Solution {
public:
    vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int M;
    int N;
    bool isValid(int x, int y) {
        if (x < 0 || x >= M || y < 0 || y >= N) return false;
        return true;
    }
    void bfs(queue<pair<int, int>>& q, vector<vector<bool>>& matrix, vector<vector<int>>& heights) {
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            for (auto& direction : directions) {
                int nextX = x + direction.first;
                int nextY = y + direction.second;
                if (!isValid(nextX, nextY)) continue;
                if (matrix[nextX][nextY]) continue;
                if (heights[nextX][nextY] < heights[x][y]) continue;
                q.push({nextX, nextY});
                matrix[nextX][nextY] = true;
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        M = heights.size();
        N = heights[0].size();
        
        // pacific
        vector<vector<bool>> pacific(M, vector<bool>(N, false));
        queue<pair<int, int>> q;
        for (int i = 0; i < M; ++i) {
            q.push({i, 0});
            pacific[i][0] = true;
        }
        for (int j = 0; j < N; ++j) {
            q.push({0, j});
            pacific[0][j] = true;
        }
        bfs(q, pacific, heights);
        
        // atlantic
        vector<vector<bool>> atlantic(M, vector<bool>(N, false));
        for (int i = 0; i < M; ++i) {
            q.push({i, N - 1});
            atlantic[i][N - 1] = true;
        }
        for (int j = 0; j < N; ++j) {
            q.push({M - 1, j});
            atlantic[M - 1][j] = true;
        }
        bfs(q, atlantic, heights);
        
        // combine
        vector<vector<int>> res;
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                if (pacific[i][j] && atlantic[i][j]) res.push_back({i, j});
            }
        }
        return res;
    }
};

// V2
// class Solution {
// public:
//     vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
//         int m = heights.size();
//         int n = heights[0].size();
        
//         vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        
//         // pacific
//         vector<vector<bool>> canReachPacific(m, vector<bool>(n, false));
//         queue<pair<int, int>> q;
//         for (int i = 0; i < m; i++) {
//             q.push(make_pair(i, 0));
//             canReachPacific[i][0] = true;
//         }
//         for (int j = 1; j < n; j++) {
//             q.push(make_pair(0, j));
//             canReachPacific[0][j] = true;
//         }
        
//         while (!q.empty()) {
//             auto [x, y] = q.front();
//             q.pop();
//             for (auto direction : directions) {
//                 int _x = x + direction.first;
//                 int _y = y + direction.second;
//                 if (_x < 0 || _x >= m || _y < 0 || _y >= n) continue;
//                 if (canReachPacific[_x][_y]) continue;
//                 if (heights[x][y] > heights[_x][_y]) continue;
//                 q.push(make_pair(_x, _y));
//                 canReachPacific[_x][_y] = true;
//             }
//         }
        
//         while (!q.empty()) q.pop();
        
//         // atlantic
//         vector<vector<bool>> canReachAtlantic(m, vector<bool>(n, false));
//         for (int i = 0; i < m; i++) {
//             q.push(make_pair(i, n - 1));
//             canReachAtlantic[i][n - 1] = true;
//         }
//         for (int j = 0; j < n - 1; j++) {
//             q.push(make_pair(m - 1, j));
//             canReachAtlantic[m - 1][j] = true;
//         }
        
//         while (!q.empty()) {
//             auto [x, y] = q.front();
//             q.pop();
//             for (auto direction : directions) {
//                 int _x = x + direction.first;
//                 int _y = y + direction.second;
//                 if (_x < 0 || _x >= m || _y < 0 || _y >= n) continue;
//                 if (canReachAtlantic[_x][_y]) continue;
//                 if (heights[x][y] > heights[_x][_y]) continue;
//                 q.push(make_pair(_x, _y));
//                 canReachAtlantic[_x][_y] = true;
//             }
//         }
        
//         // final
//         vector<vector<int>> res;
//         for (int i = 0; i < m; i++) {
//             for (int j = 0; j < n; j++) {
//                 if (canReachPacific[i][j] && canReachAtlantic[i][j]) res.push_back({i, j});
//             }
//         }
//         return res;
//     }
// };