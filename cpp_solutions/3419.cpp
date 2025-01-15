class Solution {
public:
    bool criteria(int mid, int n, vector<vector<pair<int, int>>>& graph) {
        // if the graph can be constructed with edges of weight <= mid
        int reach = 1;
        vector<bool> visited(n, false);
        visited[0] = 1;
        queue<int> q;
        q.push(0);
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            for (auto& neighborInfo : graph[node]) {
                auto [neighbor, weight] = neighborInfo;
                if (weight > mid) continue;
                if (visited[neighbor]) continue;
                q.push(neighbor);
                visited[neighbor] = true;
                reach++;
            }
        }
        return reach == n;
    }
    int minMaxWeight(int n, vector<vector<int>>& edges, int threshold) {
        int left = 0;
        int right = 1e6 + 1;
        vector<vector<pair<int, int>>> graph(n);
        for (auto& edge : edges) {
            graph[edge[1]].push_back({edge[0], edge[2]});
        }
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (criteria(mid, n, graph)) right = mid;
            else left = mid + 1;
        }
        return (left == 1e6 + 1) ? -1 : left;
    }
};
