class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<pair<int, int>> v;
        int n = score.size();
        for (int i = 0; i < n; ++i) {
            v.push_back(make_pair(score[i], i));
        }
        sort(v.begin(), v.end(), greater<pair<int, int>>());
        
        vector<string> res(n, "");
        for (int i = 0; i < n; ++i) {
            int index = v[i].second;
            if (i == 0) res[index] = "Gold Medal";
            else if (i == 1) res[index] = "Silver Medal";
            else if (i == 2) res[index] = "Bronze Medal";
            else res[index] = to_string(i + 1);
        }
        return res;
    }
};