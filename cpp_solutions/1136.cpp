class Solution {
public:
    int minimumSemesters(int n, vector<vector<int>>& relations) {
        vector<vector<int>> edge(n);
        vector<int> inDegree(n, 0);
        for (auto relation : relations) {
            inDegree[relation[1] - 1]++;
            edge[relation[0] - 1].push_back(relation[1] - 1);
        }
        queue<pair<int, int>> q;
        int count = 0;
        for (int i = 0; i < n; ++i) {
            if (!inDegree[i]) {
                q.push(make_pair(i, 1));
                count++;
            }
        }
        
        int res = -1;
        while (!q.empty()) {
            auto [node, level] = q.front();
            res = max(res, level);
            q.pop();
            for (auto neighbor : edge[node]) {
                inDegree[neighbor]--;
                if (!inDegree[neighbor]) {
                    count++;
                    q.push(make_pair(neighbor, level + 1));
                }
            }
        }
        if (count != n) return -1;
        return res;
    }
};