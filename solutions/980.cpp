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