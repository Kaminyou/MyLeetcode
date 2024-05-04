typedef pair<int, pair<int, int>> P;
class Solution {
public:
    int minimumVisitedCells(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> minDist(m, vector<int>(n, INT_MAX));
        priority_queue<P> pq;
        pq.push({-1, {0, 0}});
        minDist[0][0] = 0;
        
        while (!pq.empty()) {
            auto p = pq.top();
            int d = -p.first;
            int x = p.second.first;
            int y = p.second.second;
            pq.pop();
            if (x == m - 1 && y == n - 1) return d;
            int move = grid[x][y];
            for (int k = 1; k <= move; ++k) {
                int nextX = x + k;
                int nextY = y + k;
                if (nextX < m && minDist[nextX][y] > d + 1) {
                    minDist[nextX][y] = d + 1;
                    pq.push({-(d + 1), {nextX, y}});
                }
                if (nextY < n && minDist[x][nextY] > d + 1) {
                    minDist[x][nextY] = d + 1;
                    pq.push({-(d + 1), {x, nextY}});
                }
                if (nextX >= m && nextY >= n) break;
            }
        }
        return -1;
    }
};