class Solution {
public:
    vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int M;
    int N;
    int position2idx(int x, int y) {
        return x * N + y;
    }
    void idx2position(int idx, int&x ,int &y) {
        x = idx / N;
        y = idx % N;
    }
    int countPaths(vector<vector<int>>& grid) {
        const long long mod = 1e9 + 7;
        long long res = 0;
        M = grid.size();
        N = grid[0].size();
        vector<vector<int>> mp(M * N);
        vector<int> inDegrees(M * N, 0);
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                for (auto& direction : directions) {
                    int x_ = i + direction.first;
                    int y_ = j + direction.second;
                    if (x_ < 0 || x_ >= M || y_ < 0 || y_ >= N) continue;
                    if (grid[x_][y_] <= grid[i][j]) continue;
                    mp[position2idx(i, j)].push_back(position2idx(x_, y_));
                    inDegrees[position2idx(x_, y_)]++;
                }
            }
        }
        vector<vector<long long>> dp(M, vector<long long>(N, 1));
        queue<int> q;
        for (int i = 0; i < M * N; ++i) {
            if (inDegrees[i] == 0) q.push(i);
        }
        while (!q.empty()) {
            int t = q.front();
            q.pop();
            int fx, fy;
            idx2position(t, fx, fy);
            for (auto neighbor : mp[t]) {
                inDegrees[neighbor]--;
                int x, y;
                idx2position(neighbor, x, y);
                dp[x][y] += dp[fx][fy];
                dp[x][y] %= mod;
                if (inDegrees[neighbor] == 0) q.push(neighbor);
            }
        }
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                res += dp[i][j];
                res %= mod;
            }
        }
        return res;
    }
};