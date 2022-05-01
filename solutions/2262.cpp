class Solution {
public:
    long long appealSum(string s) {
        long long res = 0;
        int n = s.size();
        vector<vector<int>> indices(26, vector<int>(1, -1));
        
        // collect index of each alphabet in s
        for (int i = 0; i < n; i++) {
            indices[s[i] - 'a'].push_back(i);
        }
        
        // for each alphabet
        for (int i = 0; i < 26; i++) {
            // if there is no such alphabet in the s, pass
            if (indices[i].size() == 1) continue;
            // for every two indices of that alphabet
            for (int j = 1; j < indices[i].size(); j++) {
                // calculate the combination
                // e.g., abbca => [-1, 0, 4]
                //       01234
                // for [-1, 0] => (0 - (-1)) * (5 - 0) = 5 || a, ab, abb, abbc, abbca
                // for [0, 4] => (4 - 0) * (5 - 4) = 4 || bbca, bca, ca, a
                res += (indices[i][j] - indices[i][j - 1]) * (n - indices[i][j]);
            }
        }
        return res;
    }
};