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

class Solution {
public:
    int dp(int index, vector<vector<int>>& jobs, vector<int>& start, vector<int>& memo) {
        if (index == jobs.size()) return 0;
        if (memo[index] != -1) return memo[index];
        auto it = lower_bound(start.begin() + index, start.end(), jobs[index][1]);
        int nextIdx = it - start.begin();
        return memo[index] = max(dp(index + 1, jobs, start, memo), dp(nextIdx, jobs, start, memo) + jobs[index][2]);;
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        vector<vector<int>> jobs(n, vector<int>(3, 0));
        for (int i = 0; i < n; ++i) {
            jobs[i][0] = startTime[i];
            jobs[i][1] = endTime[i];
            jobs[i][2] = profit[i];
        }
        
        sort(jobs.begin(), jobs.end());
        vector<int> memo(n, -1);
        vector<int> start(n, 0);
        for (int i = 0; i < n; ++i) start[i] = jobs[i][0];
        return dp(0, jobs, start, memo);
    }
};