class Solution {
public:
    void dfs(int node, int depth, int& maxDepth, vector<bool>& visited, vector<vector<int>>& graph) {
        visited[node] = true;
        maxDepth = max(maxDepth, depth);
        for (auto& neighbor : graph[node]) {
            if (!visited[neighbor]) {
                dfs(neighbor, depth + 1, maxDepth, visited, graph);
            }
        }
    }
    int assignEdgeWeights(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<vector<int>> graph(n + 2);
        for (auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        int maxDepth = 0;
        vector<bool> visited(n + 2, false);
        dfs(1, 0, maxDepth, visited, graph);
        vector<int> even(maxDepth, 0);
        vector<int> odd(maxDepth, 0);
        even[0] = 1;
        odd[0] = 1;
        int mod = 1e9 + 7;
        for (int i = 1; i < maxDepth; ++i) {
            even[i] = odd[i - 1] + even[i - 1];
            odd[i] = odd[i - 1] + even[i - 1];
            even[i] %= mod;
            odd[i] %= mod;
        }
        return odd[maxDepth - 1];
    }
};
