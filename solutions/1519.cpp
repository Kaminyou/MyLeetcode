class Solution {
public:
    vector<int> dfs(int node, int parent, vector<vector<int>>& adjacency, string& labels, vector<int>& res) {
        vector<int> counts(26, 0);
        for (auto& neighbor : adjacency[node]) {
            if (neighbor == parent) continue;
            vector<int> childCnt = dfs(neighbor, node, adjacency, labels, res);
            for (int i = 0; i < 26; ++i) {
                counts[i] += childCnt[i];
            }
        }
        res[node] = ++counts[labels[node] - 'a'];
        return counts;
    }
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        vector<vector<int>> adjacency(n);
        for (auto& edge : edges) {
            adjacency[edge[0]].push_back(edge[1]);
            adjacency[edge[1]].push_back(edge[0]);
        }
        vector<int> res(n, 0);
        dfs(0, -1, adjacency, labels, res);
        return res;
    }
};