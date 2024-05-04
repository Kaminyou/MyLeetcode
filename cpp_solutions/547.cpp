class DisjointSet {
private:
    vector<int> parents;
    vector<int> ranks;
    int nodes;
public:
    DisjointSet(int size) {
        this->nodes = size;
        parents.resize(size, 0);
        ranks.resize(size, 0);
        for (int i = 0; i < size; ++i) parents[i] = i;
    }
    int find(int x) {
        if (parents[x] != x) {
            parents[x] = find(parents[x]);
        }
        return parents[x];
    }
    void join(int x, int y) {
        int pX = find(x);
        int pY = find(y);
        if (pX == pY) return;
        nodes--;
        if (ranks[pY] > ranks[pX]) {
            parents[pX] = pY;
        }
        else if (ranks[pY] < ranks[pX]) {
            parents[pY] = pX;
        }
        else {
            parents[pY] = pX;
            ranks[pX]++;
        }
    }
    int getNodes() {
        return nodes;
    }
};
class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        DisjointSet* disjointSet = new DisjointSet(n);
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (isConnected[i][j]) disjointSet->join(i, j);
            }
        }
        return disjointSet->getNodes();
    }
};