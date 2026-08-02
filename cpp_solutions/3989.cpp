class Solution {
public:
    int findMaxPath(int node, vector<vector<int>>& graph, vector<int>& memo) {
        if (memo[node] != -1) return memo[node];
        int val = 1;
        for (auto& neighbor : graph[node]) {
            val = max(val, findMaxPath(neighbor, graph, memo) + 1);
        }
        return memo[node] = val;
    }
    int maxConsistentColumns(vector<vector<int>>& grid, int limit) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> graph(n);
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                bool flag = true;
                for (int k = 0; k < m; ++k) {
                    if (abs(grid[k][j] - grid[k][i]) > limit) {
                        flag = false;
                        break;
                    }
                }
                if (flag) {
                    graph[i].push_back(j);
                }
            }
        }
        int res = 1;
        vector<int> memo(n, -1);
        for (int i = 0; i < n; ++i) {
            res = max(res, findMaxPath(i, graph, memo));
        }
        return res;
    }
};

