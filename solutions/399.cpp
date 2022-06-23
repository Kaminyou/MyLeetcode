class Solution {
public:
    unordered_set<string> nodes;
    unordered_map<string, vector<pair<string, double>>> graph;
    
    double bfs(string from, string to) {
        unordered_set<string> visited;
        queue<pair<string, double>> q;
        q.push(make_pair(from, 1));
        visited.insert(from);
        while (!q.empty()) {
            auto [node, value] = q.front();
            q.pop();
            if (node == to) return value;
            for (auto neighbor : graph[node]) {
                if (visited.find(neighbor.first) == visited.end()) {
                    visited.insert(neighbor.first);
                    q.push(make_pair(neighbor.first, neighbor.second * value));
                }
            }
        }
        return -1.0;
    }
    
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int n = equations.size();
        for (int i = 0; i < n; i++) {
            nodes.insert(equations[i][0]);
            nodes.insert(equations[i][1]);
            graph[equations[i][0]].push_back(make_pair(equations[i][1], values[i]));
            graph[equations[i][1]].push_back(make_pair(equations[i][0], 1 / values[i]));
        }
        
        vector<double> res;
        for (auto query : queries) {
            if (nodes.find(query[0]) == nodes.end() || nodes.find(query[1]) == nodes.end()) {
                res.push_back(-1.0);
                continue;
            }
            else if (query[0] == query[1]) {
                res.push_back(1.0);
                continue;
            }
            res.push_back(bfs(query[0], query[1]));
        }
        return res;
    }
};

// DFS version
// class Solution {
// public:
//     void dfs(string from, string to, double curr, unordered_map<string, vector<pair<string, double>>>& mp, unordered_set<string>& visited, double& ans) {
//         visited.insert(from);
//         if (mp.find(from) == mp.end()) return;
//         if (mp.find(to) == mp.end()) return;
//         if (from == to) {
//             ans = curr;
//         }
//         for (auto [neighbor, value] : mp[from]) {
//             if (neighbor == to) {
//                 ans = value * curr;
//                 return;
//             }
//             if (visited.find(neighbor) == visited.end()) dfs(neighbor, to, curr * value, mp, visited, ans);
//         }
//         return;
//     }
//     vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
//         unordered_map<string, vector<pair<string, double>>> mp;
//         int n = equations.size();
//         for (int i = 0; i < n; ++i) {
//             mp[equations[i][0]].push_back(make_pair(equations[i][1], values[i]));
//             mp[equations[i][1]].push_back(make_pair(equations[i][0], 1 / values[i]));
//         }
//         vector<double> res;
//         for (auto& query : queries) {
//             string from = query[0];
//             string to = query[1];
//             unordered_set<string> visited;
//             double ans = -1.0;
//             dfs(from, to, 1.0, mp, visited, ans);
//             res.push_back(ans);
//         }
//         return res;
//     }
// };