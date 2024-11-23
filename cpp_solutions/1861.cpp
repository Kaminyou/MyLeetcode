class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int m = box.size();
        int n = box[0].size();
        for (int i = 0; i < m; ++i) {
            int cnt = 0;
            for (int j = 0; j < n; ++j) {
                if (box[i][j] == '#') {
                    box[i][j] = '.';
                    cnt++;
                }
                else if (box[i][j] == '*') {
                    int curr = j - 1;
                    while (cnt > 0) {
                        box[i][curr] = '#';
                        curr--;
                        cnt--;
                    }
                }
            }
            int curr = n - 1;
            while (cnt > 0) {
                box[i][curr] = '#';
                curr--;
                cnt--;
            }
        }
        vector<vector<char>> res(n, vector<char>(m, '.'));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                res[j][i] = box[m - i - 1][j];
            }
        }
        return res;
    }
};
