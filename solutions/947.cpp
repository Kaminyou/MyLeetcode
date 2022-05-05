class Solution {
public:
    void dfs(int node, vector<vector<int>>& graph, vector<bool>& visited) {
        if (visited[node]) return;
        visited[node] = true;
        for (auto neighbor : graph[node]) {
            dfs(neighbor, graph, visited);
        }
    }
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        vector<vector<int>> graph(n, vector<int>());
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]) {
                    graph[i].push_back(j);
                    graph[j].push_back(i);
                }
            }
        }
        
        vector<bool> visited(n, false);
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (visited[i] == false) {
                count++;
                dfs(i, graph, visited);
            }
        }
        return n - count;
    }
};