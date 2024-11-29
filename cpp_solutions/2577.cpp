typedef pair<int, pair<int, int>> P;
class Solution {
public:
    vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int minimumTime(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        priority_queue<P, vector<P>, greater<P>> pq;
        if (grid[1][0] > 1 && grid[0][1] > 1) return -1;
        if (grid[1][0] <= 1) pq.push({1, {1, 0}}); 
        if (grid[0][1] <= 1) pq.push({1, {0, 1}});
        while (!pq.empty()) {
            P p = pq.top();
            pq.pop();
            int t = p.first;
            int x = p.second.first;
            int y = p.second.second;
            if (visited[x][y]) continue;
            visited[x][y] = true;

            if (x == m - 1 && y == n - 1) return t;
            for (auto& direction : directions) {
                int nextX = x + direction.first;
                int nextY = y + direction.second;
                if (nextX < 0 || nextX >= m || nextY < 0 || nextY >= n) continue;
                if (visited[nextX][nextY]) continue;
                if (grid[nextX][nextY] <= t + 1) {
                    pq.push({t + 1, {nextX, nextY}});
                }
                else if ((grid[nextX][nextY] - t) & 1) {
                    pq.push({grid[nextX][nextY], {nextX, nextY}});
                }
                else {
                    pq.push({grid[nextX][nextY] + 1, {nextX, nextY}});
                }
            }
        } 
        return -1;
    }
};
