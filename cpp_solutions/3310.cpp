class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>> graph(n);
        vector<vector<int>> revGraph(n);
        for (auto& invocation : invocations) {
            graph[invocation[0]].push_back(invocation[1]);
            revGraph[invocation[1]].push_back(invocation[0]);
        }
        vector<bool> visited(n, false);
        queue<int> q;
        q.push(k);
        visited[k] = true;
        while (!q.empty()) {
            int m = q.size();
            while (m--) {
                int node = q.front();
                q.pop();
                for (auto& neighbor : graph[node]) {
                    if (visited[neighbor]) continue;
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
        bool flag = true;
        for (int i = 0; i < n; ++i) {
            if (visited[i]) {
                for (auto& neighbor : revGraph[i]) {
                    if (!visited[neighbor]) {
                        flag = false;
                        break;
                    }
                }
                if (!flag) break;
            }
        }
        vector<int> res;
        if (flag) {
            for (int i = 0; i < n; ++i) {
                if (!visited[i]) res.push_back(i);
            }
        }
        else {
            for (int i = 0; i < n; ++i) {
                res.push_back(i);
            }
        }
        return res;
    }
};
