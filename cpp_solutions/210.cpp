class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<int> inDegrees(numCourses, 0);
        for (auto& prerequisite : prerequisites) {
            inDegrees[prerequisite[0]]++;
            graph[prerequisite[1]].push_back(prerequisite[0]);
        }
        queue<int> q;
        for (int i = 0; i < numCourses; ++i) {
            if (inDegrees[i] == 0) q.push(i);
        }
        vector<int> res;
        while (!q.empty()) {
            int node = q.front();
            res.push_back(node);
            q.pop();
            for (auto& neighbor : graph[node]) {
                inDegrees[neighbor]--;
                if (inDegrees[neighbor] == 0) q.push(neighbor);
            }
        }
        if (res.size() != numCourses) return {};
        return res;
    }
};