class Solution {
public:
    vector<vector<int>> substringXorQueries(string s, vector<vector<int>>& queries) {
        int n = queries.size();
        vector<vector<int>> res;
        unordered_map<long long, pair<int, int>> mp;
        // precompute
        for (int i = 0; i < s.size(); ++i) {
            long long cum = 0;
            for (int j = 0; j < 34; ++j) {
                if (i + j >= s.size()) break;
                cum *= 2;
                cum += (s[i + j] - '0');
                if (mp.find(cum) == mp.end()) {
                    mp[cum] = {i, i + j};
                }
                if (cum == 0) break;
            }
        }
        
        for (int i = 0; i < n; ++i) {
            long long value = (long long)queries[i][0] ^ (long long)queries[i][1];
            if (mp.count(value)) {
                auto instance = mp[value];
                res.push_back({instance.first, instance.second});
            }
            else {
                res.push_back({-1, -1});
            }
        }
        return res;
    }
};
