class Solution {
public:
    vector<vector<int>> res;
    void dfs(vector<vector<int>>& graph, vector<int>& low, vector<int>& time, int curr, int prev, int currTime) {
        low[curr] = time[curr] = currTime;
        for (auto neighbor : graph[curr]) {
            if (time[neighbor] == 0) {
                dfs(graph, low, time, neighbor, curr, currTime + 1);
                low[curr] = min(low[curr], low[neighbor]);
            }
            else if (neighbor != prev) {
                low[curr] = min(low[curr], low[neighbor]);
            }
            if (low[neighbor] > currTime) {
                res.push_back({curr, neighbor});
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> graph(n);
        vector<int> low(n, 0);
        vector<int> time(n, 0);
        
        for (auto connection : connections) {
            graph[connection[0]].push_back(connection[1]);
            graph[connection[1]].push_back(connection[0]);
        }
        
        dfs(graph, low, time, 0, -1, 1);
        return res;
    }
};