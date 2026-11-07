class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        // min q
        priority_queue<vector<long long>, vector<vector<long long>>, greater<vector<long long>>> pq;
        priority_queue<vector<long long>, vector<vector<long long>>, greater<vector<long long>>> wait;
        int n = servers.size();
        for (int i = 0; i < n; ++i) {
            pq.push({servers[i], i});
        }
        int m = tasks.size();
        vector<int> res(m, -1);
        long long t = 0;
        for (int i = 0; i < m; ++i) {
            if (!pq.empty()) {
                t = max(t, (long long)i);
            }
            else {
                vector<long long> v = wait.top();
                t = max(t, v[0]);
            }
            while (!wait.empty() && wait.top()[0] <= t) {
                vector<long long> v = wait.top();
                wait.pop();
                pq.push({v[1], v[2]});
            }
            vector<long long> v = pq.top();
            pq.pop();
            res[i] = v[1];
            wait.push({t + tasks[i], v[0], v[1]});

        }
        return res;
    }
};
