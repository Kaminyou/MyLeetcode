class Solution {
public:
    int M;
    int N;
    bool isOutside(int x, int y) {
        return (x < 0 || x >= M || y < 0 || y >= N);
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        M = matrix.size();
        N = matrix[0].size();
        vector<vector<int>> inDegrees(M, vector<int>(N, 0));
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                for (auto direction : directions) {
                    int _x = i + direction.first;
                    int _y = j + direction.second;
                    if (isOutside(_x, _y)) continue;
                    if (matrix[i][j] < matrix[_x][_y]) inDegrees[i][j]++;
                }
            }
        }
        
        queue<pair<int, int>> q;
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                if (inDegrees[i][j] == 0) q.push(make_pair(i, j));
            }
        }
        
        int level = 0;
        while (!q.empty()) {
            level++;
            queue<pair<int, int>> newQ;
            while (!q.empty()) {
                auto [x, y] = q.front();
                q.pop();
                for (auto direction : directions) {
                    int _x = x + direction.first;
                    int _y = y + direction.second;
                    if (isOutside(_x, _y)) continue;
                    if (matrix[x][y] > matrix[_x][_y]) {
                        inDegrees[_x][_y]--;
                        if (inDegrees[_x][_y] == 0) newQ.push(make_pair(_x, _y));
                    }
                }
            }
            q = newQ;
        }
        return level;
    }
};

// V2: DFS
// class Solution {
// public:
//     int M;
//     int N;
//     vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
//     int dfs(int x, int y, vector<vector<int>>& matrix, vector<vector<int>>& memo) {
//         if (memo[x][y] != -1) return memo[x][y];
//         int res = 1;
//         for (auto& direction : directions) {
//             int nextX = x + direction.first;
//             int nextY = y + direction.second;
//             if (nextX < 0 || nextX >= M || nextY < 0 || nextY >= N) continue;
//             if (matrix[nextX][nextY] <= matrix[x][y]) continue;
//             res = max(res, 1 + dfs(nextX, nextY, matrix, memo));
//         }
//         return memo[x][y] = res;
//     }
//     int longestIncreasingPath(vector<vector<int>>& matrix) {
//         M = matrix.size();
//         N = matrix[0].size();
//         vector<vector<int>> memo(M, vector<int>(N, -1));
//         int res = 0;
//         for (int i = 0; i < M; ++i) {
//             for (int j = 0; j < N; ++j) {
//                 int length = dfs(i, j, matrix, memo);
//                 res = max(res, length);
//             }
//         }
//         return res;
//     }
// };