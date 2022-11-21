class Solution {
public:
    vector<pair<int, int>> directions = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int m = maze.size();
        int n = maze[0].size();
        queue<pair<int, int>> q;
        q.push({entrance[0], entrance[1]});
        maze[entrance[0]][entrance[1]] = '+';
        int level = 0;
        while (!q.empty()) {
            int k = q.size();
            for (int i = 0; i < k; ++i) {
                auto [x, y] = q.front();
                q.pop();
                for (auto& direction : directions) {
                    int nextX = x + direction.first;
                    int nextY = y + direction.second;
                    if (nextX < 0 || nextX >= m || nextY < 0 || nextY >= n) continue;
                    if (maze[nextX][nextY] == '+') continue;
                    if (nextX == 0 || nextX == m - 1|| nextY == 0 || nextY == n - 1) return level + 1;
                    q.push({nextX, nextY});
                    maze[nextX][nextY] = '+';
                }
            }
            level++;
        }
        return -1;
    }
};