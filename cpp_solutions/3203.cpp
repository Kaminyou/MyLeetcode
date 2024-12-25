class Solution {
public:
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int d1 = maxDistance(edges1);
        int d2 = maxDistance(edges2);
        return max({d1, d2, (d1 + 1) / 2 + (d2 + 1) / 2 + 1});
    }
    int maxDistance(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<vector<int>> graph(n + 1);
        for (auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        pair<int, int> p1 = _maxDistance(graph, 0);
        pair<int, int> p2 = _maxDistance(graph, p1.first);
        return p2.second;
    }
    pair<int, int> _maxDistance(vector<vector<int>>& graph, int start) {
        queue<int> q;
        int n = graph.size();
        vector<bool> visited(n, false);
        q.push(start);
        visited[start] = true;
        int lastNode = -1;
        int distance = -1;
        while (!q.empty()) {
            int m = q.size();
            distance++;
            for (int i = 0; i < m; ++i) {
                int node = q.front();
                lastNode = node;
                q.pop();
                for (auto& neighbor : graph[node]) {
                    if (visited[neighbor]) continue;
                    q.push(neighbor);
                    visited[neighbor] = true;
                }
            }
        }
        return {lastNode, distance};
    }
};
