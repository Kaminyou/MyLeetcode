class DisjointSet {
private:
    vector<int> parents;
    vector<int> ranks;
    int sets;
public:
    DisjointSet(int n) {
        parents.resize(n, 0);
        ranks.resize(n, 1);
        for (int i = 0; i < n; ++i) {
            parents[i] = i;
        }
        sets = n;
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
        sets--;
        if (ranks[pX] > ranks[pY]) {
            parents[pY] = pX;
        }
        else if (ranks[pX] < ranks[pY]) {
            parents[pX] = pY;
        }
        else {
            parents[pY] = pX;
            ranks[pX]++;
        }
    }
    bool isAllJoin() {
        return sets == 1;
    }
};
class Solution {
public:
    bool isValid(int minVal, int n, vector<vector<int>>& edges, int k) {
        DisjointSet* disjointSet = new DisjointSet(n);
        vector<vector<int>> candidates;
        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int s = edge[2];
            int must = edge[3];
            if (must) {
                if (s < minVal) return false;
                if (disjointSet->find(u) == disjointSet->find(v)) return false;
                disjointSet->join(u, v);
            }
            else {
                if (s >= minVal) {
                    candidates.push_back({0, u, v});
                }
                else if (s * 2 >= minVal) {
                    candidates.push_back({1, u, v});
                }
            }
        }
        if (disjointSet->isAllJoin()) return true;
        int ungradeNum = 0;
        sort(candidates.begin(), candidates.end());
        for (auto& candidate : candidates) {
            int isUpgrade = candidate[0];
            int u = candidate[1];
            int v = candidate[2];
            if (disjointSet->find(u) != disjointSet->find(v)) {
                disjointSet->join(u, v);
                ungradeNum += isUpgrade;
            }
            if (ungradeNum > k) return false;
            if (disjointSet->isAllJoin()) return true;
        }
        return false;
    }
    int maxStability(int n, vector<vector<int>>& edges, int k) {
        int left = 1;
        int right = 1e5 * 2 + 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (!isValid(mid, n, edges, k)) right = mid;
            else left = mid + 1;
        }
        left--;
        if (isValid(left, n, edges, k)) return left;
        return -1;
    }
};
