class Solution {
private:
    vector<vector<int>> jobs;
    vector<int> dp;
public:
    static bool compare(const vector<int>& v1, const vector<int>& v2) {
        return v1[0] < v2[0];
    }
    int recursive(vector<int>& start, int curr, int n) {
        if (curr == n) return 0;
        if (dp[curr] != -1) return dp[curr];
        auto it = lower_bound(start.begin() + curr, start.end(), jobs[curr][1]);
        int p = it - start.begin();
        dp[curr] = max(recursive(start, curr + 1, n), recursive(start, p, n) + jobs[curr][2]);
        return dp[curr];
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        jobs.resize(n, vector<int>(3, 0));
        for (int i = 0; i < n; ++i) {
            jobs[i][0] = startTime[i];
            jobs[i][1] = endTime[i];
            jobs[i][2] = profit[i];
        }
        sort(jobs.begin(), jobs.end(), compare);
        vector<int> start;
        for (int i = 0; i < n; ++i) start.push_back(jobs[i][0]);
        
        dp.resize(n + 1, -1);
        
        return recursive(start, 0, n);
    }
};