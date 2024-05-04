class Solution {
public:
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        int n = req_skills.size();
        int target = (1 << n) - 1;
        unordered_map<string, int> skill2idx;
        vector<int> peopleSkills; 
        for (int i = 0; i < n; ++i) {
            skill2idx[req_skills[i]] = i;
        }
        for (auto& person : people) {
            int mask = 0;
            for (auto& skill : person) {
                mask |= (1 << skill2idx[skill]);
            }
            peopleSkills.push_back(mask);
        }
        vector<int> res;
        vector<int> dp(1<<n, INT_MAX / 2);
        vector<pair<int, int>> dpState(1<<n, {-1, -1});
        dp[0] = 0;
        for (int i = 0; i < (1 << n); ++i) {
            for (int j = 0; j < peopleSkills.size(); ++j) {
                int nextState = (i | peopleSkills[j]);
                if (dp[i] + 1 < dp[nextState]) {
                    dp[nextState] = dp[i] + 1;
                    dpState[nextState] = make_pair(i, j);
                }
            }
        }
        int currState = target;
        while (currState != 0) {
            res.push_back(dpState[currState].second);
            currState = dpState[currState].first;
        }
        return res;
    }
};