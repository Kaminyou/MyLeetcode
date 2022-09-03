class Solution {
public:
    int maximumRows(vector<vector<int>>& mat, int cols) {
        int m = mat.size();
        int n = mat[0].size();
        
        // for each col, find its covered set
        vector<int> cover(n, -1);
        for (int j = 0; j < n; ++j) {
            int state = 0;
            for (int i = 0; i < m; ++i) {
                if (mat[i][j] == 1) state ^= (1 << i);
            }
            cover[j] = state;
        }
        
        // choose cols
        int res = 0;
        for (int state = 0; state < (1 << n); ++state) {
            if (__builtin_popcount(state) != cols) continue;
            int currentNotCovered = 0;
            int stateTemp = state;
            
            int index = 0;
            while (stateTemp) {
                int chose = stateTemp & 1;
                if (!chose) {
                    currentNotCovered |= cover[index];
                }
                index++;
                stateTemp >>= 1;
            }
            while (index != n) {
                currentNotCovered |= cover[index];
                index++;
            }
            res = max(res, m - __builtin_popcount(currentNotCovered));
        }
        return res;
    }
};
