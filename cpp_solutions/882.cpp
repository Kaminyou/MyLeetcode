typedef pair<int, int> P; // distance, node
class Solution {
public:
    int reachableNodes(vector<vector<int>>& edges, int maxMoves, int n) {
        unordered_map<int, unordered_map<int, int>> distances;
        for (auto& edge : edges) {
            distances[edge[0]][edge[1]] = edge[2];
            distances[edge[1]][edge[0]] = edge[2];
        }
        unordered_map<int, unordered_map<int, int>> node2nodeVisited;
        vector<int> visited(n, INT_MAX);
        priority_queue<P, vector<P>, greater<P>> pq;
        pq.push({0, 0});
        visited[0] = 0;
        int res = 0;
        while (!pq.empty()) {
            auto [dist, node] = pq.top();
            pq.pop();
            for (auto& [neighbor, length] : distances[node]) {
                node2nodeVisited[node][neighbor] = max(node2nodeVisited[node][neighbor], maxMoves - dist);
                if (dist + length + 1 <= maxMoves) {
                    if (dist + length + 1 < visited[neighbor]) {
                        visited[neighbor] = dist + length + 1;
                        pq.push({dist + length + 1, neighbor});
                    }
                }
            }
        }
        for (auto& node : visited) {
            if (node != INT_MAX) res++;
        }
        for (auto& edge : edges) {
            int plus = min(distances[edge[0]][edge[1]], node2nodeVisited[edge[0]][edge[1]] + node2nodeVisited[edge[1]][edge[0]]);
            res += plus;
        }
        return res;
    }
};