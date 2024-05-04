class DisjointSet {
private:
    vector<int> parent;
    vector<int> rank;
    vector<int> size;
public:
    DisjointSet(int n) {
        parent.resize(n, 0);
        rank.resize(n, 0);
        size.resize(n, 1);
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
            size[pX] += size[pY];
        }
        else if (rank[pX] < rank[pY]) {
            parent[pX] = pY;
            size[pY] += size[pX];
        }
        else {
            parent[pY] = pX;
            rank[pX]++;
            size[pX] += size[pY];
        }
    }
    int getSize(int x) {
        return size[find(x)];
    }
};
class Solution {
public:
    int minMalwareSpread(vector<vector<int>>& graph, vector<int>& initial) {
        int n = graph.size();
        unordered_set<int> initialHash(initial.begin(), initial.end());
        vector<int> naive;
        for (int i = 0; i < n; ++i) {
            if (initialHash.find(i) == initialHash.end()) naive.push_back(i);
        }
        
        DisjointSet* disjointSet = new DisjointSet(n);
        // connect all naive nodes
        for (const auto& node1 : naive) {
            for (const auto& node2 : naive) {
                if (graph[node1][node2]) disjointSet->join(node1, node2);
            }
        }
        
        unordered_map<int, unordered_set<int>> malware2groups;
        unordered_map<int, int> node2malwareCnt;
        for (auto& malware : initial) {
            for (auto& node : naive) {
                if (graph[malware][node]) malware2groups[malware].insert(disjointSet->find(node));
            }
            for (auto& infectedNode : malware2groups[malware]) {
                node2malwareCnt[infectedNode]++;
            }
        }
        
        int maxCount = 0;
        int res = initial[0];
        for (auto& malware : initial) {
            int count = 0;
            for (auto& infectedNode : malware2groups[malware]) {
                if (node2malwareCnt[infectedNode] == 1) count += disjointSet->getSize(infectedNode);
            }
            if (count > maxCount) {
                maxCount = max(maxCount, count);
                res = malware;
            }
            else if (count == maxCount) {
                res = min(res, malware);
            }
        }
        return res;
    }
};