class Solution {
public:
    int dfs(vector<vector<int>>& graph, int prev, int curr, int& res) {
        int cnt = 1;
        unordered_set<int> st;
        for (auto& neighbor : graph[curr]) {
            if (neighbor == prev) continue;
            int sub = dfs(graph, curr, neighbor, res);
            st.insert(sub);
            cnt += sub;
        }
        if (st.size() <= 1) res++;
        return cnt;
    }
    int countGoodNodes(vector<vector<int>>& edges) {
        int n = edges.size() + 1;
        vector<vector<int>> graph(n);
        for (auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        int res = 0;
        dfs(graph, -1, 0, res);
        return res;
    }
};
