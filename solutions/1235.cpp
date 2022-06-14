class Solution {
public:
    vector<int> dp;
    vector<vector<int>> jobs;
    int N;
    static bool compare(const vector<int>& v1, const vector<int>& v2) {
        return v1[0] < v2[0];
    }
    int recursive(vector<int>& start, int curr) {
        if (curr == N) return 0;
        if (dp[curr] != -1) return dp[curr];
        // find the next => next start >= curr end
        auto it = lower_bound(start.begin() + curr, start.end(), jobs[curr][1]);
        const int p = it - start.begin();
        // either skip this job, or do this job
        dp[curr] = max(recursive(start, curr + 1), recursive(start, p) + jobs[curr][2]);
        return dp[curr];
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        N = n;
        for (int i = 0; i < n; ++i) {
            vector<int> job(3);
            job[0] = startTime[i];
            job[1] = endTime[i];
            job[2] = profit[i];
            jobs.push_back(job);
        }
        sort(jobs.begin(), jobs.end(), compare);
        vector<int> start(n);
        for (int i = 0; i < n; ++i) start[i] = jobs[i][0];
        dp.resize(n, -1);
        return recursive(start, 0);
    }
};