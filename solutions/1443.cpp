class Solution {
public:
    bool dfs(int node, int parent, vector<vector<int>>& adjacency, vector<bool>& hasApple, int& res) {
        bool subTreeHasApple = false;
        if (hasApple[node]) subTreeHasApple = true;
        
        for (auto& neighbor : adjacency[node]) {
            if (neighbor == parent) continue;
            if (dfs(neighbor, node, adjacency, hasApple, res)) {
                subTreeHasApple = true;
                res += 2;
            }
        }
        return subTreeHasApple;
    }
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        int res = 0;
        vector<vector<int>> adjacency(n);
        for (auto& edge : edges) {
            adjacency[edge[0]].push_back(edge[1]);
            adjacency[edge[1]].push_back(edge[0]);
        }
        dfs(0, -1, adjacency, hasApple, res);
        return res;
    }
};