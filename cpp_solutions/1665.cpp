class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {
        int n = tasks.size();
        for (int i = 0; i < n; ++i) {
            int diff = tasks[i][1] - tasks[i][0];
            tasks[i][0] = diff;
        }
        sort(tasks.begin(), tasks.end());
        int curr = 0;
        for (int i = 0; i < n; ++i) {
            int diff = tasks[i][0];
            int energy = tasks[i][1] - diff;
            curr = max(curr + energy, tasks[i][1]);
        }
        return curr;
    }
};

