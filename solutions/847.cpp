class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();
        int target = (1 << n) - 1;
        vector<unordered_set<int>> visited(n);
        queue<tuple<int, int, int>> q; //node, mask, path length
        for (int i = 0; i < n; ++i) {
            q.push(make_tuple(i, 1 << i, 0));
            visited[i].insert(1 << i);
        }
        while (!q.empty()) {
            auto [node, state, length] = q.front();
            q.pop();
            if (state == target) return length;
            for (auto& neighbor : graph[node]) {
                int nextState = state | (1 << neighbor);
                if (visited[neighbor].find(nextState) != visited[neighbor].end()) continue;
                q.push(make_tuple(neighbor, nextState, length + 1));
                visited[neighbor].insert(nextState);
                if (nextState == target) return length + 1;
            }
        }
        return -1;
    }
};