class Solution {
public:
    int dfs(int parent, int node, vector<vector<int>>& adjacency, long long& res, int seats) {
        int sum = 0;
        for (auto& neighbor : adjacency[node]) {
            if (neighbor == parent) continue;
            sum += dfs(node, neighbor, adjacency, res, seats);
        }
        if (node != 0) res += sum / seats + 1;
        return sum + 1;
    }
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        int n = roads.size() + 1;
        vector<vector<int>> adjacency(n);
        for (auto& road : roads) {
            adjacency[road[0]].push_back(road[1]);
            adjacency[road[1]].push_back(road[0]);
        }
        long long res = 0;
        dfs(-1, 0, adjacency, res, seats);
        return res;
    }
};