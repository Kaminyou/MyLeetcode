class Solution {
public:
    bool dfs(vector<bool>& visited, vector<vector<int>>& adjacency, int current, int destination) {
        visited[current] = true;
        if (current == destination) return true;
        for (auto& neighbor : adjacency[current]) {
            if (visited[neighbor]) continue;
            if (dfs(visited, adjacency, neighbor, destination)) return true;
        }
        return false;
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<bool> visited(n, false);
        vector<vector<int>> adjacency(n);
        for (auto& edge : edges) {
            adjacency[edge[0]].push_back(edge[1]);
            adjacency[edge[1]].push_back(edge[0]);
        }
        return dfs(visited, adjacency, source, destination);
    }
};