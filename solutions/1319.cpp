class DisjointSet {
public:
    vector<int> parent;
    vector<int> rank;
    int groups;
    DisjointSet(int n) {
        parent.resize(n, 0);
        for (int i = 0; i < n; ++i) parent[i] = i;
        rank.resize(n, 0);
        groups = n;
    }
    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
    void join(int x, int y) {
        int pX = find(x);
        int pY = find(y);
        if (pX == pY) return;
        groups--;
        if (rank[pX] > rank[pY]) {
            parent[pY] = pX;
        }
        else if (rank[pX] < rank[pY]) {
            parent[pX] = pY;
        }
        else {
            parent[pY] = pX;
            rank[pX]++;
        }
    }
};
class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        int m = connections.size();
        if (m < n - 1) return -1;
        DisjointSet* disjointSet = new DisjointSet(n);
        for (auto& connection : connections) {
            disjointSet->join(connection[0], connection[1]);
        }
        return disjointSet->groups - 1;
    }
};