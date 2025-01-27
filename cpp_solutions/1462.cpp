class Solution {
public:
    void dfs(int start, int node, vector<vector<int>>& graph, vector<vector<bool>>& reachable, vector<bool>& visited) {
        visited[node] = true;
        reachable[start][node] = true;
        for (auto& neighbor : graph[node]) {
            if (!visited[neighbor]) dfs(start, neighbor, graph, reachable, visited);
        }
    }
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<bool>> reachable(numCourses, vector<bool>(numCourses, false));
        vector<vector<int>> graph(numCourses);
        for (auto& prerequisity : prerequisites) {
            graph[prerequisity[0]].push_back(prerequisity[1]);
        }
        vector<bool> visited(numCourses, false);
        for (int i = 0; i < numCourses; ++i) {
            dfs(i, i, graph, reachable, visited);
            for (int i = 0; i < numCourses; ++i) visited[i] = false;
        }
        int n = queries.size();
        vector<bool> res(n, false);
        for (int i = 0; i < n; ++i) {
            res[i] = reachable[queries[i][0]][queries[i][1]];
        }
        return res;
    }
};
