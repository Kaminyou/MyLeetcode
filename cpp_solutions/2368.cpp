class Solution {
public:
    int res = 0;
    void dfs(int currNode, vector<vector<int>>& adjacency, vector<bool>& visited) {
        visited[currNode] = true;
        res++;
        for (auto& neighbor : adjacency[currNode]) {
            if (visited[neighbor]) continue;
            dfs(neighbor, adjacency, visited);
        }
    }
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        vector<vector<int>> adjacency(n);
        for (auto& edge : edges) {
            adjacency[edge[0]].push_back(edge[1]);
            adjacency[edge[1]].push_back(edge[0]);
        }
        
        vector<bool> visited(n, false);
        for (auto& num : restricted) visited[num] = true;
        dfs(0, adjacency, visited);
        return res;
    }
};