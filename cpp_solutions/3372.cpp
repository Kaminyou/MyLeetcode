class Solution {
public:
    int numOfNodes(vector<vector<int>>& graph, vector<bool>& visited, int start, int k) {
        int res = 0;
        queue<int> q;
        q.push(start);
        int level = 0;
        int n = visited.size();
        for (int i = 0; i < n; ++i) visited[i] = false;
        visited[start] = true;
        while (!q.empty()) {
            if (level > k) break;
            int m = q.size();
            while (m--) {
                int node = q.front();
                q.pop();
                res++;
                for (auto& neighbor : graph[node]) {
                    if (visited[neighbor]) continue;
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
            level++;
        }
        return res;
    }
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        int n = edges1.size() + 1;
        int m = edges2.size() + 1;
        vector<vector<int>> graph1(n);
        vector<vector<int>> graph2(m);
        for (auto& edge : edges1) {
            graph1[edge[0]].push_back(edge[1]);
            graph1[edge[1]].push_back(edge[0]);
        }
        for (auto& edge : edges2) {
            graph2[edge[0]].push_back(edge[1]);
            graph2[edge[1]].push_back(edge[0]);
        }
        int maxNodes2 = 0;
        vector<bool> visited2(m, false);
        for (int i = 0; i < m; ++i) {
            maxNodes2 = max(maxNodes2, numOfNodes(graph2, visited2, i, k - 1));
        }
        
        vector<int> res(n, 0);
        vector<bool> visited1(n, false);
        for (int i = 0; i < n; ++i) {
            int nodes = numOfNodes(graph1, visited1, i, k);
            res[i] = nodes + maxNodes2;
        }
        return res;
    }
};
