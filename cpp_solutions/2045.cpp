class Solution {
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        vector<vector<int>> graph(n + 1);
        for (auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        vector<int> visited(n + 1, 0);
        vector<int> dist(n + 1, -1);
        queue<pair<int, int>> q;
        q.push({1, 0});

        while (!q.empty()) {
            auto [node, t] = q.front();
            q.pop();
            int round = t / change;
            int tt = t + time;
            if (round & 1) {
                tt = (round + 1) * change + time;
            }
            for (auto& neighbor : graph[node]) {
                if (visited[neighbor] < 2 && dist[neighbor] < tt) {
                    visited[neighbor]++;
                    dist[neighbor] = tt;
                    q.push({neighbor, tt});
                    if (visited[neighbor] == 2 && neighbor == n) return tt;
                }
            }
        }
        return -1;
    }
};
