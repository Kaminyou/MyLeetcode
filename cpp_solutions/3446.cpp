class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                int key = j - i;
                mp[key].push_back(grid[i][j]);
            }
        }
        int m = mp.size();
        unordered_map<int, int> k2i;
        for (auto& [k, v] : mp) {
            sort(v.begin(), v.end());
            if (k <= 0) reverse(v.begin(), v.end());
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                int key = j - i;
                grid[i][j] = mp[key][k2i[key]];
                k2i[key]++;
            }
        }
        return grid;
    }
};
