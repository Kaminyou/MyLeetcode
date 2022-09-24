class Solution {
public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int n = quiet.size();
        vector<vector<int>> adjacency(n);
        vector<int> inDegrees(n, 0);
        for (auto& p : richer) {
            adjacency[p[0]].push_back(p[1]);
            inDegrees[p[1]]++;
        }
        queue<int> q;
        for (int i = 0; i < n; ++i) {
            if (inDegrees[i] == 0) q.push(i);
        }
        
        vector<int> res(n, -1);
        for (int i = 0; i < n; ++i) res[i] = i;
        
        int level = 0;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            for (auto& neighbor : adjacency[node]) {
                if (quiet[res[neighbor]] > quiet[res[node]]) {
                    res[neighbor] = res[node];
                }
                inDegrees[neighbor]--;
                if (inDegrees[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }
        return res;
    }
};