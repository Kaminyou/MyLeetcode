class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<int> res(n, INT_MAX);
        
        vector<vector<int>> redAdjacency(n);
        vector<vector<int>> blueAdjacency(n);
        
        for (auto& edge : redEdges) {
            redAdjacency[edge[0]].push_back(edge[1]);
        }
        
        for (auto& edge : blueEdges) {
            blueAdjacency[edge[0]].push_back(edge[1]);
        }
        
        vector<vector<bool>> visited(n, vector<bool>(2, false));
        // node, color (0: prev=red; 1: prev=blue)
        queue<pair<int, int>> q;
        q.push(make_pair(0, 0));
        q.push(make_pair(0, 1));
        visited[0][0] = true;
        visited[0][1] = true;
        
        int distance = 0;
        while (!q.empty()) {
            int n = q.size();
            for (int i = 0; i < n; ++i) {
                auto [node, color] = q.front();
                q.pop();
                res[node] = min(res[node], distance);
                
                // prev blue
                if (color == 1) {
                    for (auto& neighbor : redAdjacency[node]) {
                        if (visited[neighbor][1]) continue;
                        q.push(make_pair(neighbor, 0));
                        visited[neighbor][1] = true;
                    }
                }
                else {
                    for (auto& neighbor : blueAdjacency[node]) {
                        if (visited[neighbor][0]) continue;
                        q.push(make_pair(neighbor, 1));
                        visited[neighbor][0] = true;
                    }
                }
            }
            
            distance++;
        }
        for (int i = 0; i < n; ++i) {
            if (res[i] == INT_MAX) res[i] = -1;
        }
        
        return res;
    }
};