class Solution {
public:
    long long dfs(int node, vector<vector<int>>& graph, vector<int>& baseTime) {
        if (graph[node].size() == 0) return baseTime[node];
        long long minV = LLONG_MAX;
        long long maxV = LLONG_MIN;
        for (auto& neighbor : graph[node]) {
            long long v = dfs(neighbor, graph, baseTime);
            minV = min(minV, v);
            maxV = max(maxV, v);
        }
        long long ownDuration = maxV - minV + baseTime[node];
        return maxV + ownDuration;
    }
    long long finishTime(int n, vector<vector<int>>& edges, vector<int>& baseTime) {
        vector<vector<int>> graph(n);
        for (auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
        }
        return dfs(0, graph, baseTime);
    }
};
