class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        vector<bool> visited(n, false);
        vector<vector<pair<int, int>>> graphs(n);
        for (auto& edge : edges) {
            graphs[edge[0]].push_back({edge[1], edge[2]});
            graphs[edge[1]].push_back({edge[0], edge[2] * 2});
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, 0});
        while (!pq.empty()) {
            auto [cost, node] = pq.top();
            pq.pop();
            if (node == n - 1) return cost;
            if (visited[node]) continue;
            visited[node] = true;
            for (auto& [next, w] : graphs[node]) {
                if (visited[next]) continue;
                pq.push({cost + w, next});
            }
        }
        return -1;
    }
};
