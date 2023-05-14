class DisjointSet {
private:
    vector<int> parent;
    vector<int> rank;
    vector<int> nodes;
public:
    DisjointSet(int size) {
        parent.resize(size, 0);
        for (int i = 0; i < size; ++i) parent[i] = i;
        rank.resize(size, 0);
        nodes.resize(size, 1);
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
        if (rank[pX] > rank[pY]) {
            parent[pY] = pX;
            nodes[pX] += nodes[pY];
        }
        else if (rank[pX] < rank[pY]) {
            parent[pX] = pY;
            nodes[pY] += nodes[pX];
        }
        else {
            parent[pY] = pX;
            nodes[pX] += nodes[pY];
            rank[pX]++;
        }
    }
    int getNodes(int x) {
        int parent = find(x);
        return nodes[parent];
    }
};
class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        DisjointSet* disjointSet = new DisjointSet(n);
        for (auto& edge : edges) {
            disjointSet->join(edge[0], edge[1]);
        }
        unordered_map<int, int> parent2edgeCnt;
        for (auto& edge : edges) {
            int parent = disjointSet->find(edge[0]);
            parent2edgeCnt[parent]++;
        }
        int res = 0;
        for (auto& [parent, cnt] : parent2edgeCnt) {
            int nodes = disjointSet->getNodes(parent);
            if ((nodes * (nodes - 1)) / 2 == cnt) res++;
        }
        for (int i = 0; i < n; ++i) {
            if (disjointSet->getNodes(i) == 1) res++;
        }
        return res;
    }
};