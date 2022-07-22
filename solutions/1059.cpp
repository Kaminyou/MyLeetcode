class Solution {
public:
    bool dfs(vector<vector<int>>& adjacency, vector<int>& visited, int current, int destination) {
        if (adjacency[current].size() == 0) return current == destination;
        if (visited[current] != -1) return visited[current];
        visited[current] = 0;
        for (auto& neighbor : adjacency[current]) {
            if (!dfs(adjacency, visited, neighbor, destination)) return false;
        }
        
        return visited[current] = true;
    }
    bool leadsToDestination(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> adjacency(n);
        vector<int> visited(n, -1);
        for (auto& edge : edges) {
            adjacency[edge[0]].push_back(edge[1]);
        }
        
        return dfs(adjacency, visited, source, destination);
    }
};