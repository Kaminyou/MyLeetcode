class Solution {
public:
    int maximumCostSubstring(string s, string chars, vector<int>& vals) {
        vector<int> mapping(26, 0);
        for (int i = 0; i < 26; ++i) mapping[i] = i + 1;
        int n = chars.size();
        for (int i = 0; i < n; ++i) {
            mapping[chars[i] - 'a'] = vals[i];
        }
        
        int res = 0;
        int cum = 0;
        for (auto& c : s) {
            cum = max({mapping[c - 'a'], mapping[c - 'a'] + cum, 0});
            res = max(res, cum);
        }
        return res;
    }
};