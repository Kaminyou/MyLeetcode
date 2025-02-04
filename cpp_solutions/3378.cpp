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
    int countComponents(vector<int>& nums, int threshold) {
        unordered_set<int> visited;
        DisjointSet* disjointSet = new DisjointSet(threshold + 1);
        for (auto& num : nums) {
            if (visited.count(num)) continue;
            visited.insert(num);
            for (int factor = 2; factor * num <= threshold; factor++) {
                disjointSet->join(num, num * factor);
                visited.insert(num * factor);
            }
        }
        unordered_set<int> cnts;
        for (auto& num : nums) {
            if (num > threshold) {
                cnts.insert(num);
            }
            else {
                int group = disjointSet->find(num);
                cnts.insert(group);
            }
        }
        int res = cnts.size();
        return res;
    }
};
