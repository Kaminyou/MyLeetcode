class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> revGraph(n);
        vector<int> inDegrees(n, 0);
        for (int i = 0; i < n; ++i) {
            for (auto& neighbor : graph[i]) {
                revGraph[neighbor].push_back(i);
                inDegrees[i]++;
            }
        }
        vector<int> res;
        queue<int> q;
        for (int i = 0; i < n; ++i) {
            if (inDegrees[i] == 0) q.push(i);
        }
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            res.push_back(node);
            for (auto& neighbor : revGraph[node]) {
                inDegrees[neighbor]--;
                if (inDegrees[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }
        sort(res.begin(), res.end());
        return res;
    }
};