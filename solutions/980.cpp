class Solution {
public:
    int endX;
    int endY;
    int M;
    int N;
    int position2idx(int x, int y) {
        return x * N + y;
    }
    vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int dp(int x, int y, int state) {
        if (__builtin_popcount(state) == M * N) {
            if (x == endX && y == endY) return 1;
            else return 0;
        }
        int position = position2idx(x, y);
        int res = 0;
        for (auto& direction : directions) {
            int _x = x + direction.first;
            int _y = y + direction.second;
            if (_x < 0 || _x >= M || _y < 0 ||_y >= N) continue;
            int idx = position2idx(_x, _y);
            if ((state & (1 << idx)) != 0) continue;
            res += dp(_x, _y, (state | (1 << idx)));
        }
        return res;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        M = grid.size();
        N = grid[0].size();
        int startX, startY;
        int mask = 0;
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                if (grid[i][j] == 1) {
                    startX = i;
                    startY = j;
                    mask |= (1 << position2idx(i, j));
                }
                else if (grid[i][j] == 2) {
                    endX = i;
                    endY = j;
                }
                else if (grid[i][j] == -1) {
                    mask |= (1 << position2idx(i, j));
                }
            }
        }
        return dp(startX, startY, mask);
    }
};

class Solution {
public:
    int M;
    int N;
    int pos2idx(int x, int y) {
        return x * N + y;
    }
    vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int dp(int x, int y, int step, int targetStep, int state, vector<vector<int>>& grid) {
        if (step == targetStep) {
            if (grid[x][y] == 2) return 1;
            else return 0;            
        }

        int sum = 0;
        for (auto& direction : directions) {
            int nextX = x + direction.first;
            int nextY = y + direction.second;
            if (nextX < 0 || nextX >= M || nextY < 0 || nextY >= N) continue;
            if (grid[nextX][nextY] == -1) continue;
            if (grid[nextX][nextY] == 1) continue;
            int nextState = state | (1 << pos2idx(nextX, nextY));
            if (state == nextState) continue;
            sum += dp(nextX, nextY, step + 1, targetStep, nextState, grid);
        }
        return sum;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        M = grid.size();
        N = grid[0].size();
        int state = 0;
        int startX = 0;
        int startY = 0;
        int targetStep = 0;
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                if (grid[i][j] == 1) {
                    startX = i;
                    startY = j;
                }
                else if (grid[i][j] == 0) targetStep++;
            }
        }
        state |= (1 << pos2idx(startX, startY));
        return dp(startX, startY, 0, targetStep + 1, state, grid);
    }
};