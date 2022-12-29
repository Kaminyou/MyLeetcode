typedef pair<int ,int> P;
class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        priority_queue<P, vector<P>, greater<P>> pq;

        int n = tasks.size();
        vector<int> res;
        vector<vector<int>> taskWithId(n, {0, 0, 0});
        for (int i = 0; i < n; ++i) {
            taskWithId[i][0] = tasks[i][0];
            taskWithId[i][1] = tasks[i][1];
            taskWithId[i][2] = i;
        }
        sort(taskWithId.begin(), taskWithId.end());
        int index = 0;
        long long currentTime = taskWithId[index][0];
        while (index < n && taskWithId[index][0] <= currentTime) {
            pq.push({taskWithId[index][1], taskWithId[index][2]});
            index++;
        }

        while (!pq.empty()) {
            auto [duration, taskId] = pq.top();
            res.push_back(taskId);
            pq.pop();
            currentTime += duration;
            while (index < n && taskWithId[index][0] <= currentTime) {
                pq.push({taskWithId[index][1], taskWithId[index][2]});
                index++;
            }
            if (pq.empty() && index < n) {
                currentTime = taskWithId[index][0];
                pq.push({taskWithId[index][1], taskWithId[index][2]});
                index++;
            }
        }
        return res;
    }
};