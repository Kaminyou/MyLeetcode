class Solution {
public:
    vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    void bfs(vector<pair<int, int>>& points, vector<vector<int>>& grid, int x, int y) {
        queue<pair<int, int>> q;
        q.push({x, y});
        grid[x][y] = 0;
        while (!q.empty()) {
            auto [currX, currY] = q.front();
            q.pop();
            points.push_back({currX, currY});
            for (auto& direction : directions) {
                int nextX = currX + direction.first;
                int nextY = currY + direction.second;
                if (nextX < 0 || nextX >= M || nextY < 0 || nextY >= N) continue;
                if (grid[nextX][nextY] == 0) continue;
                q.push({nextX, nextY});
                grid[nextX][nextY] = 0;
            }
        }
    }
    vector<pair<int, int>> normalize(vector<pair<int, int>>& points) {
        vector<vector<pair<int, int>>> rotatedPoints(8);
        for (auto& point : points) {
            auto [x, y] = point;
            rotatedPoints[0].push_back({x, y});
            rotatedPoints[1].push_back({-x, y});
            rotatedPoints[2].push_back({x, -y});
            rotatedPoints[3].push_back({-x, -y});
            rotatedPoints[4].push_back({y, x});
            rotatedPoints[5].push_back({-y, x});
            rotatedPoints[6].push_back({y, -x});
            rotatedPoints[7].push_back({-y, -x});
        }
        for (auto& singlePoints : rotatedPoints) {
            sort(singlePoints.begin(), singlePoints.end());
            int normalizeX = singlePoints[0].first;
            int normalizeY = singlePoints[0].second;
            for (auto& point : singlePoints) {
                point.first -= normalizeX;
                point.second -= normalizeY;
            }
        }
        sort(rotatedPoints.begin(), rotatedPoints.end());
        return rotatedPoints[0];
    }
    int M;
    int N;
    int numDistinctIslands2(vector<vector<int>>& grid) {
        M = grid.size();
        N = grid[0].size();
        set<vector<pair<int, int>>> st;
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                if (grid[i][j] == 1) {
                    vector<pair<int, int>> points;
                    bfs(points, grid, i, j);
                    st.insert(normalize(points));
                }
            }
        }
        return st.size();
    }
};