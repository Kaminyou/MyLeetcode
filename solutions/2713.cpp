typedef pair<int, pair<int, int>> P;
class Solution {
public:
    int maxIncreasingCells(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<P> nums;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                nums.push_back({mat[i][j], {i, j}});
            }
        }
        sort(nums.begin(), nums.end());
        
        vector<map<int, int>> rows(m);
        vector<map<int, int>> cols(n);
        for (int i = 0; i < m; ++i) rows[i][INT_MIN] = 0;
        for (int i = 0; i < n; ++i) cols[i][INT_MIN] = 0;
        
        int res = 0;
        for (auto& [num, pos] : nums) {
            int length = 1;
            auto [x, y] = pos;
            
            auto iter = rows[x].lower_bound(num);
            iter--;
            length = max(length, 1 + iter->second);
            
            iter = cols[y].lower_bound(num);
            iter--;
            length = max(length, 1 + iter->second);
            
            res = max(res, length);
            
            rows[x][num] = max(length, rows[x][num]);
            cols[y][num] = max(length, cols[y][num]);
        }
        return res;
    }
};