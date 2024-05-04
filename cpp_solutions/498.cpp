class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<int> out;
        int sum = m + n; // [0 ... m + n]
        for (int i = 0; i < sum; ++i) {
            // up to down
            if (i & 1) {
                // y = i - x >= 0 ==> i >= x
                // y = i - x < n ==> x > i - n ==> x >= i - n + 1
                // but min x = 0 and max x = m - 1
                for (int x = max(0, i - n + 1); x <= min(i, m - 1); ++x) {
                    int y = i - x;
                    if (y >= 0 && y < n) out.push_back(mat[x][y]);
                }
            }
            // down to up
            else {
                for (int x = min(i, m - 1); x >= max(0, i - n + 1); --x) {
                    int y = i - x;
                    if (y >= 0 && y < n) out.push_back(mat[x][y]);
                }
            }
        }
        return out;
    }
    
};