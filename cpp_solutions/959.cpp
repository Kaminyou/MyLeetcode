class DisjointSet {
private:
    vector<int> parent;
    vector<int> rank;
    int remain;
public:
    DisjointSet(int size) {
        parent.resize(size, 0);
        rank.resize(size, 0);
        remain = size;
        for (int i = 0; i < size; ++i) parent[i] = i;
    }
    int find(int x) {
        if (x != parent[x]) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
    void join(int x, int y) {
        int parentX = find(x);
        int parentY = find(y);
        if (parentX == parentY) return;
        remain--;
        if (rank[parentX] > rank[parentY]) {
            parent[parentY] = parentX;
        }
        else if (rank[parentX] < rank[parentY]) {
            parent[parentX] = parentY;
        }
        else {
            parent[parentY] = parentX;
            rank[parentX]++;
        }
    }
    int getRemain() {
        return remain;
    }
};
class Solution {
public:
    int regionsBySlashes(vector<string>& grid) {
        int n = grid.size();
        DisjointSet* disjointSet = new DisjointSet(n * n * 4);
        
        int rowExpand = n * 4;
        
        // 0 up; 1 right; 2 down; 3 left
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == ' ') {
                    disjointSet->join(i * rowExpand + j * 4 + 0, i * rowExpand + j * 4 + 1);
                    disjointSet->join(i * rowExpand + j * 4 + 1, i * rowExpand + j * 4 + 2);
                    disjointSet->join(i * rowExpand + j * 4 + 2, i * rowExpand + j * 4 + 3);
                    disjointSet->join(i * rowExpand + j * 4 + 0, i * rowExpand + j * 4 + 3);
                }
                else if (grid[i][j] == '/') {
                    disjointSet->join(i * rowExpand + j * 4 + 0, i * rowExpand + j * 4 + 3);
                    disjointSet->join(i * rowExpand + j * 4 + 1, i * rowExpand + j * 4 + 2);
                }
                else {
                    disjointSet->join(i * rowExpand + j * 4 + 0, i * rowExpand + j * 4 + 1);
                    disjointSet->join(i * rowExpand + j * 4 + 2, i * rowExpand + j * 4 + 3);
                }
                // up
                if (i > 0) {
                    disjointSet->join(i * rowExpand + j * 4 + 0, (i - 1) * rowExpand + j * 4 + 2);
                }
                // down
                if (i < n - 1) {
                    disjointSet->join(i * rowExpand + j * 4 + 2, (i + 1) * rowExpand + j * 4 + 0);
                }
                // left
                if (j > 0) {
                    disjointSet->join(i * rowExpand + j * 4 + 3, i * rowExpand + (j - 1) * 4 + 1);
                }
                // right
                if (j < n - 1) {
                    disjointSet->join(i * rowExpand + j * 4 + 1, i * rowExpand + (j + 1) * 4 + 3);
                }
            }
        }
        return disjointSet->getRemain();
    }
};