typedef pair<int, int> P;
class Solution {
public:
    vector<vector<int>> modifiedGraphEdges(int n, vector<vector<int>>& edges, int source, int destination, int target) {
        unordered_map<int, unordered_map<int, int>> mp;
        unordered_map<int, unordered_map<int, bool>> invalidEdges;

        for (auto& edge : edges) {
            int a = edge[0];
            int b = edge[1];
            int c = edge[2];
            if (c == -1) {
                invalidEdges[a][b] = true;
                invalidEdges[b][a] = true;
                c = 1;
            }
            mp[a][b] = c;
            mp[b][a] = c;
        }
        
        priority_queue<P, vector<P>, greater<P>> pq;
        vector<int> distances1(n, INT_MAX / 3);
        pq.push({0, destination});
        while (!pq.empty()) {
            auto [distance, node] = pq.top();
            pq.pop();
            if (distances1[node] != INT_MAX / 3) continue;
            distances1[node] = distance;
            for (auto& [neighbor, weight] : mp[node]) {
                if (distances1[neighbor] != INT_MAX / 3) continue;
                pq.push({distance + weight, neighbor});
            }
        }

        vector<int> distances(n, INT_MAX / 3);
        pq.push({0, source});
        while (!pq.empty()) {
            auto [distance, node] = pq.top();
            pq.pop();
            if (distances[node] != INT_MAX / 3) continue;
            distances[node] = distance;
            if (node == destination && distance != target) return {};
            for (auto& [neighbor, weight] : mp[node]) {
                if (distances[neighbor] != INT_MAX / 3) continue;
                if (invalidEdges[node][neighbor] && distances[node] + weight + distances1[neighbor] < target) {
                    weight = target - distances[node] - distances1[neighbor];
                    mp[node][neighbor] = weight;
                    mp[neighbor][node] = weight;
                }
                pq.push({distance + weight, neighbor});
            }
        }

        for (auto& edge : edges) {
            int a = edge[0];
            int b = edge[1];
            edge[2] = mp[a][b];
        }
        return edges;
    }
};
