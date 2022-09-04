class Solution {
public:
    vector<vector<int>> res;
    void backtracking(vector<vector<int>>& graph, int node, int target, vector<int>& path) {
        if (node == target) {
            res.push_back(path);
            return;
        }
        for (auto& neighbor : graph[node]) {
            path.push_back(neighbor);
            backtracking(graph, neighbor, target, path);
            path.pop_back();
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int> path = {0};
        int n = graph.size();
        backtracking(graph, 0, n - 1, path);
        return res;
    }
};