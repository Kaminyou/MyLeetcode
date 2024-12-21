class Solution {
public:
    long long dfs(int node, vector<vector<int>>& graph, vector<bool>& visited, vector<int>& values, int& res, int k) {
        visited[node] = true;
        long long currentSum = 0;
        for (auto& neighbor : graph[node]) {
            if (visited[neighbor]) continue;
            long long sum = dfs(neighbor, graph, visited, values, res, k);
            currentSum += sum;
        }
        currentSum += values[node];
        if (currentSum % k == 0) {
            res++;
            return 0;
        }
        return currentSum;
    }
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        int res = 0;
        vector<vector<int>> graph(n);
        vector<bool> visited(n, false);
        for (auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        dfs(0, graph, visited, values, res, k);
        return res;
    }
};
