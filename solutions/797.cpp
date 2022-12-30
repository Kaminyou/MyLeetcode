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

class Solution {
public:
    vector<vector<int>> paths;
    void backtracking(int parent, int node, int target, vector<int>& path, vector<vector<int>>& graph) {
        if (node == target) {
            paths.push_back(path);
            return;
        }
        for (auto& neighbor : graph[node]) {
            if (neighbor == parent) continue;
            path.push_back(neighbor);
            backtracking(node, neighbor, target, path, graph);
            path.pop_back();
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> path;
        path.push_back(0);
        backtracking(-1, 0, n - 1, path, graph);
        return paths;
    }
};