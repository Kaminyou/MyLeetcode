class Solution {
public:
    int res = 0;
    void dfs(int node, vector<vector<int>>& children, vector<int>& informTime, int currentTime) {
        if (children[node].size() == 0) {
            res = max(res, currentTime);
            return;
        }
        
        for (auto child : children[node]) {
            dfs(child, children, informTime, currentTime + informTime[node]);
        }
        
    }
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<vector<int>> children(n);
        for (int i = 0; i < n; ++i) {
            if (i == headID) continue;
            children[manager[i]].push_back(i);
        }
        dfs(headID, children, informTime, 0);
        return res;
    }
};