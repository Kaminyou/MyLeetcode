class Solution {
public:
    void dfs(int node, vector<vector<int>>& graph, vector<bool>& visited) {
        visited[node] = true;
        for (auto neighbor : graph[node]) {
            if (visited[neighbor]) continue;
            dfs(neighbor, graph, visited);
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);
        for (auto edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        
        vector<bool> visited(n, false);
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                dfs(i, graph, visited);
                count++;
            }
        }
        return count;
    }
};

class DisjointSet {
private:
    vector<int> parent;
    vector<int> rank;
public:
    int comonents = 0;
    DisjointSet(int size) {
        parent.resize(size, 0);
        for (int i = 0; i < size; ++i) parent[i] = i;
        rank.resize(size, 0);
        comonents = size;
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
        comonents--;
        if (rank[pX] > rank[pY]) parent[pY] = pX;
        else if (rank[pY] > rank[pX]) parent[pX] = pY;
        else {
            parent[pY] = pX;
            rank[pX]++;
        }
    }
};
class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        DisjointSet* disjointSet = new DisjointSet(n);
        for (auto& edge : edges) {
            disjointSet->join(edge[0], edge[1]);
        }
        return disjointSet->comonents;
    }
};