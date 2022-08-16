class Solution {
public:
    int firstUniqChar(string s) {
        vector<vector<int>> hash(26);
        for (int i = 0; i < s.size(); ++i) {
            hash[s[i] - 'a'].push_back(i);
        }
        int res = INT_MAX;
        for (int i = 0; i < 26; ++i) {
            if (hash[i].size() == 1) res = min(res, hash[i][0]);
        }
        return res == INT_MAX ? -1 : res;
    }
};