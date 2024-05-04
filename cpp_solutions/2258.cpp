class Solution {
public:
    int M;
    int N;
    vector<pair<int, int>> fireInit;
    vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    bool reachable(vector<vector<int>>& grid, int time) {
        // can reach bottom right with time delay
        vector<vector<int>> gridCopy = grid;
        queue<pair<int, pair<int, int>>> q;
        set<pair<int, int>> st;
        if (time == 0) {
            q.push({4, {0, 0}});
            gridCopy[0][0] = 3;
        }
        for (auto fire : fireInit) {
            q.push({3, {fire.first, fire.second}});
            gridCopy[fire.first][fire.second] = 1;
        }
        
        int level = 0;
        while (!q.empty() || level < time) {
            int k = q.size();
            if (level + 1 <= time && gridCopy[0][0] == 1) return false;
            if (level + 1 == time) {
                q.push({4, {0, 0}});
                gridCopy[0][0] = 3;
            }
            for (int i = 0; i < k; ++i) {
                auto [obj, position] = q.front();
                auto [x, y] = position;
                q.pop();
                if (obj == 4 && st.find({x, y}) != st.end()) continue;
                for (auto& direction : directions) {
                    int nextX = x + direction.first;
                    int nextY = y + direction.second;
                    if (nextX < 0 || nextX >= M || nextY < 0 || nextY >= N) continue;
                    if (nextX == M - 1 && nextY == N - 1 && obj == 4 && gridCopy[nextX][nextY] == 0) return true;
                    if (gridCopy[nextX][nextY] == 2) continue;
                    
                    // fire
                    if (obj == 3) {
                        if (gridCopy[nextX][nextY] == 1) continue;
                        if (gridCopy[nextX][nextY] == 3) st.insert({nextX, nextY});
                        q.push({obj, {nextX, nextY}});
                        gridCopy[nextX][nextY] = 1;
                    }
                    // person
                    else if (obj == 4) {
                        if (gridCopy[nextX][nextY] == 3) continue;
                        if (gridCopy[nextX][nextY] == 1) continue;
                        q.push({obj, {nextX, nextY}});
                        gridCopy[nextX][nextY] = 3;
                    }
                }
            }
            level++;
        }
        return false;
    }
    int maximumMinutes(vector<vector<int>>& grid) {
        M = grid.size();
        N = grid[0].size();
        
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                if (grid[i][j] == 1) fireInit.push_back({i, j});
            }
        }

        int left = 0;
        int right = M * N;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (!reachable(grid, mid)) right = mid;
            else left = mid + 1;
        }
        if (left == M * N) return 1000000000;
        return left - 1;
    }
};