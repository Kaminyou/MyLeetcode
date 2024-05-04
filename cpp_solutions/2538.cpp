class Solution {
public:
    long long dfs1(int node, int parent, vector<vector<int>>& adjacency, vector<int>& price, vector<long long>& maxPaths) {
        long long maxPath = price[node];
        for (auto& neighbor : adjacency[node]) {
            if (neighbor == parent) continue;
            maxPath = max(maxPath, price[node] + dfs1(neighbor, node, adjacency, price, maxPaths));
        }
        return maxPaths[node] = maxPath;
    }
    void dfs2(int node, int parent, vector<vector<int>>& adjacency, vector<int>& price, vector<long long>& maxPaths, long long parentContribution, long long& res) {
        int maxChildNode = -1;
        long long maxChildPrice = 0;
        long long secondChildPrice = 0;
        for (auto& neighbor : adjacency[node]) {
            if (neighbor == parent) continue;
            long long childPrice = maxPaths[neighbor];
            if (childPrice > maxChildPrice) {
                secondChildPrice = maxChildPrice;
                maxChildNode = neighbor;
                maxChildPrice = childPrice;
            }
            else if (childPrice > secondChildPrice) {
                secondChildPrice = childPrice;
            }
        }
        res = max({res, maxChildPrice, parentContribution});
        for (auto& neighbor : adjacency[node]) {
            if (neighbor == parent) continue;
            if (neighbor == maxChildNode) {
                dfs2(neighbor, node, adjacency, price, maxPaths, price[node] + max(parentContribution, secondChildPrice), res);
            }
            else {
                dfs2(neighbor, node, adjacency, price, maxPaths, price[node] + max(parentContribution, maxChildPrice), res);
            }
        }
    }
    long long maxOutput(int n, vector<vector<int>>& edges, vector<int>& price) {
        vector<vector<int>> adjacency(n);
        for (auto& edge : edges) {
            adjacency[edge[0]].push_back(edge[1]);
            adjacency[edge[1]].push_back(edge[0]);
        }
        vector<long long> maxPaths(n, 0);
        dfs1(0, -1, adjacency, price, maxPaths);
        long long res = 0;
        dfs2(0, -1, adjacency, price, maxPaths, 0, res);
        return res;
    }
};