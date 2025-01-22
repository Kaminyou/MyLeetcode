class Solution {
public:
    vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int m = isWater.size();
        int n = isWater[0].size();
        vector<vector<int>> res(m, vector<int>(n, 0));

        queue<pair<int, int>> q;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (isWater[i][j] == 1) {
                    q.push({i, j});
                    isWater[i][j] = -1;
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
                    if (isWater[nextX][nextY] == -1) continue;
                    isWater[nextX][nextY] = -1;
                    res[nextX][nextY] = length;
                    q.push({nextX, nextY});
                }
            }
            length++;
        }
        return res;
    }
};
