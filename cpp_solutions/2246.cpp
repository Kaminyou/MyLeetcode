class Solution {
public:
    int dfs(int node, int parent, vector<vector<int>>& adjacency, string& s, int& res) {
        char current = s[node];
        int maxLength = 0;
        int secondLength = 0;
        for (auto& neighbor : adjacency[node]) {
            if (neighbor == parent) continue;
            int length = dfs(neighbor, node, adjacency, s, res);
            if (s[neighbor] != current) {
                if (length >= maxLength) {
                    secondLength = maxLength;
                    maxLength = length;
                }
                else if (length >= secondLength) {
                    secondLength = length;
                }
            }
        }
        res = max(res, maxLength + secondLength + 1);
        return maxLength + 1;
    }
    int longestPath(vector<int>& parent, string s) {
        int n = parent.size();
        vector<vector<int>> adjacency(n);
        for (int i = 0; i < n; ++i) {
            if (parent[i] == -1) continue;
            adjacency[parent[i]].push_back(i);
        }

        int res = 0;
        dfs(0, -1, adjacency, s, res);
        return res;
    }
};