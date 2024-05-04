class DisjointSet {
private:
    vector<int> parent;
    vector<int> rank;
    int groups = 0;
public:
    DisjointSet(int size) {
        parent.resize(size, 0);
        rank.resize(size, 0);
        for (int i = 0; i < size; ++i) parent[i] = i;
        groups = size;
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
    bool isAllConnected() {
        return groups == 1;
    }
};
class Solution {
public:
    int earliestAcq(vector<vector<int>>& logs, int n) {
        DisjointSet* disjointSet = new DisjointSet(n);
        sort(logs.begin(), logs.end());
        for (auto& log : logs) {
            disjointSet->join(log[1], log[2]);
            if (disjointSet->isAllConnected()) return log[0];
        }
        return -1;
    }
};