class DisjointSet {
private:
    vector<int> parent;
    vector<int> rank;
    int n;
public:
    DisjointSet(int size) {
        n = size;
        parent.resize(size, 0);
        rank.resize(size, 0);
        for (int i = 0; i < n; ++i) parent[i] = i;
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
        if (pX != pY) {
            n--;
            if (rank[pX] > rank[pY]) {
                parent[pY] = parent[pX];
            }
            else if (rank[pX] < rank[pY]) {
                parent[pX] = parent[pY];
            }
            else {
                parent[pY] = parent[pX];
                rank[pX]++;
            }
        }
    }
    int size() {
        return n;
    }
};
class Solution {
public:
    bool isSimilar(const string& s1, const string& s2) {
        int n = s1.size();
        int m = s2.size();
        if (n != m) return false;
        int diffCount = 0;
        int diffOne = -1, diffTwo = -1;
        for (int i = 0; i < n; ++i) {
            if (s1[i] != s2[i]) {
                diffCount++;
                if (diffCount == 1) diffOne = i;
                else if (diffCount == 2) diffTwo = i;
                else return false;
            }
        }
        if (diffCount <= 1) return true;
        if (s1[diffOne] != s2[diffTwo]) return false;
        if (s1[diffTwo] != s2[diffOne]) return false;
        return true;
    }
    int numSimilarGroups(vector<string>& strs) {
        int n = strs.size();
        DisjointSet* disjointSet = new DisjointSet(n);
        vector<pair<int, int>> edges;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (isSimilar(strs[i], strs[j])) disjointSet->join(i, j);
            }
        }
        return disjointSet->size();
    }
};