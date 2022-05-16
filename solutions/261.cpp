class DisjointSet {
private:
    vector<int> parent;
    vector<int> rank;
public:
    DisjointSet(int size) {
        parent.resize(size, 0);
        rank.resize(size, 0);
        for (int i = 0; i < size; i++) parent[i] = i;
    }
    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
    bool join(int x, int y) {
        int pX = find(x);
        int pY = find(y);
        if (pX == pY) return false;
        if (rank[pX] > rank[pY]) parent[pY] = pX;
        else if (rank[pX] < rank[pY]) parent[pX] = pY;
        else {
            parent[pY] = pX;
            rank[pX]++;
        }
        return true;
    }
};
class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        DisjointSet* disjointSet = new DisjointSet(n);
        for (auto edge : edges) {
            if (!disjointSet->join(edge[0], edge[1])) return false;
        }
        int parent = disjointSet->find(0);
        for (int i = 1; i < n; i++) {
            if (disjointSet->find(i) != parent) return false;
        }
        return true;
    }
};