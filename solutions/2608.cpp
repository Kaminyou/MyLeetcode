class Solution {
public:
    int findShortestCycle(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adjacency(n);
        for (auto& edge : edges) {
            adjacency[edge[0]].push_back(edge[1]);
            adjacency[edge[1]].push_back(edge[0]);
        }
        
        int res = INT_MAX;
        for (int root = 0; root < n; ++root) {
            vector<int> parents(n, -1);
            vector<int> dist(n, -1);
            queue<int> q;
            q.push(root);
            dist[root] = 0;
            while (!q.empty()) {
                int node = q.front();
                q.pop();
                for (auto& neighbor : adjacency[node]) {
                    if (dist[neighbor] == -1) {
                        dist[neighbor] = dist[node] + 1;
                        parents[neighbor] = node;
                        q.push(neighbor);
                    }
                    else if (parents[node] != neighbor) {
                        res = min(res, dist[node] + dist[neighbor] + 1);
                    }
                }
            }
        }
        if (res == INT_MAX) return -1;
        return res;
    }
};