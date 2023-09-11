class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        unordered_map<int, vector<int>> mp;
        int n = groupSizes.size();
        for (int i = 0; i < n; ++i) {
            mp[groupSizes[i]].push_back(i);
        }
        vector<vector<int>> res;
        for (auto [k, v] : mp) {
            int m = v.size();
            int t = m / k;
            for (int i = 0; i < t; ++i) {
                vector<int> temp;
                for (int j = 0; j < k; ++j) {
                    temp.push_back(v[i * k + j]);
                }
                res.push_back(temp);
            }
        }
        return res;
    }
};
