class Solution {
public:
    int res = 0;
    void dfs(int node, int parent, vector<vector<pair<int, bool>>>& adjacency) {
        for (auto& [neighbor, status] : adjacency[node]) {
            if (neighbor == parent) continue;
            if (status) res++;
            dfs(neighbor, node, adjacency);
        }
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<pair<int, bool>>> adjacency(n);
        for (auto& connection : connections) {
            adjacency[connection[0]].push_back({connection[1], true});
            adjacency[connection[1]].push_back({connection[0], false});
        }
        dfs(0, -1, adjacency);
        return res;
    }
};