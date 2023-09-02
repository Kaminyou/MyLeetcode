class Solution {
public:
    vector<int> goodSubsetofBinaryMatrix(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        unordered_map<int, vector<int>> hash;
        for (int i = 0; i < m; ++i) {
            int state = 0;
            for (int j = 0; j < n; ++j) {
                if (grid[i][j]) state += (1 << j);
            }
            if (state == 0) return {i};
            hash[state].push_back(i);
        }

        for (int i = 0; i < m; ++i) {
            int state = 0;
            for (int j = 0; j < n; ++j) {
                if (grid[i][j]) state += (1 << j);
            }
            
            for (int complement = 0; complement < (1 << n); ++ complement) {
                if (complement & state) continue;
                for (int index : hash[complement]) {
                    if (index != i) {
                        vector<int> res = {i, index};
                        sort(res.begin(), res.end());
                        return res;
                    }
                }
            }
        }
        return {};
    }
};
