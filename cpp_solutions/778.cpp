typedef tuple<int, int, int> T;
class Solution {
public:
    vector<pair<int, int>> directions = {{0, 1}, {0, - 1}, {1, 0}, {-1, 0}};
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        
        priority_queue<T, vector<T>, greater<T>> pq;
        pq.push(make_tuple(grid[0][0], 0, 0));
        
        int res = 0;
        while (!pq.empty()) {
            auto t = pq.top();
            pq.pop();
            int level = get<0>(t);
            int x = get<1>(t);
            int y = get<2>(t);
            
            res = max(res, level);
            if (x == n - 1 && y == n - 1) return res;
            for (auto& direction : directions) {
                int nextX = x + direction.first;
                int nextY = y + direction.second;
                if (nextX < 0 || nextX >= n || nextY < 0 || nextY >= n) continue;
                if (visited[nextX][nextY]) continue;
                pq.push(make_tuple(grid[nextX][nextY], nextX, nextY));
                visited[nextX][nextY] = true;
            }
        }
        return -1;
    }
};

class DisjointSet {
private:
    vector<int> parents;
    vector<int> ranks;
public:
    DisjointSet(int n) {
        parents.resize(n, 0);
        for (int i = 0; i < n; ++i) {
            parents[i] = i;
        }
        ranks.resize(n, 0);
    }
    int find(int x) {
        if (x != parents[x]) {
            parents[x] = find(parents[x]);
        }
        return parents[x];
    }
    void join(int x, int y) {
        int pX = find(x);
        int pY = find(y);
        if (pX == pY) return;
        if (ranks[pX] >= ranks[pY]) {
            parents[pY] = pX;
            ranks[pX]++;
        }
        else {
            parents[pX] = pY;
            ranks[pY]++;
        }
    }
};
class Solution {
public:
    int N;
    vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int grid2index(int x, int y) {
        return x * N + y;
    }
    pair<int, int> index2grid(int index) {
        int x = index / N;
        int y = index % N;
        return {x, y};
    }
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        N = n;
        DisjointSet* disjointSet = new DisjointSet(n * n);
        vector<pair<int, int>> v;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                int value = grid[i][j];
                int index = grid2index(i, j);
                v.push_back({value, index});
            }
        }
        sort(v.begin(), v.end());
        for (int i = 0; i < n * n; ++i) {
            int value = v[i].first;
            int index = v[i].second;
            pair<int, int> p = index2grid(index);
            for (auto& direction : directions) {
                int xx = direction.first + p.first;
                int yy = direction.second + p.second;
                if (xx < 0 || xx >= n || yy < 0 || yy >= n) continue;
                if (grid[xx][yy] > grid[p.first][p.second]) continue;
                int nextIndex = grid2index(xx, yy);
                disjointSet->join(index, nextIndex);
            }
            if (disjointSet->find(0) == disjointSet->find(n * n - 1)) return value;
        }
        return -1;
    }
};
