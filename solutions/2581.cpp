class Solution {
public:
    int dfs(int node, int parent, vector<vector<int>>& adjacency, unordered_map<int, unordered_map<int, int>>& edge2validCnt, unordered_map<int, unordered_set<int>>& validEdge) {
        if (edge2validCnt.find(parent) != edge2validCnt.end() && edge2validCnt[parent].find(node) != edge2validCnt[parent].end()) {
            return edge2validCnt[parent][node];
        }
        int count = 0;
        if (validEdge.find(parent) != validEdge.end() && validEdge[parent].find(node) != validEdge[parent].end()) {
            count++;
        }
        for (auto& neighbor : adjacency[node]) {
            if (neighbor == parent) continue;
            count += dfs(neighbor, node, adjacency, edge2validCnt, validEdge);
        }
        return edge2validCnt[parent][node] = count;
    }
    int rootCount(vector<vector<int>>& edges, vector<vector<int>>& guesses, int k) {
        int n = edges.size() + 1;
        vector<vector<int>> adjacency(n);
        for (auto& edge: edges) {
            adjacency[edge[0]].push_back(edge[1]);
            adjacency[edge[1]].push_back(edge[0]);
        }
        unordered_map<int, unordered_set<int>> validEdge; // parent -> children
        for (auto& guess : guesses) {
            validEdge[guess[0]].insert(guess[1]);
        }
        
        unordered_map<int, unordered_map<int, int>> edge2validCnt;
        int res = 0;
        for (int i = 0; i < n; ++i) {
            int count = dfs(i, -1, adjacency, edge2validCnt, validEdge);
            if (count >= k) res++;
        }
        return res;
        
    }
};