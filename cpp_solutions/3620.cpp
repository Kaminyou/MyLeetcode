class Solution {
public:
    bool valid(int minCost, vector<vector<pair<int, int>>>& graph, int n, long long k) {
        // can walk if cost >= minCost
        vector<bool> visited(n, false);
        priority_queue<pair<long long, int>> q;
        q.push({0, 0});
        while (!q.empty()) {
            auto [negTotal, node] = q.top();
            q.pop();
            if (visited[node]) continue;
            long long posTotal = -negTotal;
            visited[node] = true;
            if (node == n - 1) return true;
            for (auto& [neighbor, cost] : graph[node]) {
                if (visited[neighbor]) continue;
                if (posTotal + cost > k) continue;
                if (cost < minCost) continue;
                q.push({-(posTotal + cost), neighbor});
            }
        }
        return false;
    }
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        int n = online.size();
        vector<vector<pair<int, int>>> graph(n);
        for (auto& edge : edges) {
            if (online[edge[0]] && online[edge[1]]) {
                graph[edge[0]].push_back({edge[1], edge[2]});
            }
        }
        int left = 0;
        int right = INT_MAX;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (!valid(mid, graph, n, k)) right = mid;
            else left = mid + 1;
        }
        return left - 1;
    }
};

