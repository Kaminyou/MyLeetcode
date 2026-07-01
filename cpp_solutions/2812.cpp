class Solution {
public:
    vector<pair<int ,int >> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();
        queue<pair<int, int>> q;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) q.push({i, j});
            }
        }

        while (!q.empty()) {
            auto [i, j] = q.front();
            q.pop();
            for (auto& direction : directions) {
                int x = i + direction.first;
                int y = j + direction.second;
                if (x < 0 || x >= n || y < 0 || y >= n) continue;
                if (grid[x][y] != 0) continue;
                grid[x][y] = grid[i][j] + 1;
                q.push({x, y});
            }
        }

        priority_queue<tuple<int, int, int>> pq;
        pq.push({grid[0][0], 0, 0});
        while (get<1>(pq.top()) < n - 1 || get<2>(pq.top()) < n - 1) {
            auto [val, i, j] = pq.top();
            pq.pop();
            for (auto& direction : directions) {
                int x = i + direction.first;
                int y = j + direction.second;
                if (x < 0 || x >= n || y < 0 || y >= n) continue;
                if (grid[x][y] < 0) continue;
                pq.push({min(val, grid[x][y]), x, y});
                grid[x][y] *= -1;
            }
        }
        return get<0>(pq.top()) - 1;
    }
};

class DisjointSet {
private:
    vector<int> parents;
    vector<int> ranks;
public:
    DisjointSet(int n) {
        parents.resize(n, 0);
        ranks.resize(n, 0);
        for (int i = 0; i < n; ++i) {
            parents[i] = i;
        }
    }
    int find(int x) {
        if (parents[x] == x) return parents[x];
        return parents[x] = find(parents[x]);
    }
    void join(int x, int y) {
        int pX = find(x);
        int pY = find(y);
        if (pX == pY) return;
        if (ranks[pX] > ranks[pY]) parents[pY] = pX;
        else if (ranks[pX] < ranks[pY]) parents[pX] = pY;
        else {
            parents[pY] = pX;
            ranks[pX]++;
        }
    }
};
class Solution {
public:
    vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> distances(n, vector<int>(n, INT_MAX));
        queue<pair<int, int>> q;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    q.push({i, j});
                    distances[i][j] = 0;
                }
            }
        }
        while (!q.empty()) {
            int m = q.size();
            while (m--) {
                auto [x, y] = q.front();
                int curr = distances[x][y];
                q.pop();
                for (auto& direction : directions) {
                    int xx = x + direction.first;
                    int yy = y + direction.second;
                    if (xx < 0 || xx >= n || yy < 0 || yy >= n) continue;
                    if (distances[xx][yy] != INT_MAX) continue;
                    distances[xx][yy] = curr + 1;
                    q.push({xx, yy});
                }
            }
        }
        vector<pair<int, pair<int, int>>> v;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                v.push_back({-distances[i][j], {i, j}});
            }
        }
        sort(v.begin(), v.end());
        DisjointSet* disjointSet = new DisjointSet(n * n);
        for (auto& vv : v) {
            auto [d, p] = vv;
            auto [x, y] = p;
            for (auto& direction : directions) {
                int xx = x + direction.first;
                int yy = y + direction.second;
                if (xx < 0 || xx >= n || yy < 0 || yy >= n) continue;
                if (distances[xx][yy] < -d) continue;
                disjointSet->join(x * n + y, xx * n + yy);
            }
            if (disjointSet->find(0) == disjointSet->find(n * n - 1)) return -d;
        }
        return -1;
    }
};

