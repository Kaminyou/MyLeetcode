class Solution {
public:
    bool dfs(int parent, int curr, int target, vector<vector<int>>& graph, unordered_set<int>& st) {
        if (curr == target) {
            st.insert(curr);
            return true;
        }
        for (auto& neighbor : graph[curr]) {
            if (neighbor != parent && dfs(curr, neighbor, target, graph, st)) {
                st.insert(curr);
                return true;
            }
        }
        return false;
    }
    bool findPath(int parent, int curr, int target, vector<vector<int>>& graph, unordered_set<int>& st) {
        if (curr == target) return true;
        for (auto& neighbor : graph[curr]) {
            if (neighbor != parent && st.find(neighbor) == st.end() && findPath(curr, neighbor, target, graph, st)) return true;
        }
        return false;
    }
    vector<int> closestNode(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        vector<vector<int>> graph(n);
        vector<int> res(query.size(), 0);
        for (auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        for (int i = 0; i < query.size(); ++i) {
            vector<int>& q = query[i];
            unordered_set<int> path;
            dfs(-1, q[0], q[1], graph, path);
            for (auto& node : path) {
                if (findPath(-1, node, q[2], graph, path)) {
                    res[i] = node;
                }
            }
        }
        return res;
    }
};