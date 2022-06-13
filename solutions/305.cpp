class DisjointSet {
private:
    vector<int> parent;
    vector<int> rank;
    int groups;
    int M;
    int N;
public:
    DisjointSet(int m, int n) {
        M = m;
        N = n;
        parent.resize(M * N, -1);
        rank.resize(M * N, 0);
        groups = 0;
    }
    int anchorToNode(int x, int y) {
        return x * N + y;
    }
    void addNode(int x, int y) {
        int node = anchorToNode(x, y);
        if (parent[node] != -1) return;
        parent[node] = node;
        groups++;
    }
    int _find(int node) {
        if (parent[node] != node) {
            parent[node] = _find(parent[node]);
        }
        return parent[node];
    }
    int find(int x, int y) {
        int node = anchorToNode(x, y);
        return _find(node);
    }
    void join(int x1, int y1, int x2, int y2) {
        int node1 = anchorToNode(x1, y1);
        int node2 = anchorToNode(x2, y2);
        if (parent[node2] == -1) return;
        int p1 = _find(node1);
        int p2 = _find(node2);
        if (p1 != p2) {
            groups--;
            if (rank[p1] > rank[p2]) {
                parent[p2] = p1;
            }
            else if (rank[p1] < rank[p2]) {
                parent[p1] = p2;
            }
            else {
                parent[p2] = p1;
                rank[p1]++;
            }
        }
    }
    int getGroup() {
        return groups;
    }
};
class Solution {
public:
    vector<int> numIslands2(int m, int n, vector<vector<int>>& positions) {
        vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        DisjointSet* disjointSet = new DisjointSet(m, n);
        vector<int> res;
        for (auto& position : positions) {
            int x = position[0];
            int y = position[1];
            disjointSet->addNode(x, y);
            for (auto& direction : directions) {
                int _x = x + direction.first;
                int _y = y + direction.second;
                if (_x < 0 || _x >= m || _y < 0 || _y >= n) continue;
                disjointSet->join(x, y, _x, _y);
            }
            int groups = disjointSet->getGroup();
            res.push_back(groups);
        }
        return res;
    }
};