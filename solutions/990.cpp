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
    bool equationsPossible(vector<string>& equations) {
        DisjointSet* disjointSet = new DisjointSet(26);
        for (auto& equation : equations) {
            if (equation[1] == '=') disjointSet->join(equation[0] - 'a', equation[3] - 'a');
        }
        for (auto& equation : equations) {
            if (equation[1] == '!') {
                int pA = disjointSet->find(equation[0] - 'a');
                int pB = disjointSet->find(equation[3] - 'a');
                if (pA == pB) return false;
            }
        }
        return true;
    }
};