typedef pair<int, pair<int, int>> P;
class Solution {
public:
    vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int trapRainWater(vector<vector<int>>& heightMap) {
        int res = 0;
        priority_queue<P, vector<P>, greater<P>> pq;
        int m = heightMap.size();
        int n = heightMap[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for (int i = 0; i < m; ++i) {
            pq.push(make_pair(heightMap[i][0], make_pair(i, 0)));
            visited[i][0] = true;
            pq.push(make_pair(heightMap[i][n - 1], make_pair(i, n - 1)));
            visited[i][n - 1] = true;
        }
        for (int j = 0; j < n; ++j) {
            pq.push(make_pair(heightMap[0][j], make_pair(0, j)));
            visited[0][j] = true;
            pq.push(make_pair(heightMap[m - 1][j], make_pair(m -1, j)));
            visited[m - 1][j] = true;
        }
        
        while (!pq.empty()) {
            auto [height, position] = pq.top();
            auto [x, y] = position;
            pq.pop();
            
            queue<pair<int, int>> q;
            q.push(position);
            while (!q.empty()) {
                auto [currX, currY] = q.front();
                q.pop();
                for (auto& direction : directions) {
                    int nextX = currX + direction.first;
                    int nextY = currY + direction.second;
                    if (nextX < 0 || nextX >= m || nextY < 0 || nextY >= n) continue;
                    if (visited[nextX][nextY] == true) continue;
                    visited[nextX][nextY] = true;
                    if (heightMap[nextX][nextY] > height) {
                        pq.push(make_pair(heightMap[nextX][nextY], make_pair(nextX, nextY)));
                    }
                    else {
                        res += height - heightMap[nextX][nextY];
                        q.push(make_pair(nextX, nextY));
                    }
                }
            }
        }
        return res;
    }
};