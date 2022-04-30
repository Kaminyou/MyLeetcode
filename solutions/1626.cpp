class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        vector<pair<int, int>> v;
        for (int i = 0; i < scores.size(); i++) {
            v.push_back(make_pair(ages[i], scores[i]));
        }
        sort(v.begin(), v.end());
        
        int res = 0;
        // dp[i]: the max score could be got consider player i and others
        vector<int> dp(v.size(), 0);
        for (int i = 0; i < v.size(); i++) {
            int temp = 0;
            for (int j = 0; j < i; j++) {
                // if the current player i's score >= j'score
                // get the max among such j
                if (v[i].second >= v[j].second) temp = max(temp, dp[j]);
            }
            dp[i] = v[i].second + temp;
            res = max(res, dp[i]);
        }
        return res;
    }
};