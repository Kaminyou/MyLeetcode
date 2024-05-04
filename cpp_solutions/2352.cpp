class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n = grid.size();
        // hash cols
        unordered_map<string, int> hashing;
        for (int j = 0; j < n; ++j) {
            string encode = "";
            for (int i = 0; i < n; ++i) {
                encode += to_string(grid[i][j]) + "#";
            }
            hashing[encode]++;
        }
        
        int res = 0;
        for (int i = 0; i < n; ++i) {
            string encode = "";
            for (int j = 0; j < n; ++j) {
                encode += to_string(grid[i][j]) + "#";
            }
            res += hashing[encode];
        }
        return res;
    }
};