class DisjointSet {
private:
    vector<int> parent;
    vector<int> rank;
public:
    DisjointSet(int n) {
        parent.resize(n, 0);
        rank.resize(n, 0);
        for (int i = 0; i < n; ++i) parent[i] = i;
    }
    int find(int x) {
        if (x != parent[x]) {
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
    int largestComponentSize(vector<int>& nums) {
        int maxVal = *max_element(nums.begin(), nums.end());
        DisjointSet* disjointSet = new DisjointSet(maxVal + 1);
        
        for (const auto& num : nums) {
            for (int i = 2; i <= sqrt(num); ++i) {
                if (num % i == 0) {
                    disjointSet->join(i, num);
                    disjointSet->join(i, num / i);
                }
            }
        }
        unordered_map<int, int> group2cnt;
        int maxCnt = 0;
        for (auto& num : nums) {
            int group = disjointSet->find(num);
            group2cnt[group]++;
            maxCnt = max(maxCnt, group2cnt[group]);
        }
        return maxCnt;
    }
};