class DisjointSet {
private:
    vector<int> parent;
    vector<int> rank;
public:
    DisjointSet(int size) {
        parent.resize(size, 0);
        for (int i = 0; i < size; ++i) parent[i] = i;
        rank.resize(size, 0);
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
    int minScore(int n, vector<vector<int>>& roads) {
        // the min road in the conntect component
        DisjointSet* disjointSet = new DisjointSet(n);
        for (auto& road : roads) {
            disjointSet->join(road[0] - 1, road[1] - 1);
        }
        int targetParent = disjointSet->find(n - 1);
        int minRoad = INT_MAX;
        for (auto& road : roads) {
            if (disjointSet->find(road[0] - 1) == targetParent && disjointSet->find(road[1] - 1) == targetParent) {
                minRoad = min(minRoad, road[2]);
            }
        }
        return minRoad;
    }
};