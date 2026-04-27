class Solution {
public:
    vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}}; // right, left, down, up
    bool valid(int s1, int s2, int direction) {
        if (s1 == 1) {
            if (direction == 0) return (s2 == 1 || s2 == 3 || s2 == 5);
            if (direction == 1) return (s2 == 1 || s2 == 4 || s2 == 6);
            return false;
        }
        if (s1 == 2) {
            if (direction == 2) return (s2 == 2 || s2 == 5 || s2 == 6);
            if (direction == 3) return (s2 == 2 || s2 == 3 || s2 == 4);
            return false;
        }
        if (s1 == 3) {
            if (direction == 1) return (s2 == 1 || s2 == 4 || s2 == 6);
            if (direction == 2) return (s2 == 2 || s2 == 4 || s2 == 6);
            return false;
        }
        if (s1 == 4) {
            if (direction == 0) return (s2 == 1 || s2 == 3 || s2 == 5);
            if (direction == 2) return (s2 == 2 || s2 == 4 || s2 == 6);
            return false;
        }
        if (s1 == 5) {
            if (direction == 1) return (s2 == 1 || s2 == 4 || s2 == 6);
            if (direction == 3) return (s2 == 2 || s2 == 3 || s2 == 4);
            return false;
        }
        if (s1 == 6) {
            if (direction == 0) return (s2 == 1 || s2 == 3 || s2 == 5);
            if (direction == 2) return (s2 == 2 || s2 == 4 || s2 == 6);
            return false;
        }
        return false;
    }
    bool hasValidPath(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        queue<pair<int, int>> q;
        q.push({0, 0});
        while (!q.empty()) {
            int k = q.size();
            while (k--) {
                auto [y, x] = q.front();
                cout << y << " " << x << endl;
                if (y == m - 1 && x == n - 1) return true;
                q.pop();
                int s1 = grid[y][x];
                for (int t = 0; t < 4; ++t) {
                    auto [d1, d2] = directions[t];
                    int yy = y + d1;
                    int xx = x + d2;
                    if (yy < 0 || yy >= m || xx < 0 || xx >= n) continue;
                    if (visited[yy][xx]) continue;
                    int s2 = grid[yy][xx];
                    if (valid(s1, s2, t)) {
                        q.push({yy, xx});
                        visited[yy][xx] = true;
                    }
                }
            }
        }
        return false;
    }
};
