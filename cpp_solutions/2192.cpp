class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<set<int>> res(n, set<int>());
        vector<vector<int>> resFinal(n, vector<int>());
        vector<vector<int>> graph(n, vector<int>());

        vector<int> indegrees(n, 0);
        for (auto& edge : edges) {
            indegrees[edge[1]] += 1;
            graph[edge[0]].push_back(edge[1]);
        }

        queue<int> q;
        for (int i = 0; i < n; ++i) {
            if (indegrees[i] == 0) q.push(i);
        }

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            for (auto& neighbor : graph[node]) {
                indegrees[neighbor] -= 1;
                res[neighbor].insert(node);
                for (auto& pre : res[node]) {
                    res[neighbor].insert(pre);
                }
                if (indegrees[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }
        for (int i = 0; i < n; ++i) {
            for (auto& element : res[i]) {
                resFinal[i].push_back(element);
            }
            sort(resFinal[i].begin(), resFinal[i].end());
        }
        return resFinal;
    }
};
