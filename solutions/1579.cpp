class DisjointSet {
private:
    vector<int> parent;
    vector<int> rank;
    int group;
public:
    DisjointSet(int n) {
        parent.resize(n, 0);
        rank.resize(n, 0);
        for (int i = 0; i < n; ++i) parent[i] = i;
        group = n;
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
        group--;
        if (rank[pX] > rank[pY]) {
            parent[pY] = pX;
        }
        else if (rank[pX] < rank[pY]) {
            parent[pX] = pY;
        }
        else {
            rank[pX]++;
            parent[pY] = pX;
        }
        return true;
    }
    bool isFullConnected() {
        return group == 1;
    }
};
class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        DisjointSet* aliceSet = new DisjointSet(n);
        DisjointSet* bobSet = new DisjointSet(n);
        int res = 0;
        int index = 0;
        for (auto& edge : edges) {
            if (edge[0] == 3) {
                bool result = aliceSet->join(edge[1] - 1, edge[2] - 1);
                bobSet->join(edge[1] - 1, edge[2] - 1);
                if (result == false) res++;
            }
        }
        for (auto& edge : edges) {
            if (edge[0] == 2) {
                bool result = bobSet->join(edge[1] - 1, edge[2] - 1);
                if (result == false) res++;
            }
        }
        for (auto& edge : edges) {
            if (edge[0] == 1) {
                bool result = aliceSet->join(edge[1] - 1, edge[2] - 1);
                if (result == false) res++;
            }
        }
        if (aliceSet->isFullConnected() && bobSet->isFullConnected()) {
            return res;
        }
        return -1;
    }
};
