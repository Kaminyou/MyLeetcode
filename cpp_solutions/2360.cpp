class Solution {
public:
    // {node, length}: 
    // node = -1: not detected
    // node = -2: detected
    pair<int, int> dfs(vector<int>& edges, vector<int>& visited, int node) {
        if (visited[node] != -1) return {-1, -1};
        visited[node] = 0;
        int neighbor = edges[node];
        if (neighbor == -1) {
            visited[node] = 1;
            return {-1, -1};
        }
        if (visited[neighbor] == 0) {
            visited[node] = 1;
            return {neighbor, 1};
        }
        auto [cycle, length] = dfs(edges, visited, neighbor);
        visited[node] = 1;
        if (cycle == -1) return {-1, -1};
        if (cycle == node) return {-2, length + 1};
        else {
            if (cycle == -2) return {-2, length};
            else return {cycle, length + 1};
        }
    }
    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        vector<int> visited(n, -1);
        
        int maxLength = -1;
        for (int i = 0; i < n; ++i) {
            if (visited[i] == -1) {
                auto [node, length] = dfs(edges, visited, i);
                if (node != -1 && length > maxLength) {
                    maxLength = length;
                }
            }
        }
        return maxLength;
    }
};