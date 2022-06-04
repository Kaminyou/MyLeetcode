class Solution {
public:
    void dfs(unordered_map<int, stack<int>>& graph, vector<vector<int>>& res, int curr) {
        auto& neighbors = graph[curr];
        while (!neighbors.empty()) {
            int neighbor = neighbors.top();
            neighbors.pop();
            dfs(graph, res, neighbor);
            res.push_back({curr, neighbor});
        }
    }
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        unordered_map<int, stack<int>> graph;
        unordered_map<int, int> in;
        unordered_map<int, int> out;
        for (const auto& pair : pairs) {
            int u = pair[0];
            int v = pair[1];
            graph[u].push(v);
            in[v]++;
            out[u]++;
        }
        
        int start = -1;
        for (auto& element : graph) {
            int node = element.first;
            if (out[node] - in[node] == 1) {
                start = node;
                break;
            }
        }
        
        if (start == -1) start = graph.begin()->first;
        
        vector<vector<int>> res;
        dfs(graph, res, start);
        reverse(res.begin(), res.end());
        return res;
    }
};