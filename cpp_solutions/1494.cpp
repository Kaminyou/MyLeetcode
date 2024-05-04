class Solution {
public:
    int minNumberOfSemesters(int n, vector<vector<int>>& relations, int k) {
        
        vector<int> coursePrerequisites(n, 0);
        vector<int> statePrerequisites(1 << n, 0);
        for (auto& relation : relations) {
            coursePrerequisites[relation[1] - 1] |= 1 << (relation[0] - 1);
        }
        
        for (int state = 0; state < (1 << n); ++state) {
            for (int course = 0; course < n; ++course) {
                if ((state >> course) & 1) statePrerequisites[state] |= coursePrerequisites[course];
            }
        }

        vector<int> dp(1 << n, INT_MAX / 2);
        dp[0] = 0;
        for (int state = 1; state < (1 << n); ++state) {
            // prestate is state's subset
            for (int prestate = state; prestate >= 0; prestate = ((prestate - 1) & state)) {
                // check the # of added course
                // check if all prerequisite of "state" is curr in "prestate"
                if ((__builtin_popcount(state) - __builtin_popcount(prestate) <= k) &&
                   ((statePrerequisites[state] & prestate) == statePrerequisites[state])) {
                    dp[state] = min(dp[state], dp[prestate] + 1);
                }
                if (prestate == 0) break;
            }
        }
        return dp[(1 << n) - 1];
    }
};