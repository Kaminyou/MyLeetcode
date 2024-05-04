class DisjointSet {
private:
    vector<int> parent;
public:
    DisjointSet(int n) {
        parent.resize(n);
        for (int i = 0; i < n; ++i) parent[i] = i;
    }
    int find(int x) {
        if (parent[x] != x) parent[x] = find(parent[x]);
        return parent[x];
    }
    void join(int x, int y) {
        int pX = find(x);
        int pY = find(y);
        if (pX == pY) return;
        if (pX > pY) parent[pY] = pX;
        else parent[pX] = pY;
    }
};
class Solution {
public:
    vector<int> minReverseOperations(int n, int p, vector<int>& banned, int k) {
        vector<int> res(n, -1);
        res[p] = 0;
        DisjointSet* disjointSet = new DisjointSet(n + 2);
        disjointSet->join(p, p + 2);
        for (auto& ban : banned) disjointSet->join(ban, ban + 2);
        queue<int> q;
        q.push(p);
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            int left = max(k - 1 - node, node - k + 1);
            int right = min(k - 1 + node, 2 * n - k - 1 - node);
            int i = disjointSet->find(left);
            for (int i = disjointSet->find(left); i <= right; i = disjointSet->find(i)) {
                res[i] = res[node] + 1;
                disjointSet->join(i, i + 2);
                q.push(i);
            }
        }
        return res;
    }
};