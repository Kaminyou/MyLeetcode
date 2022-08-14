class Solution {
public:
    bool isRowSame(vector<vector<char>>& picture, int i, int j, int n) {
        for (int k = 0; k < n; ++k) {
            if (picture[i][k] != picture[j][k]) return false;
        }
        return true;
    }
    int findBlackPixel(vector<vector<char>>& picture, int target) {
        int m = picture.size();
        int n = picture[0].size();
        
        vector<int> same(m, 0);
        for (int i = 0; i < m; ++i) {
            for (int j = i + 1; j < m; ++j) {
                if (isRowSame(picture, i, j, n)) {
                    same[i]++;
                    same[j]++;
                }
            }
        }
        
        vector<int> rows(m, 0);
        vector<int> cols(n, 0);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (picture[i][j] == 'B') {
                    rows[i]++;
                    cols[j]++;
                }
            }
        }
        
        int cnt = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (picture[i][j] == 'B') {
                    if (rows[i] == cols[j] && rows[i] == target && same[i] + 1 == target) cnt++;
                }
            }
        }
        return cnt;
    }
};