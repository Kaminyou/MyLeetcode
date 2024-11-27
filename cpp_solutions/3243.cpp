class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& graph) {
        queue<int> q;
        q.push(0);
        int res = 0;
        vector<bool> visited(n, false);
        visited[0] = true;
        while (!q.empty()) {
            int m = q.size();
            while (m--){
                int node = q.front();
                q.pop();
                if (node == n - 1) return res;
                for (auto& neighbor : graph[node]) {
                    if (visited[neighbor]) continue;
                    q.push(neighbor);
                    visited[neighbor] = true;
                }
            }
            res++;
        }
        return n - 1;
    }
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> graph(n);
        for (int i = 0; i < n - 1; ++i) {
            graph[i].push_back(i + 1);
        }
        int m = queries.size();
        vector<int> res(m, 0);
        for (int i = 0; i < m; ++i) {
            graph[queries[i][0]].push_back(queries[i][1]);
            res[i] = shortestPath(n, graph);
        }
        return res;
    }
};
