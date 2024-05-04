class Solution {
public:
    typedef pair<int, int> Node; // distance, id
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> graph(n + 1); // node-> nodes (id, distance)
        vector<int> distances(n + 1, INT_MAX);
        vector<bool> visited(n + 1, false);
        
        for (auto time : times) {
            graph[time[0]].push_back(make_pair(time[1], time[2]));
        }
        
        priority_queue<Node, vector<Node>, greater<Node>> pq;
        pq.push(make_pair(0, k));
        distances[k] = 0;
        
        while (!pq.empty()) {
            auto [dist, node] = pq.top();
            pq.pop();
            visited[node] = true;
            
            for (auto [neighbor, w] : graph[node]) {
                int _w = w + dist;
                if (_w < distances[neighbor]) {
                    distances[neighbor] = _w;
                    if (!visited[neighbor]) pq.push(make_pair(_w, neighbor));
                }
            }
        }
        
        int res = -1;
        for (int i = 1; i <= n; i++) {
            if (distances[i] == INT_MAX) return -1;
            else res = max(res, distances[i]);
        }
        return res;
    }
};