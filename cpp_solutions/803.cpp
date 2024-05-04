class DisjointSet {
private:
    vector<int> parent;
    vector<int> rank;
    vector<int> size;
    vector<pair<int, int>> directions;
public:
    DisjointSet(int n) {
        parent = vector<int>(n, 0);
        rank = vector<int>(n, 0);
        size = vector<int>(n, 1);
        for (int i = 0; i < n; i++) parent[i] = i;
        directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    }
    int getSize(int x) {
        return size[find(x)];
    }
    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
    void join(int x, int y) {
        int xP = find(x);
        int yP = find(y);
        if (xP == yP) return;
        if (rank[xP] > rank[yP]) {
            parent[yP] = xP;
            size[xP] += size[yP];
        }
        else if (rank[xP] < rank[yP]) {
            parent[xP] = yP;
            size[yP] += size[xP];
        }
        else {
            parent[yP] = xP;
            size[xP] += size[yP];
            rank[xP]++;
        }
    }
    void joinNeighbor(int x, int y, vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int currIdx = x * n + y + 1;
        for (auto direction : directions) {
            int _x = x + direction.first;
            int _y = y + direction.second;
            if (_x < 0 || _x >= m || _y < 0 || _y >= n || grid[_x][_y] != 1) continue;
            int neighborIdx = _x * n + _y + 1;
            join(currIdx, neighborIdx);
        }
        if (x == 0) join(0, currIdx);
    }
};
class Solution {
public:
    vector<int> hitBricks(vector<vector<int>>& grid, vector<vector<int>>& hits) {
        int m = grid.size();
        int n = grid[0].size();
        DisjointSet* disjointSet = new DisjointSet(m * n + 1);
        
        for (auto hit : hits) {
            if (grid[hit[0]][hit[1]] == 1) grid[hit[0]][hit[1]] = 2;
        }
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) disjointSet->joinNeighbor(i, j, grid);
            }
        }

        vector<int> res(hits.size(), 0);
        int currSize = disjointSet->getSize(0);
        for (int i = hits.size() - 1; i >= 0; i--) {
            int x = hits[i][0];
            int y = hits[i][1];
            if (grid[x][y] == 2) {
                grid[x][y] = 1;
                disjointSet->joinNeighbor(x, y, grid);
            }
            int tempSize = disjointSet->getSize(0);
            if (tempSize > currSize) {
                res[i] = tempSize - currSize - 1;
                currSize = tempSize;
            }
        }
        return res;
    }
};