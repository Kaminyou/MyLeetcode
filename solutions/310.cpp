class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n == 1) return {0};
        vector<vector<int>> graph(n);
        vector<int> inDegrees(n, 0);
        for (auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
            inDegrees[edge[0]]++;
            inDegrees[edge[1]]++;
        }
        
        queue<int> q;
        for (int i = 0; i < n; ++i) {
            if (inDegrees[i] == 1) q.push(i);
        }
        
        while (n > 2) {
            int size = q.size();
            n -= size;
            for (int i = 0; i < size; ++i) {
                int node = q.front();
                q.pop();
                for (auto neighbor : graph[node]) {
                    inDegrees[neighbor]--;
                    if (inDegrees[neighbor] == 1) q.push(neighbor);
                }
            }
        }
        vector<int> res;
        while (!q.empty()) {
            res.push_back(q.front());
            q.pop();
        }
        return res;
    }
};