class DisjointSet {
private:
    vector<int> parent;
    vector<int> rank;
public:
    DisjointSet(int size) {
        parent.resize(size, 0);
        rank.resize(size, 0);
        for (int i = 0; i < size; ++i) {
            parent[i] = i;
        }
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
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        DisjointSet* disjointSet = new DisjointSet(26);
        int n = s1.size();
        for (int i = 0; i < n; ++i) {
            disjointSet->join(s1[i] - 'a', s2[i] - 'a');
        }
        vector<int> groupMin(26, 26);
        for (int i = 0; i < 26; ++i) {
            int group = disjointSet->find(i);
            groupMin[group] = min(groupMin[group], i);
        }
        string res;
        for (auto& c : baseStr) {
            int group = disjointSet->find(c - 'a');
            res.push_back(groupMin[group] + 'a');
        }
        return res;
    }
};