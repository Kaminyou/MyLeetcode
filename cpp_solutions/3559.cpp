const int MAXN = 1e5 + 6;
const int LOGN = 17;
class Solution {
public:
    vector<pair<int, int>> adj[MAXN];
    int up[MAXN][LOGN + 1];
    int depth[MAXN];
    int distRoot[MAXN];
    void dfs(int curr, int parent) {
        up[curr][0] = parent;
        for (auto& [v, w] : adj[curr]) {
            if (v != parent) {
                depth[v] = depth[curr] + 1;
                distRoot[v] = distRoot[curr] + w;
                dfs(v, curr);
            }
        }
    }
    int lca(int a, int b) {
        if (depth[a] < depth[b]) swap(a, b);
        int diff = depth[a] - depth[b];
        for (int k = 0; k <= LOGN; ++k) {
            if (diff & (1 << k)) {
                a = up[a][k];
            }
        }
        if (a == b) return a;
        for (int k = LOGN; k >= 0; --k) {
            if (up[a][k] != up[b][k]) {
                a = up[a][k];
                b = up[b][k];
            }
        }
        return up[a][0];
    }
    int dist(int a, int b) {
        int c = lca(a, b);
        return distRoot[a] + distRoot[b] - 2 * distRoot[c];
    }
    vector<int> assignEdgeWeights(vector<vector<int>>& edges, vector<vector<int>>& queries) {
        int n = edges.size() + 1;
        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int w = 1;
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
        depth[1] = 0;
        distRoot[1] = 0;
        dfs(1, 1);
        for (int k = 1; k <= LOGN; ++k) {
            for (int i = 1; i <= n; ++i) {
                up[i][k] = up[up[i][k - 1]][k - 1];
            }
        }
        vector<int> power(1e5 + 1, 0);
        int mod = 1e9 + 7;
        power[0] = 1;
        for (int i = 1; i <= 1e5; ++i) {
            power[i] = power[i - 1] * 2;
            power[i] %= mod;
        }
        vector<int> res;
        for (auto& query : queries) {
            int d = dist(query[0], query[1]);
            if (d == 0) res.push_back(0);
            else res.push_back(power[d - 1]);
        }
        return res;
    }
};
