class DisjointSet {
private:
    vector<int> parent;
    vector<int> rank;
public:
    DisjointSet(int size) {
        parent.resize(size, 0);
        rank.resize(size, 0);
        for (int i = 0; i < size; i++) parent[i] = i;
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
        if (rank[pX] > rank[pY]) parent[pY] = pX;
        else if (rank[pX] < rank[pY]) parent[pX] = pY;
        else {
            parent[pY] = pX;
            rank[pX]++;
        }
    }
};
class Solution {
public:
    long long countPairs(int n, vector<vector<int>>& edges) {
        DisjointSet* disjointSet = new DisjointSet(n);
        for (auto& edge : edges) disjointSet->join(edge[0], edge[1]);
        unordered_map<int, int> mp;
        for (int i = 0; i < n; ++i) {
            int parent = disjointSet->find(i);
            mp[parent]++;
        }
        long long res = 0;
        vector<long long> groupSize;
        for (auto& element : mp) {
            groupSize.push_back(element.second);
        }
        int m = groupSize.size();
        vector<long long> prefixSum(m + 1, 0);
        for (int i = 1; i <= m; ++i) {
            prefixSum[i] = prefixSum[i - 1] + groupSize[i - 1];
        }
        for (int i = 0; i < m; ++i) {
            res += groupSize[i] * (prefixSum[m] - prefixSum[i + 1]);
        }
        
        return res;
    }
};