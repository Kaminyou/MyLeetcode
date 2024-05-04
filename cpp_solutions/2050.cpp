class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<int> inDegrees(n, 0);
        vector<vector<int>> graph(n);
        for (auto& relation : relations) {
            inDegrees[relation[1] - 1]++;
            graph[relation[0] - 1].push_back(relation[1] - 1);
        }

        vector<int> preTime(n, -1);
        int maxTime = 0;
        queue<int> q;
        for (int i = 0; i < n; ++i) {
            if (inDegrees[i] == 0) {
                q.push(i);
                preTime[i] = time[i];
                maxTime = max(maxTime, time[i]);
            }
        }

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            for (auto& child : graph[node]) {
                inDegrees[child]--;
                preTime[child] = max(preTime[child], preTime[node] + time[child]);
                maxTime = max(maxTime, preTime[child]);
                if (inDegrees[child] == 0) {
                    q.push(child);
                }
            }
        }
        return maxTime;
    }
};