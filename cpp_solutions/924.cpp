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
            size[pX] += size[pY];
        }
        else if (rank[pX] < rank[pY]) {
            parent[pX] = pY;
            size[pY] += size[pX];
        }
        else {
            rank[pX]++;
            parent[pY] = pX;
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
        DisjointSet* disjointSet = new DisjointSet(n);
        
        vector<vector<int>> adjacency(n);
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (graph[i][j]) {
                    adjacency[i].push_back(j);
                    adjacency[j].push_back(i);
                }
            }
        }
        
        vector<bool> visited(n, false);
        for (auto& initNode : initial) {
            if (visited[initNode]) continue;
            queue<int> q;
            q.push(initNode);
            visited[initNode] = true;
            while (!q.empty()) {
                int node = q.front();
                q.pop();
                for (auto& neighbor : adjacency[node]) {
                    if (visited[neighbor]) continue;
                    q.push(neighbor);
                    visited[neighbor] = true;
                    disjointSet->join(node, neighbor);
                }
            }
        }
        
        unordered_map<int, vector<int>> parent2nodes;
        for (auto& initNode : initial) {
            int parent = disjointSet->find(initNode);
            parent2nodes[parent].push_back(parent);
        }
        // find # of node = 1 with max size
        int res = INT_MAX;
        int maxSize = -1;
        for (auto& element : parent2nodes) {
            if (element.second.size() == 1) {
                int size = disjointSet->getSize(element.first);
                if (size > maxSize) {
                    maxSize = size;
                    res = element.second[0];
                }
                else if (size == maxSize) {
                    res = min(res, element.second[0]);
                }
            }
        }
        if (res != INT_MAX) return res;
        return *min_element(initial.begin(), initial.end());
    }
};