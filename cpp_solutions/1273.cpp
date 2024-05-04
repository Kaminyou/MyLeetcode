class Solution {
public:
    int res;
    vector<int> dfs(int node, vector<vector<int>>& children, vector<int>& value) {
        if (children[node].size() == 0) {
            if (value[node] == 0) {
                res -= 1;
                return {0, 0};
            }
            return {value[node], 1};
        }
        vector<int> curr = {value[node], 1};
        for (auto& child : children[node]) {
            vector<int> childInfo = dfs(child, children, value);
            curr[0] += childInfo[0];
            curr[1] += childInfo[1];
        }
        if (curr[0] == 0) {
            res -= curr[1];
            return {0, 0};
        }
        return curr;
    }
    int deleteTreeNodes(int nodes, vector<int>& parent, vector<int>& value) {
        vector<vector<int>> children(nodes);
        for (int i = 1; i < nodes; ++i) {
            children[parent[i]].push_back(i);
        }
        
        res = nodes;
        dfs(0, children, value);
        return res;
    }
};