class Solution {
public:
    void bobDfs(int parent, int node, vector<vector<int>>& adjacency, vector<int>& bobPath, vector<int>& currentPath) {
        if (node == 0) {
            bobPath = currentPath;
            return;
        }
        for (auto& neighbor : adjacency[node]) {
            if (neighbor == parent) continue;
            currentPath.push_back(neighbor);
            bobDfs(node, neighbor, adjacency, bobPath, currentPath);
            currentPath.pop_back();
        }
    }
    void aliceDfs(int parent, int node, vector<vector<int>>& adjacency, int& res, int income, vector<int>& nodeTime, int time, vector<int>& amount) {
        if (nodeTime[node] == time) {
            income += amount[node] / 2;
        }
        else if (nodeTime[node] == -1 || nodeTime[node] > time){
            income += amount[node];
        }
        else {
            income += 0;
        }
        
        int cnt = 0;
        for (auto& neighbor : adjacency[node]) {
            if (neighbor == parent) continue;
            aliceDfs(node, neighbor, adjacency, res, income, nodeTime, time + 1, amount);
            cnt++;
        }
        
        // cnt == 0 => leaf
        if (cnt == 0) {
            res = max(res, income);
        }
    }
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int n = edges.size() + 1;
        vector<vector<int>> adjacency(n);
        for (auto& edge : edges) {
            adjacency[edge[0]].push_back(edge[1]);
            adjacency[edge[1]].push_back(edge[0]);
        }

        // bob to root by dfs
        vector<int> bobPath;
        vector<int> currentPath;
        currentPath.push_back(bob);
        bobDfs(-1, bob, adjacency, bobPath, currentPath);

        // get time
        int m = bobPath.size();
        vector<int> nodeTime(n, -1);
        for (int i = 0; i < m; ++i) {
            nodeTime[bobPath[i]] = i;
        }

        // alice
        int res = INT_MIN;
        aliceDfs(-1, 0, adjacency, res, 0, nodeTime, 0, amount);
        return res;
    }
};