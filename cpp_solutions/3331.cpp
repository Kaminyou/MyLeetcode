class Solution {
public:
    void dfsModify(vector<vector<int>>& graph, vector<int>& char2parent, vector<int>& parent, int node, string& s) {
        int ancestor = char2parent[s[node] - 'a'];
        if (ancestor != -1) {
            parent[node] = ancestor;
        }
        char2parent[s[node] - 'a'] = node;
        for (auto& child : graph[node]) {
            dfsModify(graph, char2parent, parent, child, s);
        }
        char2parent[s[node] - 'a'] = ancestor;
    }
    int dfsCount(vector<vector<int>>& graph, int node, vector<int>& res) {
        int cnt = 1;
        for (auto& child : graph[node]) {
            cnt += dfsCount(graph, child, res);
        }
        res[node] = cnt;
        return cnt;
    }
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = parent.size();
        vector<vector<int>> graph(n);
        for (int i = 0; i < n; ++i) {
            if (parent[i] == -1) continue;
            graph[parent[i]].push_back(i);
        }
        vector<int> char2parent(26, -1);
        dfsModify(graph, char2parent, parent, 0, s);
        
        vector<vector<int>> graph2(n);
        for (int i = 0; i < n; ++i) {
            if (parent[i] == -1) continue;
            graph2[parent[i]].push_back(i);
        }
        vector<int> res(n, 0);
        dfsCount(graph2, 0, res);
        return res;
    }
};
