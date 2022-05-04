class Solution {
public:
    bool check(int x, int y, int m, int n, vector<vector<int>>& maze) {
        if (x < 0 || x >= m) return false;
        if (y < 0 || y >= n) return false;
        if (maze[x][y] != 0) return false;
        return true;
    }
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        int m = maze.size();
        int n = maze[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        
        vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        queue<pair<int, int>> q;
        q.push(make_pair(start[0], start[1]));
        visited[start[0]][start[1]] = true;
        
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            if (x == destination[0] && y == destination[1]) return true;
            for (auto direction : directions) {
                int _x = x;
                int _y = y;
                while (check(_x + direction.first, _y + direction.second, m, n, maze)) {
                    _x += direction.first;
                    _y += direction.second;
                }
                if (visited[_x][_y]) continue;
                q.push(make_pair(_x, _y));
                visited[_x][_y] = true;
            }
        }
        return false;
    }
};