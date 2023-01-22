class Solution {
public:
    vector<vector<int>> sortTheStudents(vector<vector<int>>& score, int k) {
        int m = score.size();
        int n = score[0].size();
        vector<pair<int, int>> values;
        for (int i = 0; i < m; ++i) {
            values.push_back({score[i][k], i});
        }
        sort(values.begin(), values.end(), greater<pair<int, int>>());
        vector<vector<int>> res;
        for (int i = 0; i < m; ++i) {
            res.push_back(score[values[i].second]);
        }
        return res;
    }
};