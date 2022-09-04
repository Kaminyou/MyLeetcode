class DisjointSet {
private:
    vector<int> parent;
    vector<int> rank;
public:
    DisjointSet(int size) {
        parent.resize(size, 0);
        rank.resize(size, 0);
        for (int i = 0; i < size; ++i) parent[i] = i;
    }
    int find(int x) {
        if (x != parent[x]) {
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
    int minSwapsCouples(vector<int>& row) {
        int n = row.size();
        DisjointSet* disjointSet = new DisjointSet(n / 2);
        int res = 0;
        for (int i = 0; i < n; i += 2) {
            int pA = disjointSet->find(row[i] / 2);
            int pB = disjointSet->find(row[i + 1] / 2);
            if (pA != pB) {
                disjointSet->join(pA, pB);
                res++;
            }
        }
        return res;
    }
};