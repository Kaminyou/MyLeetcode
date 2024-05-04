class Solution {
public:
    vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> res(m, vector<int>(n, 0));

        queue<pair<int, int>> q;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (mat[i][j] == 0) {
                    q.push({i, j});
                    mat[i][j] = -1;
                }
            }
        }
        int length = 1;
        while (!q.empty()) {
            int k = q.size();
            while (k--) {
                auto [x, y] = q.front();
                q.pop();
                for (auto direction : directions) {
                    int nextX = x + direction.first;
                    int nextY = y + direction.second;
                    if (nextX < 0 || nextX >= m || nextY < 0 || nextY >= n) continue;
                    if (mat[nextX][nextY] == -1) continue;
                    mat[nextX][nextY] = -1;
                    res[nextX][nextY] = length;
                    q.push({nextX, nextY});
                }
            }
            length++;
        }
        return res;
    }
};