class Solution {
public:
    vector<int> bfs(vector<vector<int>>& adjacency, int node) {
        int n = adjacency.size();
        int level = 0;
        vector<int> res(n, INT_MAX);
        vector<bool> visited(n, false);
        queue<int> q;
        q.push(node);
        visited[node] = true;
        
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                int curr = q.front();
                q.pop();
                res[curr] = level;
                for (auto& neighbor : adjacency[curr]) {
                    if (visited[neighbor] == false) {
                        q.push(neighbor);
                        visited[neighbor] = true;
                    }
                }
            }
            level++;
        }
        return res;
    }
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        vector<vector<int>> adjacency(n);
        for (int i = 0; i < n; ++i) {
            if (edges[i] != -1) adjacency[i].push_back(edges[i]);
        }
        
        vector<int> node1Reach = bfs(adjacency, node1);
        vector<int> node2Reach = bfs(adjacency, node2);
        
        int ans = -1;
        int max_path = INT_MAX;
        for (int i = 0; i < n; ++i) {
            if (max(node1Reach[i], node2Reach[i]) < max_path) {
                max_path = max(node1Reach[i], node2Reach[i]);
                ans = i;
            }
        }
        return ans;
    }
};