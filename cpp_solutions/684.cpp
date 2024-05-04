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
    bool merge(int x, int y) {
        int gX = find(x);
        int gY = find(y);
        if (gX == gY) return false;
        if (rank[gX] > rank[gY]) parent[gY] = gX;
        else if (rank[gX] < rank[gY]) parent[gX] = gY;
        else {
            parent[gY] = gX;
            rank[gX]++;
        }
        return true;
    }
};
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size() + 1;
        DisjointSet* disjointSet = new DisjointSet(n);
        for (auto edge : edges) {
            if (!disjointSet->merge(edge[0], edge[1])) return edge;
        }
        return {};
    }
};