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
        if (pX != pY) {
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
};
class Solution {
public:
    int kruskal(int n, vector<vector<int>>& edges, int skip) {
        int res = 0;
        DisjointSet* disjointSet = new DisjointSet(n);
        for (int i = 0; i < edges.size(); ++i) {
            if (i == skip) continue;
            auto edge = edges[i];
            int pA = disjointSet->find(edge[0]);
            int pB = disjointSet->find(edge[1]);
            if (pA == pB) continue;
            res += edge[2];
            disjointSet->join(edge[0], edge[1]);
        }
        for (int i = 0; i < n; ++i) {
            if (disjointSet->find(i) != disjointSet->find(0)) return INT_MAX;
        }
        return res;
    }
    static bool compare(vector<int>& v1, vector<int>& v2) {
        return (v1[2] < v2[2]);
    }
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        int m = edges.size();
        for (int i = 0; i < m; ++i) {
            edges[i].push_back(i);
        }
        sort(edges.begin(), edges.end(), compare);

        unordered_set<int> set1;
        unordered_set<int> set2;
        int minMSTValue = kruskal(n, edges, -1);
        for (int i = 0; i < m; ++i) {
            int MSTValue = kruskal(n, edges, i);
            if (MSTValue > minMSTValue) set1.insert(edges[i][3]);
        }

        for (int i = 0; i < m; ++i) {
            if (set1.find(edges[i][3]) != set1.end()) continue;
            int edgeIdx = edges[i][3];
            auto edge = edges[i];
            edges.insert(edges.begin(), edge);
            int MSTValue = kruskal(n, edges, -1);
            if (MSTValue == minMSTValue) {
                set2.insert(edgeIdx);
            }
            edges.erase(edges.begin());
        }
        vector<int> res1(set1.begin(), set1.end());
        vector<int> res2(set2.begin(), set2.end());
        return {res1, res2};
    }
};