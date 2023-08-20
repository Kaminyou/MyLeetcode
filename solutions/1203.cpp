class Solution {
public:
    vector<int> topologicalSort(unordered_set<int>& nodes, unordered_map<int, unordered_set<int>>& graph, unordered_map<int, int>& inDegrees) {
        vector<int> res;
        queue<int> q;
        for (auto& node : nodes) {
            if (inDegrees[node] == 0) q.push(node);
        }
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            res.push_back(node);
            for (auto& neighbor : graph[node]) {
                inDegrees[neighbor]--;
                if (inDegrees[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }
        if (res.size() == nodes.size()) return res;
        return {};
    }
    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
        int currentGoupId = m;
        unordered_map<int, unordered_set<int>> group2nodes;
        for (int i = 0; i < n; ++i) {
            if (group[i] == -1) {
                group[i] = currentGoupId;
                currentGoupId++;
            }
            group2nodes[group[i]].insert(i);
        }

        unordered_map<int, unordered_set<int>> graph;
        unordered_map<int, int> inDegrees;
        for (int i = 0; i < n; ++i) {
            for (auto neighbor : beforeItems[i]) {
                if (group[i] != group[neighbor]) continue;
                graph[neighbor].insert(i);
                inDegrees[i]++;
            }
        }

        unordered_map<int, vector<int>> group2orderedNodes;
        for (auto [groupID, groupNodes] : group2nodes) {
            group2orderedNodes[groupID] = topologicalSort(groupNodes, graph, inDegrees);
        }

        graph.clear();
        inDegrees.clear();
        unordered_set<int> groupIDs;
        for (int i = 0; i < n; ++i) {
            groupIDs.insert(group[i]);
            for (auto neighbor : beforeItems[i]) {
                if (group[i] == group[neighbor]) continue;
                if (graph[group[neighbor]].count(group[i])) continue;
                graph[group[neighbor]].insert(group[i]);
                inDegrees[group[i]]++;
            }
        }
        vector<int> orderedGroups = topologicalSort(groupIDs, graph, inDegrees);

        vector<int> res;
        for (auto& groupID : orderedGroups) {
            for (auto& node : group2orderedNodes[groupID]) {
                res.push_back(node);
            }
        }
        if (res.size() != n) return {};
        return res;
    }
};
