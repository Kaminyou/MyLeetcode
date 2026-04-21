class DisjointSet {
private:
    vector<int> parents;
    vector<int> ranks;
public:
    DisjointSet(int n) {
        parents.resize(n, 0);
        for (int i = 0; i < n; ++i) parents[i] = i;
        ranks.resize(n, 1);
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
};
class Solution {
public:
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        int n = source.size();
        DisjointSet* disjointSet = new DisjointSet(n);
        for (auto& allowedSwap : allowedSwaps) {
            disjointSet->join(allowedSwap[0], allowedSwap[1]);
        }
        unordered_map<int, vector<int>> idx2group;
        for (int i = 0; i < n; ++i) {
            int idx = disjointSet->find(i);
            idx2group[idx].push_back(i);
        }
        int res = 0;
        unordered_map<int, int> num2cnt;
        for (auto& [idx, group] : idx2group) {
            num2cnt.clear();
            for (auto& ind : group) {
                num2cnt[source[ind]]++;
                num2cnt[target[ind]]--;
            }
            for (auto& [num, cnt] : num2cnt) {
                if (cnt > 0) res += cnt;
            }
        }
        return res;
    }
};
