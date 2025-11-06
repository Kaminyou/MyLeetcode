class Solution {
public:
    unordered_map<int, int> station2group;
    unordered_map<int, set<int>> group2stations;
    void dfs(int node, vector<bool>& visited, vector<vector<int>>& graph, int groupID) {
        visited[node] = true;
        station2group[node] = groupID;
        group2stations[groupID].insert(node);
        for (auto& neighbor : graph[node]) {
            if (visited[neighbor]) continue;
            dfs(neighbor, visited, graph, groupID);
        }
    }
    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        vector<bool> visited(c + 1, false);
        vector<vector<int>> graph(c + 1);
        for (auto& connection : connections) {
            graph[connection[0]].push_back(connection[1]);
            graph[connection[1]].push_back(connection[0]);
        }
        
        int groupID = 0;
        for (int i = 1; i <= c; ++i) {
            if (!visited[i]) {
                dfs(i, visited, graph, groupID);
                groupID++;
            }
        }

        vector<int> res;
        for (auto& query : queries) {
            int queryType = query[0];
            int node = query[1];
            int groupID = station2group[node];
            if (queryType == 1) {
                if (group2stations[groupID].count(node)) {
                    res.push_back(node);
                }
                else {
                    if (group2stations[groupID].size() == 0) {
                        res.push_back(-1);
                    }
                    else {
                        int smallest = *group2stations[groupID].begin();
                        res.push_back(smallest);
                    }
                }
            }
            else {
                group2stations[groupID].erase(node);
            }
        }
        return res;
    }
};
