class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.size();
        vector<vector<int>> adjacency(n);
        vector<int> inDegrees(n, 0);
        for (auto& edge : edges) {
            inDegrees[edge[1]]++;
            adjacency[edge[0]].push_back(edge[1]);
        }
        vector<vector<int>> dp(n, vector<int>(26, 0));
        queue<int> q;
        for (int i = 0; i < n; ++i) {
            if (inDegrees[i] == 0) {
                q.push(i);
                dp[i][colors[i] - 'a']++;
            }
        }

        int visited = 0;
        int res = 0;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            visited++;
            for (int i = 0; i < 26; ++i) {
                res = max(res, dp[node][i]);
            }
            for (auto& neighbor : adjacency[node]) {
                for (int i = 0; i < 26; ++i) {
                    if (colors[neighbor] - 'a' == i) {
                        dp[neighbor][i] = max(dp[neighbor][i], dp[node][i] + 1);
                    }
                    else dp[neighbor][i] = max(dp[neighbor][i], dp[node][i]);
                }

                inDegrees[neighbor]--;
                if (inDegrees[neighbor] == 0) q.push(neighbor);
            }
        }
        if (visited != n) return -1;
        return res;
    }
};