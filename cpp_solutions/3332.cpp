class Solution {
public:
    int maxScore(int n, int k, vector<vector<int>>& stayScore, vector<vector<int>>& travelScore) {
        vector<int> maxScores(n, 0);
        vector<int> maxScoresTemp(n, 0);
        for (int i = 0; i < k; ++i) {
            // stay
            for (int current = 0; current < n; ++current) {
                maxScoresTemp[current] = max(maxScoresTemp[current], maxScores[current] + stayScore[i][current]);
            }
            // move
            for (int current = 0; current < n; ++current) {
                for (int next = 0; next < n; ++next) {
                    if (current == next) continue;
                    maxScoresTemp[next] = max(maxScoresTemp[next], maxScores[current] + travelScore[current][next]);
                }
            }
            // update
            for (int current = 0; current < n; ++current) {
                maxScores[current] = maxScoresTemp[current];
            }
        }
        int res = 0;
        for (int current = 0; current < n; ++current) {
            res = max(res, maxScores[current]);
        }
        return res;
    }
};
