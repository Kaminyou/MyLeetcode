class Solution {
public:
    int smallestCommonElement(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        int res = INT_MAX;
        unordered_map<int, int> mp;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                mp[mat[i][j]]++;
                if (mp[mat[i][j]] == m) {
                    res = min(res, mat[i][j]);
                }
            }
        }
        return res == INT_MAX ? -1 : res;
    }
};