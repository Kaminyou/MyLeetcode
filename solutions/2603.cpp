class Solution {
public:
    void removeEdge(vector<int>& v, int p) {
        for (int i = 0; i < v.size(); ++i) {
            if (v[i] == p) {
                v.erase(v.begin() + i);
                return;
            }
        }
    }
    int collectTheCoins(vector<int>& coins, vector<vector<int>>& edges) {
        int sum = accumulate(coins.begin(), coins.end(), 0);
        if (sum <= 1) return 0;
        
        int n = coins.size();
        int ans = edges.size();
        vector<vector<int>> adjacency(n);
        for (auto& edge : edges) {
            adjacency[edge[0]].push_back(edge[1]);
            adjacency[edge[1]].push_back(edge[0]);
        }
        
        vector<int> leaves;
        for (int i = 0; i < n; ++i) {
            if (adjacency[i].size() == 1) leaves.push_back(i);
        }
        
        vector<int> leavesWithCoin;
        for (auto leaf : leaves) {
            if (coins[leaf] > 0) {
                leavesWithCoin.push_back(leaf);
                continue;
            }
            while (coins[leaf] == 0 && adjacency[leaf].size() == 1) {
                int parent = adjacency[leaf][0];
                removeEdge(adjacency[leaf], parent);
                removeEdge(adjacency[parent], leaf);
                ans -= 1;
                leaf = parent;
            }
            if (adjacency[leaf].size() == 1) {
                leavesWithCoin.push_back(leaf);
            }
        }
        
        int finalLeaves = 0;
        for (auto leaf : leavesWithCoin) {
            int parent = adjacency[leaf][0];
            removeEdge(adjacency[leaf], parent);
            removeEdge(adjacency[parent], leaf);
            ans -= 1;
            if (adjacency[parent].size() == 1) finalLeaves++;
        }
        ans -= finalLeaves;
        ans *= 2;
        return max(0, ans);
    }
};