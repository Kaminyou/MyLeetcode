class Solution {
public:
    int dfs(int curr, vector<bool>& visited, vector<int>& nums,  vector<vector<int>>& adj, vector<int>& nodeXor, vector<int>& parents, vector<vector<bool>>& isChild, vector<vector<int>>& pcEdges) {
        visited[curr] = true;
        int res = 0;
        res ^= nums[curr];
        
        for (auto& p : parents) isChild[p][curr] = true;
        
        parents.push_back(curr);
        for (auto& neighbor : adj[curr]) {
            if (!visited[neighbor]) {
                pcEdges.push_back({curr, neighbor});
                res ^= dfs(neighbor, visited, nums, adj, nodeXor, parents, isChild, pcEdges);
            }
        }
        parents.pop_back();
        nodeXor[curr] = res;
        return res;
    }
    int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
        int n = nums.size();
        vector<vector<int>> adj(n);
        vector<int> nodeXor(n, 0);
        vector<bool> visited(n, false);
        vector<int> parents;
        vector<vector<bool>> isChild(n, vector<bool>(n, false));
        vector<vector<int>> pcEdges;
        
        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        dfs(0, visited, nums, adj, nodeXor, parents, isChild, pcEdges);
        
        int res = INT_MAX;
        int m = pcEdges.size();
        for (int i = 0; i < m; ++i) {
            for (int j = i + 1; j < m; ++j) {
                int a = pcEdges[i][1];
                int b = pcEdges[j][1];
                int xa, xb;
                int xc = nodeXor[0];
                
                // b is a's child
                if (isChild[a][b]) {
                    xb = nodeXor[b];
                    xa = nodeXor[a] ^ nodeXor[b];
                    xc = xc ^ nodeXor[a];
                }
                // a is b's child
                else if (isChild[b][a]) {
                    xa = nodeXor[a];
                    xb = nodeXor[b] ^ nodeXor[a];
                    xc = xc ^ nodeXor[b];
                }
                else {
                    xa = nodeXor[a];
                    xb = nodeXor[b];
                    xc = xc ^ xa ^ xb;
                }
                res = min(res, max({xa, xb, xc}) - min({xa, xb, xc}));
            }
        }
        return res;
    }
};